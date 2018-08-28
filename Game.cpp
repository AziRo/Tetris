#include "Game.h"



Game::Game():tetramino_type(rand() % 7), next_tetramino_type(rand() % 7), lvl(1)
{
	if (tetramino_type == next_tetramino_type) next_tetramino_type = rand() % 7;
	setTetramino(tetramino_type, 0);
	setTetramino(next_tetramino_type, 1);
}

void Game::setTetramino(int tetramino_type, int number)
{
	switch (tetramino_type)
	{
	case 0:
		if (!number) 
		{
			delete tetramino;
			tetramino = new I;
		}
		else 
		{
			delete next_tetramino;
			next_tetramino = new I;
			next_tetramino->move(9, 15);
			status_panel.set_next_tetramino(next_tetramino);
		}
		break;
	case 1:
		if (!number)
		{
			delete tetramino;
			tetramino = new J;
		}
		else
		{
			delete next_tetramino;
			next_tetramino = new J;
			next_tetramino->move(9, 15);
			status_panel.set_next_tetramino(next_tetramino);
		}
		break;
	case 2:
		if (!number)
		{
			delete tetramino;
			tetramino = new L;
		}
		else
		{
			delete next_tetramino;
			next_tetramino = new L;
			next_tetramino->move(9, 15);
			status_panel.set_next_tetramino(next_tetramino);
		}
		break;
	case 3:
		if (!number)
		{
			delete tetramino;
			tetramino = new S;
		}
		else
		{
			delete next_tetramino;
			next_tetramino = new S;
			next_tetramino->move(9, 15);
			status_panel.set_next_tetramino(next_tetramino);
		}
		break;
	case 4:
		if (!number)
		{
			delete tetramino;
			tetramino = new Z;
		}
		else
		{
			delete next_tetramino;
			next_tetramino = new Z;
			next_tetramino->move(9, 15);
			status_panel.set_next_tetramino(next_tetramino);
		}
		break;
	case 5:
		if (!number)
		{
			delete tetramino;
			tetramino = new O;
		}
		else
		{
			delete next_tetramino;
			next_tetramino = new O;
			next_tetramino->move(9, 15);
			status_panel.set_next_tetramino(next_tetramino);
		}
		break;
	case 6:
		if (!number)
		{
			delete tetramino;
			tetramino = new T;
		}
		else
		{
			delete next_tetramino;
			next_tetramino = new T;
			next_tetramino->move(10, 15);
			status_panel.set_next_tetramino(next_tetramino);
		}
		break;
	}
}

void Game::draw(Painter p)
{
	status_panel.drawPanel(p);
	well.draw(p, Game::tetramino);
	tetramino->draw(p);
}

void Game::tick(int tick)
{
	tetramino->move(0, tick);

	if (well.isCollision(tetramino))
	{
		int score;
		int num_lines;
		tetramino->move(0, -tick);
		well.unit(tetramino);
		num_lines = well.removeSolidLines();
		status_panel.count_line(num_lines);
		status_panel.count_score(num_lines * 100 * num_lines);
		score = status_panel.get_score();
		if (score >= lvl * 1000 + (lvl - 1) * lvl * 100 && lvl < 10) 
		{ 
			status_panel.set_level(++lvl);
		}
		tetramino_type = next_tetramino_type;
		setTetramino(tetramino_type, 0);
		next_tetramino_type = rand() % 7;
		if (tetramino_type == next_tetramino_type) next_tetramino_type = rand() % 7;
		setTetramino(next_tetramino_type, 1);
		if (well.isCollision(tetramino))
			restart();
	}
}

void Game::restart()
{
	lvl = 1;
	status_panel.set_level(lvl);
	status_panel.count_line(0, true);
	status_panel.count_score(0, true);

	well = Well();
}

void Game::KeyEvent(Direction d)
{

	switch (d)
	{
	case UP: 
		tetramino->rotate(1);
		if (well.isCollision(tetramino))
			tetramino->rotate(-1);
		break;

	case DOWN: 
		tetramino->move(0, 1);
		if (well.isCollision(tetramino))
			tetramino->move(0, -1);
		break;

	case LEFT: 
		tetramino->move(-1, 0);
		if (well.isCollision(tetramino))
			tetramino->move(1, 0);
		break;

	case RIGHT: 
		tetramino->move(1, 0);
		if (well.isCollision(tetramino))
			tetramino->move(-1, 0);
		break;
	}
		
}

int Game::get_lvl()
{
	return lvl;
}
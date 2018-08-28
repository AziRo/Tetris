#include "Tetramino.h"

Tetramino::Tetramino() : angle(0), position_x(3), position_y(0)
{
	setColor();
}

void Tetramino::draw(Painter & p, int flag) const
{
	if(flag) p.setColor(static_cast<Painter::Color>(color));
	for (int x = 0; x < SHAPE_SIZE; x++) {
		for (int y = 0; y < SHAPE_SIZE; y++) {
			if (map(x, y)) p.rect((x + position_x) * CELL_SIZE + GAP, (y + position_y) * CELL_SIZE + GAP,
								  (x + position_x + 1) * CELL_SIZE - GAP, (y + position_y + 1) * CELL_SIZE - GAP);
		}
	}
}

void Tetramino::move(int dx, int dy)
{
	position_x += dx;
	position_y += dy;
}

void Tetramino::rotate(int pos)
{
	angle = (angle + pos) % 4;
}

int Tetramino::get_x()
{
	return position_x;
}

int Tetramino::get_y()
{
	return position_y;
}

void Tetramino::setColor()
{
	color = rand() % 7;
}

int Tetramino::get_color()
{
	return color;
}

bool I::map(int x, int y) const
{
	static const char *shape[2][4] = {
						{"  1 ",
						 "  1 ", 
						 "  1 ", 
						 "  1 "},
		
						{"1111",
						 "    ", 
						 "    ", 
						 "    "}
					 };

	return shape[angle][y][x] != ' ';
}

void I::rotate(int pos)
{
	angle = (angle + pos) % 2;
}

bool J::map(int x, int y) const
{
	static const char *shape[4][4] = {
						{"  1 ",
						 "  1 ", 
						 " 11 ", 
						 "    "},
		
						{" 111",
						 "   1", 
						 "    ", 
						 "    "},

						{" 11 ",
						 " 1  ", 
						 " 1  ", 
						 "    "},

						{"1   ",
						 "111 ", 
						 "    ", 
						 "    "}
					 };

	return shape[angle][y][x] != ' ';
}

bool L::map(int x, int y) const
{
	static const char *shape[4][4] = {
						{" 1  ",
						 " 1  ", 
						 " 11 ", 
						 "    "},
		
						{"   1",
						 " 111", 
						 "    ", 
						 "    "},

						{" 11 ",
						 "  1 ", 
						 "  1 ", 
						 "    "},

						{" 111",
						 " 1  ", 
						 "    ", 
						 "    "}
					 };

	return shape[angle][y][x] != ' ';
}

bool S::map(int x, int y) const
{
	static const char *shape[2][4] = {
						{"  1 ",
						 " 11 ", 
						 " 1  ", 
						 "    "},
		
						{"11  ",
						 " 11 ", 
						 "    ", 
						 "    "}
					 };

	return shape[angle][y][x] != ' ';
}

void S::rotate(int pos)
{
	angle = (angle + pos) % 2;
}

bool Z::map(int x, int y) const
{
	static const char *shape[2][4] = {
						{" 1  ",
						 " 11 ", 
						 "  1 ", 
						 "    "},
		
						{"  11",
						 " 11 ", 
						 "    ", 
						 "    "}
					 };

	return shape[angle][y][x] != ' ';
}
void Z::rotate(int pos)
{
	angle = (angle + pos) % 2;
}

bool O::map(int x, int y) const
{
	static const char *shape[4] = {
						 " 11 ",
						 " 11 ", 
						 "    ", 
						 "    "
					    };

	return shape[y][x] != ' ';
}

bool T::map(int x, int y) const
{
	static const char *shape[4][4] = {
						{"111 ",
						 " 1  ", 
						 "    ", 
						 "    "},
		
						{" 1  ",
						 " 11 ", 
						 " 1  ", 
						 "    "},

						{"  1 ",
						 " 111", 
						 "    ", 
						 "    "},

						{"  1 ",
						 " 11 ", 
						 "  1 ", 
						 "    "}
					 };

	return shape[angle][y][x] != ' ';
}
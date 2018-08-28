#include "StatusPanel.h"
#include<stdio.h>


StatusPanel::StatusPanel() : score(0), level(1), number_line(0), next_tetramino(NULL)
{
}

void StatusPanel::drawPanel(Painter p)
{
	p.setColor(Painter::WHITE);

	p.frame(WEITH * CELL_SIZE + 1, 1, WINDOW_WEITH - 1, WINDOW_HEIGHT - 1);

	p.printText("Level:", START_X_POSITION - 5, START_Y_POSITION);
	p.frame(START_X_POSITION - 5, START_Y_POSITION + 5, START_X_POSITION + WIDTH_FRAME + 5, START_Y_POSITION + 5 + HEIGHT_FRAME);
	p.printText(toChar(level), START_X_POSITION, START_Y_POSITION + HEIGHT_FRAME);

	p.printText("Lines:", START_X_POSITION - 5, START_Y_POSITION + 5 + HEIGHT_FRAME * 2 + GAP_FRAME);
	p.frame(START_X_POSITION - 5, START_Y_POSITION + 10 + HEIGHT_FRAME * 2 + GAP_FRAME, START_X_POSITION + WIDTH_FRAME + 5, START_Y_POSITION + 10 + HEIGHT_FRAME * 3 + GAP_FRAME);
	p.printText(toChar(number_line), START_X_POSITION, START_Y_POSITION + 5 + HEIGHT_FRAME * 3 + GAP_FRAME);

	p.printText("Score:", START_X_POSITION - 5, START_Y_POSITION + 10 + HEIGHT_FRAME * 4 + GAP_FRAME * 2);
	p.frame(START_X_POSITION - 5, START_Y_POSITION + 15 + HEIGHT_FRAME * 4 + GAP_FRAME * 2, START_X_POSITION + WIDTH_FRAME + 5, START_Y_POSITION + 15 + HEIGHT_FRAME * 5 + GAP_FRAME * 2);
	p.printText(toChar(score), START_X_POSITION, START_Y_POSITION + 10 + HEIGHT_FRAME * 5 + GAP_FRAME * 2);

	p.printText("Next:", START_X_POSITION - 5, START_Y_POSITION + 15 + HEIGHT_FRAME * 6 + GAP_FRAME * 3);
	p.frame(START_X_POSITION - 5, START_Y_POSITION + 20 + HEIGHT_FRAME * 6 + GAP_FRAME * 3, START_X_POSITION + WIDTH_FRAME + 5, START_Y_POSITION + 20 + HEIGHT_FRAME * 9 + 20 + GAP_FRAME * 3);
	next_tetramino->draw(p, 0);
}



void StatusPanel::count_score(int points, bool reset)
{
	if (reset) score = points;
	else score += points;
	
}

void StatusPanel::set_level(int num_level)
{
	level = num_level;
}

void StatusPanel::count_line(int number, bool reset)
{
	if (reset) number_line = number;
	else number_line += number;
}

void StatusPanel::set_next_tetramino(Tetramino * t)
{
	next_tetramino = t;
}

int StatusPanel::get_score()
{
	return score;
}

const char * StatusPanel::toChar(int n)
{

	char *str;
	int count = 0;
	int num = n;
	while (num)
	{
		count++;
		num /= 10;
	}
	if (!count)
	{
		str = new char[2];
		str[0] = 48;
		str[1] = 0;
	}
	else
	{
		int j = count-1;
		str = new char[count + 1];
		str[count] = 0;

		for (int i = 0; i < count; i++)
		{
			str[j--] = n % 10 + 48;
			n /= 10;
		}
	}
	return str;
}
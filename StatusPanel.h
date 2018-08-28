#pragma once

#include "Well.h"
#define START_Y_POSITION 35
#define START_X_POSITION 240

#define WIDTH_FRAME 80
#define HEIGHT_FRAME 25
#define GAP_FRAME 30

#define WINDOW_WEITH 360
#define WINDOW_HEIGHT 400

class StatusPanel
{
public:
	StatusPanel();
	void drawPanel(Painter p);
	void count_score(int points, bool reset = false);
	void set_level(int num_level);
	void count_line(int number, bool reset = false);
	void set_next_tetramino(Tetramino * t);
	int get_score();
	const char* toChar(int n);
private:
	int score;
	int level;
	int number_line;
	Tetramino *next_tetramino;
};


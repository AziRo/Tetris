#pragma once
#include "StatusPanel.h"

class Game
{
	public:
		Game();
		enum Direction { UP, DOWN, LEFT, RIGHT };
		void setTetramino(int tetramino_type, int number);
		void draw(Painter p);
		void tick(int tick);
		void restart();
		void KeyEvent(Direction d);
		int get_lvl();
	private:
		int lvl;
		int tetramino_type;
		int next_tetramino_type;
		Tetramino *tetramino;
		Tetramino *next_tetramino;
		Well well;
		StatusPanel status_panel;
};


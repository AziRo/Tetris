#pragma once

#include <gl\freeglut.h>

#define CELL_SIZE 20
#define GAP 2


class Painter
{
	public:
		enum Color { RED, WHITE, MAGENTA, DARK_BLUE, GREEN, BROWN, CYAN, BLACK };
		void rect(int x1, int y1, int x2, int y2);
		void frame(int x1, int y1, int x2, int y2);
		void printText(const char* text, int x, int y);
		void setColor(Color color);
};


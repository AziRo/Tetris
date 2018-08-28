#pragma once
#include "Tetramino.h"

#define HEIGHT 20
#define WEITH 10

class Well
{
	public:
		Well();
		void draw(Painter p, Tetramino * t) const;
		void unit(Tetramino * t);
		bool isCollision(Tetramino * t) const;
		int removeSolidLines();
	private:
		bool map_well[HEIGHT][WEITH];
};


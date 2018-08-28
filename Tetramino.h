#pragma once

#include "Painter.h"
#include "stdlib.h"

#define SHAPE_SIZE 4

class Tetramino
{
	public:
		Tetramino();
		void draw(Painter & p, int flag = 1) const;
		void move(int dx, int dy);
		virtual void rotate(int pos);
		virtual bool map(int x, int y) const = 0;
		int get_x();
		int get_y();
		void setColor();
		int get_color();
	protected:
		int angle;
		int position_x;
		int position_y;
		int color;
};

class I : public Tetramino 
{
	public:
		bool map(int x, int y) const;
		void rotate(int pos);
};

class J : public Tetramino
{
	public:
		bool map(int x, int y) const;
};

class L : public Tetramino
{
	public:
		bool map(int x, int y) const;
};

class S : public Tetramino
{
	public:
		bool map(int x, int y) const;
		void rotate(int pos);
};

class Z : public Tetramino
{
	public:
		bool map(int x, int y) const;
		void rotate(int pos);
};

class O : public Tetramino
{
	public:
		bool map(int x, int y) const;
};

class T : public Tetramino
{
	public:
		bool map(int x, int y) const;
};
#include "Painter.h"


void Painter::rect(int x1, int y1, int x2, int y2)
{
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}

void Painter::frame(int x1, int y1, int x2, int y2)
{
	glLineWidth(2);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}


void Painter::printText(const char* text, int x, int y)
{
	glBegin(GL_BITMAP);
	glRasterPos2f(x, y);
	while (*text)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text++);
	glEnd();
}

void Painter::setColor(Color color)
{
	struct RGB
	{
		float r, g, b;
	};

	RGB colors[] = {{ 1.0, 0.0, 0.0 }, 
					{ 1.0, 1.0, 1.0 },
					{ 1.0, 0.0, 1.0 }, 
					{ 0.0, 0.0, 0.5 }, 
					{ 0.0, 1.0, 0.0 },
					{ 0.5, 0.5, 0.0 }, 
					{ 0.0, 1.0, 1.0 }, 
					{ 0.0, 0.0, 0.0 }
				   };

	glColor3f(colors[color].r, colors[color].g, colors[color].b);
}
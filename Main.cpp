#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "Game.h"

Game game;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Painter p;
	game.draw(p);
	
	glutSwapBuffers();
}

void timer(int time)
{	
	int lvl = game.get_lvl();
	game.tick(1);
	int next_lvl = game.get_lvl();
	if (next_lvl != lvl && lvl < 10) time -= 100;
	printf("%i", time);
	display();
	glutTimerFunc(time, timer, time);
}

void keyEvent(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		game.KeyEvent(Game::LEFT);
		break;
	case GLUT_KEY_RIGHT:
		game.KeyEvent(Game::RIGHT);
		break;
	case GLUT_KEY_UP:
		game.KeyEvent(Game::UP);
		break;
	case GLUT_KEY_DOWN:
		game.KeyEvent(Game::DOWN);
		break;
	}
	display();
}

int main(int argc, char **argv) {
	mciSendString(L"play .//Тетрис_1.mp3 repeat", NULL, 0, NULL);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WEITH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("Tetris");
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WINDOW_WEITH, WINDOW_HEIGHT, 0, -1.0, 1.0);
	
	glutDisplayFunc(display);
	timer(1000);
	glutSpecialFunc(keyEvent);
	glutMainLoop();
	return 0;
}
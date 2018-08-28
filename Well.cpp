#include "Well.h"

Well::Well()
{
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WEITH; x++)
			map_well[y][x] = false;
}

void Well::draw(Painter p, Tetramino * t) const
{
	p.setColor(Painter::WHITE);
	p.frame(1, 1,WEITH * CELL_SIZE, HEIGHT * CELL_SIZE);
	p.setColor(static_cast<Painter::Color>(t->get_color()));
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WEITH; x++) {
			if (map_well[y][x]) p.rect( x * CELL_SIZE + GAP, y * CELL_SIZE + GAP,
									  (x + 1) * CELL_SIZE - GAP, (y + 1) * CELL_SIZE - GAP);
		}
	}
}

void Well::unit(Tetramino * t)
{
	for (int y = 0; y < SHAPE_SIZE; y++) {
		for (int x = 0; x < SHAPE_SIZE; x++) {
			int x_cell = x + t->get_x();
			int y_row = y + t->get_y();
			if (x_cell >= 0 && x_cell < WEITH && y_row >= 0 && y_row < HEIGHT)
				map_well[y_row][x_cell] = map_well[y_row][x_cell] || t->map(x, y);
		}
	}
}

bool Well::isCollision(Tetramino * t) const
{
	for (int y = 0; y < SHAPE_SIZE; y++) {
		for (int x = 0; x < SHAPE_SIZE; x++) {
			if (t->map(x, y))
			{
				int x_cell = x + t->get_x();
				int y_row = y + t->get_y();
				if (x_cell < 0 || x_cell >= WEITH || y_row < 0 || y_row >= HEIGHT)
					return true;
				if (map_well[y_row][x_cell]) return true;
			}
		}
	}
	return false;
}

int Well::removeSolidLines() {
	int count_remove = 0;
	for (int y = 0; y < HEIGHT; y++) {
		bool solid = true;
		for (int x = 0; x < WEITH; x++) {
			if (!map_well[y][x]) {
				solid = false;
				break;
			}
		}
		if (solid) {
			++count_remove;
			for (int y1 = y - 1; y1 >= 0; y1--)
				for (int x = 0; x < WEITH; x++)
					map_well[y1 + 1][x] = map_well[y1][x];
		}
	}
	for (int x = 0; x < WEITH; x++) map_well[0][x] = false;
	return count_remove;
}
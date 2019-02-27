#pragma once
#include "Cell.h"
class Tools
{
public:
	static void init(Cell grid[GRID_SIZE][GRID_SIZE]);
	static void copyGrid(Cell src[GRID_SIZE][GRID_SIZE], Cell dst[GRID_SIZE][GRID_SIZE]);
	static void giveLife(Cell grid[GRID_SIZE][GRID_SIZE], int x, int y);
};


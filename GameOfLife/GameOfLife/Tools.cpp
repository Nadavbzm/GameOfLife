#include "Tools.h"


void Tools::init(Cell grid[GRID_SIZE][GRID_SIZE])
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			grid[i][j].x = j;
			grid[i][j].y = i;
			grid[i][j].isAlive = false;
		}
	}
}

void Tools::copyGrid(Cell src[GRID_SIZE][GRID_SIZE], Cell dst[GRID_SIZE][GRID_SIZE])
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			dst[i][j] = src[i][j];
		}
	}
}

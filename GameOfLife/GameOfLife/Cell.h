#pragma once
#define GRID_SIZE 20
class Cell
{
public:
	int x;
	int	y;
	bool isAlive;
	char getLetter();
	Cell();
	~Cell();
	int getNeighbors(Cell grid[GRID_SIZE][GRID_SIZE]); //Checks 8 surrounding neighbors
	Cell(int x, int y);
	char nextGen(Cell grid[GRID_SIZE][GRID_SIZE]);// will return if cell lives or dies this turn
};


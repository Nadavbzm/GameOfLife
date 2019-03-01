#include "Cell.h"

Cell::Cell(int x, int y)
{
	this->x = x;
	this->y = y;
	this->isAlive = false;
}

char Cell::getLetter()
{
	char c = ' ';
	isAlive ? c = '0' : c = '-';
	return c;
}

Cell::Cell()
{
}


Cell::~Cell()
{
	std::cout << "aa" << '\n';
}

int Cell::getNeighbors(Cell grid[GRID_SIZE][GRID_SIZE])
{
	int n = 0;
	bool flagXRight = false;
	bool flagXLeft = false;
	bool flagYUp = false;
	bool flagYDown = false;

	if (y == GRID_SIZE - 1){
		flagYUp = true;
	}

	if (x == GRID_SIZE){
		flagXRight = true;
	}

	if (y == 0){
		flagYDown = true;
	}

	if (x == 0){
		flagXLeft = true;
	}


		if (!flagXRight && !flagYUp && grid[this->y+1][this->x + 1].isAlive) { n++; } //ALL right size
		if (!flagXRight && grid[this->y][this->x + 1].isAlive ) { n++; }
		if (!flagXRight && !flagYDown && grid[this->y-1][this->x + 1].isAlive) { n++; }

		if (!flagYUp && grid[this->y+1][this->x].isAlive) { n++; } //All up
		if (!flagXLeft && !flagYUp && grid[this->y+1][this->x - 1].isAlive ) { n++; }

		if (!flagXLeft && grid[this->y][this->x - 1].isAlive) { n++; } //All left side
		if (!flagXLeft && !flagYDown && grid[this->y-1][this->x - 1].isAlive) { n++; }

		if (!flagYDown && grid[this->y-1][this->x].isAlive) { n++; }
		return n;
}

char Cell::nextGen(Cell grid[GRID_SIZE][GRID_SIZE])
{
	int n = getNeighbors(grid);
	if (this->isAlive) //needs 2 or neighbors to live
	{
		if (n == 3 || n == 2)
		{
			return '0';
		}
	}

	if (!this->isAlive)
	{
		if (n == 3)
		{
			this->isAlive = true;
			return '0';
		}
	}

	this->isAlive = false;
	return '-';

}

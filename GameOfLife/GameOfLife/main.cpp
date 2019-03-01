#include <stdio.h>
#include <iostream>
#include "Cell.cpp"
#include "Tools.cpp"

int main()
{
	int count = 0;
	int liveCellCount = 0;
	int liveX = 0;
	int liveY = 0;
	//char displayGrid[GRID_SIZE][GRID_SIZE] = {0};
	Cell grid[GRID_SIZE][GRID_SIZE];
	Cell grid2[GRID_SIZE][GRID_SIZE];
	Tools::init(grid);
	Tools::copyGrid(grid, grid2);
	std::cout << "Hello! Welcome To Conway's Game Of Life!" << std::endl;
	std::cout << "The Rules of The game Are As Follows:" << std::endl;
	std::cout << "There are live cells ( 0 ), and dead cells ( - )." << std::endl <<
	"Live cells continue to live to next turn if they have 2 or 3 living neighbors" << std::endl <<
	"dead cells become alive if they have exactly 3 living neighbors" << std::endl <<  std::endl;

	std::cout << "Enter number of cells to give life to: ";
	std::cin >> liveCellCount;
	for (int i = 0; i < liveCellCount; i++)
	{
		std::cout << std::endl << "Enter cell " << i << "'s Y: ";
		std::cin >> liveY;
		std::cout << std::endl << "Enter cell " << i+1 << "'s X: ";
		std::cin >> liveX;
		grid[liveY][liveX].isAlive = true;
	}

	//std::cout << "Enter of cells to give life to:";
Tools::printGrid(grid);
int a = getchar();

	while (true)
	{
		Tools::copyGrid(grid, grid2);
		std::cout << "Cell iteration " << count << ": ";
		for (int i = GRID_SIZE-1; i > 0; i--)
		{
			for (int j = 0; j < GRID_SIZE; j++)
			{
				grid2[i][j].isAlive = grid[i][j].nextGen(grid) == '0';
				std::cout << grid2[i][j].getLetter();
			}
			std::cout << std::endl;
		}
		Tools::copyGrid(grid2, grid);
		count++;
		//system("pause");
		std::cout << std::endl;
		int a = getchar();
	}
	return 0;
}

#include "Game.h"
#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;

Game::Game() {

	resetVector(grid);
	
}



void Game::setAlive(int y, int x) {
	grid[x][y] = true;
}

void Game::play() {

	while (true) {

		int n;
		std::cin >> n;
		if (n < 0) {
			break;
		}

		printGrid(grid);
		printBlanks();

		std::this_thread::sleep_for(std::chrono::seconds(tickRate));

		vector<vector<bool>> temp = grid;

		getNextTick(temp);
		grid = temp;


	}

}

void Game::setTickRate(int tick) {
	tickRate = tick;
}

/*

Game Rules:

- Cells with less than 2 neighbours dies.
- Cells with two or three neigbours lives.
- Cells with three neighbours gets alive.
- Cells with more than 3 neighbours dies.

*/

void Game::getNextTick(vector<vector<bool>> &tempGrid) {

	for (auto i = 0; i < gridSize; i++) {
		for (auto j = 0; j < gridSize; j++) {

			int nCount = getNeighbourCount(i, j, grid);

			if (nCount < 2) tempGrid[i][j] = false;
			else if (nCount == 2 && tempGrid[i][j] ) tempGrid[i][j] = true;
			else if (nCount == 3) tempGrid[i][j] = true;
			else if (nCount > 3) tempGrid[i][j] = false;

		}
	}

}

int Game::getNeighbourCount(int xCoor, int yCoor, vector<vector<bool>> &tempGrid) {

	int nCount = 0;

	for (auto i = -1; i < 2; i++) {

		int tempXCoor = xCoor + i;
		
		if (tempXCoor < 0 || tempXCoor >= gridSize) {
			continue;
		}

		for (auto j = -1; j < 2; j++) {

			int tempYCoor = yCoor + j;
			
			if (tempYCoor < 0 || tempYCoor >= gridSize) {
				continue;
			}

			if (tempGrid[tempXCoor][tempYCoor] && !(tempXCoor == xCoor && tempYCoor == yCoor)) nCount++;

		}
	}

	return nCount;
}

void Game::printGrid(vector<vector<bool>> &printToGrid) {

	for (auto i = 0; i < gridSize; i++) {
		for (auto j = 0; j < gridSize; j++) {
			cout << printToGrid[i][j];
		}
		cout << endl;
	}

}

void Game::printBlanks() {

	for (auto i = 0; i < 20; i++) {
		cout << "-";
	}

	cout << endl;

}

void Game::resetVector(vector<vector<bool>> &grid) {

	for (auto i = 0; i < gridSize; i++) {
		vector<bool> temp(gridSize, false);
		grid.push_back(temp);
	}

}


#include "Game.h"
#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>
#include <algorithm>

using std::cout;
using std::endl;

Game::Game() {

	getRules();
	resetVector(grid);
	
}



void Game::setAlive(int y, int x) {
	grid[x][y] = true;
}

void Game::play() {

	int tick = 0;

	while (this->tickAmount == -1 || tick < this->tickAmount) {


		printGrid(grid);
		printBlanks();

		std::this_thread::sleep_for(std::chrono::seconds(this->tickRate));

		vector<vector<bool>> temp = grid;

		getNextTick(temp);
		grid = temp;

		tick++;


	}

}

void Game::getRules() {

	this->tickRate = Rules::getTickRate();
	this->tickAmount = Rules::getTickAmount();

}

void Game::setTickRate(int tickRate) {
	this->tickRate = tickRate;
}

void Game::setTickAmount(int tickAmount) {
	this->tickAmount = tickAmount;
}

void Game::setGridSize(int gridSize) {
	this->gridSize = gridSize;
}

/*

Game Rules:

- Cells that are alive with the amount of neighbours in designated rules lives
- Cells that are dead with the amount of neighbours in designated rules resurrects
- Cells with every other composition either continues being dead or dies

*/

void Game::getNextTick(vector<vector<bool>> &tempGrid) {

	for (auto i = 0; i < gridSize; i++) {
		for (auto j = 0; j < gridSize; j++) {

			int nCount = getNeighbourCount(i, j, grid);

			vector<int>* liveIfAlive = Rules::getLiveIfAlive();
			vector<int>* liveIfDead = Rules::getLiveIfDead();

			if (std::find(liveIfAlive->begin(), liveIfAlive->end(), nCount ) != liveIfAlive->end() && tempGrid[i][j]) {
				tempGrid[i][j] = true;
			}

			else if (std::find(liveIfDead->begin(), liveIfDead->end(), nCount) != liveIfDead->end()) {
				tempGrid[i][j] = true;
			}
			else {
				tempGrid[i][j] = false;
			}

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

	for (auto i = 0; i < gridSize; i++) {
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


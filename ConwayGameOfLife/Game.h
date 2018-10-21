#pragma once
#include <vector>
#include "Rules.h"

using std::vector;

class Game : public Rules {
public:
	Game();

	void setAlive(int, int);
	void play();

	void setTickRate(int);
	void setTickAmount(int);
	void setGridSize(int);

private:
	int gridSize = 5;
	vector<vector <bool>> grid;

	int aliveCount = 0;
	int deadCount = 0;

	void resetVector(vector<vector<bool>> &v);
	
	void printGrid(vector<vector<bool>> &);
	void printBlanks();

	int getNeighbourCount(int, int, vector<vector<bool>> &);

	void getNextTick(vector<vector<bool>> &);

	// tick rate of the simulation as seconds
	int tickRate = 1;
	int tickAmount = -1;

	void getRules();
};


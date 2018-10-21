#pragma once
#include <vector>

using std::vector;

class Rules {
public:
	Rules();
	static void addLiveIfAlive(int);
	static void addLiveIfDead(int);
	static void setTickRate(int);
	static void setTickAmount(int);
	static void setGridSize(int);

	static vector<int>* getLiveIfAlive();
	static vector<int>* getLiveIfDead();
	static int getTickRate();
	static int getTickAmount();
	static int getGridSize();

private:
	static vector<int> liveIfAlive;
	static vector<int> liveIfDead;
	static int tickRate;
	static int tickAmount;
	static int gridSize;

};


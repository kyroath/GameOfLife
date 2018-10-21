#pragma once
#include <vector>
#include <map>

using std::vector;
using std::map;

class Rules {
public:
	Rules();
	static void addLiveIfAlive(int);
	static void addLiveIfDead(int);
	static void setTickRate(int);
	static void setTickAmount(int);
	static void setGridSize(int);
	static void setAlive(int, int);

	static vector<int>* getLiveIfAlive();
	static vector<int>* getLiveIfDead();
	static map<int, int>* getAliveBits();
	static int getTickRate();
	static int getTickAmount();
	static int getGridSize();

private:
	static vector<int> liveIfAlive;
	static vector<int> liveIfDead;
	static map<int, int> aliveBits;
	static int tickRate;
	static int tickAmount;
	static int gridSize;

};


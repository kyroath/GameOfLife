#pragma once
#include <vector>
#include <map>
#include <array>

using std::vector;
using std::map;

class Rules {
public:
	Rules();
	static vector<int> liveIfAlive;
	static vector<int> liveIfDead;
	static vector<std::array<int, 2>> aliveBits;
	static int tickRate;
	static int tickAmount;
	static int gridSize;

};


#include "Rules.h"

int Rules::tickRate = 1;
int Rules::tickAmount = -1;
int Rules::gridSize = 10;
vector<int> Rules::liveIfAlive;
vector<int> Rules::liveIfDead;
vector<std::array<int, 2>> Rules::aliveBits;

Rules::Rules() {
}

#include "Rules.h"



Rules::Rules() {
	tickRate = 1;
	tickAmount = -1;
	gridSize = 10;
}

void Rules::addLiveIfAlive(int nCount) {
	liveIfAlive.push_back(nCount);
}

void Rules::addLiveIfDead(int nCount) {
	liveIfDead.push_back(nCount);
}

void Rules::setTickRate(int tick) {
	tickRate = tickRate;
}

void Rules::setTickAmount(int tick) {
	tickAmount = tick;
}

void Rules::setGridSize(int size) {
	gridSize = size;
}

vector<int>* Rules::getLiveIfAlive() {

	vector<int>* pointer = &liveIfAlive;
	return pointer;

}

vector<int>* Rules::getLiveIfDead() {

	vector<int>* pointer = &liveIfDead;
	return pointer;

}

int Rules::getTickRate() {
	return tickRate;
}

int Rules::getTickAmount() {
	return tickAmount;
}

int Rules::getGridSize() {
	return gridSize;
}

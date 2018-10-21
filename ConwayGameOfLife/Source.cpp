#include <iostream>
#include "Game.h"

int main() {
	
	Game game;
	game.setAlive(0, 0);
	game.setAlive(0, 1);
	game.setAlive(1, 0);
	game.setAlive(1, 1);
	game.setAlive(0, 2);

	game.play();

	return 0;
}
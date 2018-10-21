#include <iostream>
#include "Game.h"
#include "Parser.h"

int main() {
	
	Parser parser("Rules.gol");
	parser.parse();

	Game game;
	game.play();


	return 0;
}
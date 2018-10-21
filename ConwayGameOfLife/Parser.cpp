#include "Parser.h"
#include "Rules.h"
#include <iostream>


Parser::Parser() {
}

Parser::Parser(string fileName) {
	this->fileName = fileName;
}

void Parser::readFile() {
	file.open(fileName);
	if (!file.open) {
		std::cout << "Error while reading file" << std::endl;
		exit(2);
	}

	parseFile();
}

void Parser::parseFile() {

	string line;
	while (std::getline(file, line)) {
		std::vector<string> tokens = tokenize(line);

		try {

			if (tokens[0] == "livealive") {

				for (auto i = 1; i < tokens.size(); i++) {
					Rules::addLiveIfAlive(std::stoi(tokens[i]));
				}
			}
			else if (tokens[0] == "livedead") {

				for (auto i = 1; i < tokens.size(); i++) {
					Rules::addLiveIfDead(std::stoi(tokens[i]));
				}
			}
			else if (tokens[0] == "tickrate") {
				Rules::setTickRate(std::stoi(tokens[1]));
			}
			else if (tokens[0] == "tickamount") {
				Rules::setTickAmount(std::stoi(tokens[1]));
			}
			else if (tokens[0] == "gridsize") {
				Rules::setGridSize(std::stoi(tokens[1]));
			}
			else if (tokens[0] == "alive") {
				Rules::setAlive(std::stoi(tokens[1]), std::stoi(tokens[2]));
			}
			else if (tokens[0] == "#") {
				continue;
			}

		}
		catch (const std::out_of_range) {
			std::cout << "Syntax error at line: " << line << std::endl;
		}
	}

}

std::vector<string> Parser::tokenize(string &line) const {

	vector<string> tokens;

	for (auto i = 0, start = i; i < line.size(); i++) {
		if (line.at(i) == ' ') {
			tokens.push_back(line.substr(start, i));
			start = i + 1;
		}
	}

	return tokens;
}

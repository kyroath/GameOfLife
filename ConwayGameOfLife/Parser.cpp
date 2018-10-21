#include "Parser.h"
#include "Rules.h"
#include <iostream>
#include <algorithm>


Parser::Parser() {
}

Parser::Parser(string fileName) {
	this->fileName = fileName;
}

void Parser::parse() {

	readFile();

}

void Parser::readFile() {
	file.open(fileName);
	if (!file.is_open()) {
		std::cout << "Error while reading file" << std::endl;
		exit(2);
	}

	parseFile();
}

void Parser::parseFile() {

	string line;
	while (std::getline(file, line)) {

		if (line.size() == 0) {
			continue;
		}

		std::vector<string> tokens = tokenize(line);

		try {

			if (tokens[0] == "livealive") {

				for (int i = 1; i < tokens.size(); i++) {
					Rules::liveIfAlive.push_back(std::stoi(tokens[i]));
				}
			}
			else if (tokens[0] == "livedead") {

				for (int i = 1; i < tokens.size(); i++) {
					Rules::liveIfDead.push_back(std::stoi(tokens[i]));
				}
			}
			else if (tokens[0] == "tickrate") {
				Rules::tickRate = std::stoi(tokens[1]);
			}
			else if (tokens[0] == "tickamount") {
				Rules::tickAmount = std::stoi(tokens[1]);
			}
			else if (tokens[0] == "gridsize") {
				Rules::gridSize = std::stoi(tokens[1]);
			}
			else if (tokens[0] == "alive") {

				// quick hack with std::array
				std::array<int, 2> arr = { std::stoi(tokens[1]), std::stoi(tokens[2]) };
				
				Rules::aliveBits.push_back(arr);
			}
			else if (tokens[0] == "#") {
				continue;
			}

		}
		catch (const std::out_of_range) {
			std::cout << "Syntax error at line: " << line << std::endl;
		}
		catch (const std::invalid_argument) {
			std::cout << "invalid argument at stoi at line:" << std::endl << line << std::endl;
		}
	}

}

std::vector<string> Parser::tokenize(string &line) const {

	vector<string> tokens;

	int start = 0;
	for (auto i = 0; i < line.size(); i++) {
		if (line.at(i) == ' ') {
			string temp = line.substr(start, i - start);
			tokens.push_back(temp);
			start = i + 1;
		}
	}

	tokens.push_back(line.substr(start, line.size() - start));

	for (auto it = tokens.begin(); it != tokens.end(); ) {
		if (it->size() == 0) {
			it = tokens.erase(it);
		}
		else {
			it++;
		}
	}

	return tokens;
}

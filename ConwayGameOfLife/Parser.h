#pragma once
#include <string>
#include <fstream>
#include <vector>

using std::string;

class Parser {
public:
	Parser();
	Parser(string);

private:
	string fileName = "";
	std::ifstream file;

	void readFile();
	void parseFile();
	std::vector<string> tokenize(string &) const;
};


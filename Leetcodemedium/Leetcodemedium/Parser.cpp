#include "Parser.h"


Parser::Parser(FILE * file) :
	stream(file)
{
}

string Parser::getNextLine()
{
	string line;
	getline(std::cin, line);
	return line;
}

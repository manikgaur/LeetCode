#pragma once
#include <iostream>
#include <string>
using namespace std;
class Parser
{
	FILE* stream;
public:
	Parser( FILE* file = stdin);
	string getNextLine();
};


#include <iostream>
#include <string>
#include "Parser.h"

using namespace std;
int main(int argc, char ** argv)
{
	int T, test_case;
	Parser P;
	freopen("input.txt", "r", stdin);

	std::string line;
	while (std::getline(std::cin, line))
	{
		//std::cout << line << std::endl;
		string ret;
		ret = P.parseString(line);
		if (ret.length())
			cout << ret << endl;

	}

	cout << "Hello World" << endl;
	exit(0);
}
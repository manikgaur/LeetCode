#include "QueryHowMuch.h"
#include "Codes.h"
#include <vector>
#include <sstream>

string QueryHowMuch::prepareResult(string initial, int value)
{
	string retStr;
	if (value) {
		retStr.append(initial);
		retStr.append("is ");
		retStr.append(to_string(value));
	}
	else {
		retStr.append("I have no idea what you are talking about");
	}
	return retStr;
}

string QueryHowMuch::evaluateString(string str)
{
	vector <string> tokens;
	std::stringstream s(str);
	string tmp;
	while (getline(s, tmp, ' '))
	{
		tokens.push_back(tmp);
	}
	int i = -1;
	string codedstring;
	do {
		i++;
		codedstring.append(tokens[i]);
		codedstring.append(" ");
	}while (tokens[i].compare("is") && i < tokens.size());

	if (!codedstring.compare("how much is ")) {
		Codes *code = Codes::getInstance();
		codedstring.clear();
		if (!tokens[tokens.size() - 1].compare("?")) {
			i++;
				do {
					codedstring.append(tokens[i]);
					codedstring.append(" ");
					i++;
				} while (tokens[i].compare("?") && i < tokens.size());
		}
		return prepareResult(codedstring, code->getInt(codedstring));
	}

	return 0;
}

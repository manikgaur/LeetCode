#include "QueryHowMany.h"
#include "Codes.h"
#include "Metals.h"
#include <vector>
#include <sstream>

string QueryHowMany::prepareResult(string initial, int value)
{
	string retStr;
	if (value) {
		retStr.append(initial);
		retStr.append("is ");
		retStr.append(to_string(value));
		retStr.append("Credits");
	}
	else {
		retStr.append("I have no idea what you are talking about");
	}
	return retStr;
}

string QueryHowMany::evaluateString(string str)
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
	} while (tokens[i].compare("is") && i < tokens.size());
	
	if (!codedstring.compare("how many Credits is ")) {
		Codes *code = Codes::getInstance();
		codedstring.clear();
		string metal = tokens[tokens.size() - 2];
		if (!tokens[tokens.size() - 1].compare("?")) {
			i++;
			do {
				codedstring.append(tokens[i]);
				codedstring.append(" ");
				i++;
			} while (tokens[i].compare(metal) && i < tokens.size());
		}
		int count = code->getInt(codedstring);
		Metals *metalInst = Metals::getInstance();
		float price = metalInst->getValue(metal);
		return prepareResult(codedstring + metal +" ", count * price);
	}
	return 0;
}

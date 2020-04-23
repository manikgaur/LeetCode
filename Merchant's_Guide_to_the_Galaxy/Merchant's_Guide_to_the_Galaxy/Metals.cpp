#include "Metals.h"
#include "Codes.h"
#include <vector>
#include <string>
#include <sstream>

Metals* Metals::obj = 0;

Metals* Metals::getInstance()
{
	if (!obj)
		obj = new Metals();
	return obj;
}

float Metals::getValue(string key)
{
	return data.at(key);
}

void Metals::setValue(string key, float value)
{
	pair<string, int> p(key, value);
	data.insert(p);
}

string Metals::evaluateString(string str)
{
	Codes *codes = Codes::getInstance();
	if (str.empty())
		return 0;
	vector <string> tokens;
	std::stringstream s(str);
	string tmp;
	while (getline(s, tmp, ' '))
	{
		tokens.push_back(tmp);
	}
	int i = 0;
	string codedstring;
	while (tokens[i].compare("is")) {
		i++;
	}
	string metal = tokens[i-1];
	float credits = stoi(tokens[i + 1]);
	i = 0;
	while (tokens[i].compare(metal)) {
		codedstring.append(tokens[i]);
		codedstring.append(" ");
		i++;
	}
	int numberOfMetals = codes->getInt(codedstring);

	pair<string, float> metalsCost(metal, credits / numberOfMetals);
	data.insert(metalsCost);
	
	return string();
}

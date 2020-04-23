#include "Codes.h"
#include <iostream>
#include <utility>
#include <sstream>
#include <vector>

using namespace std;

Codes *Codes::obj = 0;

Codes::Codes()
{
	romanToInt['I'] = 1;
	romanToInt['V'] = 5;
	romanToInt['X'] = 10;
	romanToInt['L'] = 50;
	romanToInt['C'] = 100;
	romanToInt['D'] = 500;
	romanToInt['M'] = 1000;

}

Codes* Codes::getInstance()
{
	if (!obj)
		obj = new Codes();
	return obj;
}

string Codes::getValue(string key)
{
	return data.at(key);
}

void Codes::setValue(string key, string value)
{
	pair<string, string> p(key, value);
	data.insert(p);
}

string Codes::convertCodeToRoman(string str)
{	
	string romanString;
	vector <string> tokens;
	std::stringstream s(str);
	string tmp;
	while (getline(s, tmp, ' '))
	{
		romanString.append(data[tmp]);
	}
	
	return romanString;
}

int Codes::convertRomanToNumber(string roman)
{
	int i = roman.length() - 1;
	int value = 0;
	for (; i >= 0; i--)
	{
		if(i < roman.length() - 1 && romanToInt[roman[i]] < romanToInt[roman[i+1]])
			value -= romanToInt[roman[i]];
		else
			value += romanToInt[roman[i]];
	}
	return value;
}

int Codes::getInt(string codes)
{
	string romanStr = convertCodeToRoman(codes);
	int value = convertRomanToNumber(romanStr);

	return value;
}

string Codes::evaluateString(string str)
{
	vector <string> tokens;
	std::stringstream s(str);
	string tmp;
	while (getline(s, tmp, ' '))
	{
		tokens.push_back(tmp);
	}
	int i = 0;
	while (tokens[i].compare("is")) {
		i++;
	}
	pair<string, string> codeToRoman(tokens[i - 1], tokens[i + 1]);
	data.insert(codeToRoman);

	return string();
}

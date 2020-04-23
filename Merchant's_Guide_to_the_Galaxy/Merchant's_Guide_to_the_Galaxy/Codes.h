#ifndef H_CODES
#define H_CODES

#include <map>
using namespace std;
class Codes
{
	static Codes *obj;
	Codes();
	map<string, string> data;
	map<char, int> romanToInt;
public:
	static Codes* getInstance();
	string getValue(string);
	void setValue(string, string);
	string convertCodeToRoman(string codes);
	int convertRomanToNumber(string codes);
	int getInt(string codes);
	string evaluateString(string codes);
};

#endif
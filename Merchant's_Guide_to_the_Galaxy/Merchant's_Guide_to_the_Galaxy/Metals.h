#ifndef H_METAL
#define H_METAL

#include <map>
#include <string>

using namespace std;
class Metals
{
	static Metals* obj;
	Metals() {}
	map<string, float> data;
public:
	static Metals* getInstance();
	float getValue(string);
	void setValue(string, float);
	string evaluateString(string codes);
};

#endif
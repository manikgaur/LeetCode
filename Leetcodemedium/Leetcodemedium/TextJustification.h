#pragma once
#include "Solution.h"
class TextJustification :
	public Solution
{
	int maxWidth;
	vector<string> words;
public:
	TextJustification();
	void adjustLine(string& line, int maxWidth);
	vector<string> fullJustify(vector<string>& words, int maxWidth);
	void solve();
	void fillInput();
};


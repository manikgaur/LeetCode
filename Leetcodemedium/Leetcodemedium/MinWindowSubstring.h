#pragma once
#include "Solution.h"
class MinWindowSubstring :
	public Solution
{
	string S;
	string T;
public:
	MinWindowSubstring();
	void solve();
	string minWindow(string s, string t);
	void fillInput();
};


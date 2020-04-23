#pragma once
#include "Solution.h"
class LongestStringChain :
	public Solution
{
	vector<string> words;
public:
	LongestStringChain();
	void solve();
	int getDiff(string &s1, string &s2);
	static bool compare(string & s1, string & s2);
	int longestStrChain(vector<string>& words);
	void fillInput();
};


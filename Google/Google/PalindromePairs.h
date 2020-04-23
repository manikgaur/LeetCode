#pragma once
#include "Solution.h"
class PalindromePairs :
	public Solution
{
	vector<string> words;
public:
	PalindromePairs();
	bool isPailndrome(string str1, string str2);
	vector<vector<int>> palindromePairs(vector<string>& words);
	vector<vector<int>> palindromePairs2(vector<string>& words);
	void solve();
	void fillInput();
};


#pragma once
#include "Solution.h"
class WordLadderII :
	public Solution
{
	string beginWord;
	string endWord;
	vector<string> wordList;
public:
	WordLadderII();
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
	void solve();
	void fillInput();
};


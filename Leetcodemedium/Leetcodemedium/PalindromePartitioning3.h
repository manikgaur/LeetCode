#pragma once
#include "Solution.h"
class PalindromePartitioning3 :
	public Solution
{
	int K;
	string str;
	vector<vector<vector<int>>> data;
public:
	PalindromePartitioning3();
	int calculateChanges(string s, int start, int end);
	int doPalindromePartition(string s, int k, int start, int end);
	int palindromePartition(string s, int k);
	void solve();
	void fillInput();
};


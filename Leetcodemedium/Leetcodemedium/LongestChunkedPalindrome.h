#pragma once
#include "Solution.h"
class LongestChunkedPalindrome :
	public Solution
{
	string str;
public:
	LongestChunkedPalindrome();
	int longestDecomposition(string text);
	void solve();
	void fillInput();
};


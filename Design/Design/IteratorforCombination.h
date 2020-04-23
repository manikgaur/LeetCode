#pragma once
#include "Solution.h"
class IteratorforCombination :
	public Solution
{
	vector<string> queries;
	vector<string> qData;
public:
	IteratorforCombination();
	void solve();
	void fillInput();
};


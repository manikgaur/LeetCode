#pragma once
#include "Solution.h"

class LastStoneWeight :
	public Solution
{
	vector<int> nums;
public:
	LastStoneWeight();
	void solve();
	int lastStoneWeight(vector<int>& stones);
	void fillInput();
};


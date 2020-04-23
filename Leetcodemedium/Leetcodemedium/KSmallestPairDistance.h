#pragma once
#include "Solution.h"

class KSmallestPairDistance :
	public Solution
{
	vector<int> nums;
	int m;
public:
	KSmallestPairDistance();
	void solve();
	int smallestDistancePair(vector<int>& nums, int k);
	void fillInput();
};


#pragma once
#include "Solution.h"
class SplitArrayLargestSum :
	public Solution
{
	vector<int> nums;
	int m;
public:
	SplitArrayLargestSum();
	void solve();
	int splitArray(vector<int>& nums, int m);
	int findMax(vector<int>& nums, int sum);
	void fillInput();
};


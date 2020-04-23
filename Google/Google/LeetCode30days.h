#pragma once
#include "Solution.h"
class LeetCode30days :
	public Solution
{
	string s;
	vector<int> nums;
public:
	LeetCode30days();
	int maxSubArray(vector<int>& nums);
	void solve();
	void fillInput();
};


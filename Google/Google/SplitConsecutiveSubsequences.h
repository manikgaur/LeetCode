#pragma once
#include "Solution.h"
class SplitConsecutiveSubsequences :
	public Solution
{
	vector<int> nums;
public:
	SplitConsecutiveSubsequences();
	bool isPossible(vector<int>& nums);
	void solve();
	void fillInput();
};


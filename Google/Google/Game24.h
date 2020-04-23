#pragma once
#include "Solution.h"
class Game24 :
	public Solution
{
	vector<int> nums;
public:
	Game24();
	void solve();
	void fillInput();
	bool judgePoint24(vector<int>& nums);
};


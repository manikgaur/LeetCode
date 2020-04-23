#pragma once
#include "Solution.h"
class PredicttheWinner :
	public Solution
{	vector<int> nums;
public:
	PredicttheWinner();
	bool PredictTheWinner(vector<int>& nums);
	bool PredictTheWinner2(vector<int>& nums);
	void solve();
	void fillInput();
};


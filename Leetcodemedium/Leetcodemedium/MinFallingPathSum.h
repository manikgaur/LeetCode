#pragma once
#include "Solution.h"
class MinFallingPathSum :
	public Solution
{
	vector<vector<int>> arr;
public:
	MinFallingPathSum();
	int minFallingPathSum2(vector<vector<int>>& arr);
	int minFallingPathSum(vector<vector<int>>& arr);
	void solve();
	void fillInput();
};


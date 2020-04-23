#pragma once
#include "Solution.h"
class MaxSumRectangleNoLarger :
	public Solution
{
	int K;
	vector<vector<int>> matrix;
public:
	MaxSumRectangleNoLarger();
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k);
	void solve();
	void fillInput();
};


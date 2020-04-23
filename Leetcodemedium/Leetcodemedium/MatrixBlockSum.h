#pragma once
#include "Solution.h"
class MatrixBlockSum :
	public Solution
{
	vector<vector<int>> mat;
	int K;
public:
	MatrixBlockSum();
	void solve();
	int findSum(vector<vector<int>>& data, int x1, int x2, int y1, int y2);
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K);
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target);
	void fillInput();
};


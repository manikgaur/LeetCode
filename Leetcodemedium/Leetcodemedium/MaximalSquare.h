#pragma once
#include "Solution.h"
class MaximalSquare :
	public Solution
{
	vector<vector<char>> matrix;
public:
	MaximalSquare();
	void solve();
	int maximalSquare(vector<vector<char>>& matrix);
	void fillInput();
};


#pragma once
#include "Solution.h"
#include <vector>
class MaxIncreaseSkyLine :
	public Solution
{
public:
	vector < vector<int>> data;
	MaxIncreaseSkyLine();
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid);
	virtual void solve();
	virtual void fillInput();
};


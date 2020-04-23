#pragma once
#include "Solution.h"
class MinimumAreaRectangle :
	public Solution
{
	vector<vector<int>> points;
	static bool compare(vector<int>& p1, vector<int>& p2);
public:
	MinimumAreaRectangle();
	void solve();
	int minAreaRect(vector<vector<int>>& points);
	void fillInput();
};


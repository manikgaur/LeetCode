#pragma once
#include "Solution.h"

class KClosestToOrigin :
	public Solution
{
	vector<vector<int>> points;
	int K;

public:
	KClosestToOrigin();
	void solve();
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K);
	void fillInput();
};


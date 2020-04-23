#pragma once
#include "Solution.h"

struct values {
	int max;
	int cost;
	bool visited;
	values():max(0), cost(0),visited(false){}
};

class MinimumCostTreeFromLeafValues :
	public Solution
{
	vector<vector<values>> data;
	vector<int> nums;
public:
	MinimumCostTreeFromLeafValues();
	void solve();
	int minCost(vector<int>& arr, int start, int end, int & max);
	int minCostDP(vector<int>& arr);
	int mctFromLeafValues(vector<int>& arr);
	void fillInput();
};


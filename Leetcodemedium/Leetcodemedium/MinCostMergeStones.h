#pragma once
#include "Solution.h"
class MinCostMergeStones :
	public Solution
{
	int K;
	vector<int> stones;
	vector<vector<int>> data;
public:
	MinCostMergeStones();
	int mergeKstones(vector<int>& stones, vector<int>& sumArray, int K, int s, int e);
	int mergeStones(vector<int>& stones, int K);
	void solve();
	void fillInput();
};


#pragma once
#include "Solution.h"
class ShortestSubarraySumatLeastK :
	public Solution
{
	int K;
	vector<int> data;
public:
	ShortestSubarraySumatLeastK();
	int shortestSubarray(vector<int>& A, int K);
	void solve();
	void fillInput();
};


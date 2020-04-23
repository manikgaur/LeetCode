#pragma once
#include "Solution.h"
class MinDominoRotation :
	public Solution
{
	vector<int> A;
	vector<int> B;
public:
	MinDominoRotation();
	void solve();
	int minDominoRotations(vector<int>& A, vector<int>& B);
	void fillInput();
};


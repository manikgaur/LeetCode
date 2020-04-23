#pragma once
#include "Solution.h"
class Flatten2DVector :
	public Solution
{
	vector<string> queries;
	vector<vector<int>> data;
public:
	Flatten2DVector();
	void solve();
	void fillInput();
};


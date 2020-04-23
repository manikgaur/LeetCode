#pragma once
#include "Solution.h"
class HashMap :
	public Solution
{
	vector<string> queries;
	vector<vector<int>> qData;
public:
	HashMap();
	void solve();
	void fillInput();
};


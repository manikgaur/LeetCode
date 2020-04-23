#pragma once
#include "Solution.h"
class DesignCircularQueue :
	public Solution
{
	vector<string> queries;
	vector<int> qData;
public:
	DesignCircularQueue();
	void solve();
	void fillInput();
};


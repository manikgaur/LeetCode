#pragma once
#include "Solution.h"
class DesignSkiplist :
	public Solution
{
	vector<string> queries;
	vector<int> qData;
public:
	DesignSkiplist();
	void solve();
	void fillInput();
};


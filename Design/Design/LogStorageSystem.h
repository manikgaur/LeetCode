#pragma once
#include "Solution.h"
class LogStorageSystem :
	public Solution
{
	vector<string> queries;
	vector<vector<string>> qData;
public:
	LogStorageSystem();
	void solve();
	void fillInput();
};


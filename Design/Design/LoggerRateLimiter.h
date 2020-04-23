#pragma once
#include "Solution.h"
class LoggerRateLimiter :
	public Solution
{
	vector<string> queries;
	vector<vector<string>> qData;
public:
	LoggerRateLimiter();
	void solve();
	void fillInput();
};


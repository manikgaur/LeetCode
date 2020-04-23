#pragma once
#include "Solution.h"
class DesignPhoneDirectory :
	public Solution
{
	vector<string> queries;
	vector<int> qData;
public:
	DesignPhoneDirectory();
	void solve();
	void fillInput();
};


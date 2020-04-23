#pragma once
#include "Solution.h"
class AddandSearchWord :
	public Solution
{
	vector<string> queries;
	vector<string> qData;
public:
	AddandSearchWord();
	void solve();
	void fillInput();
};


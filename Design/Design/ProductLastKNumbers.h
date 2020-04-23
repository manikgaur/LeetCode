#pragma once
#include "Solution.h"
class ProductLastKNumbers :
	public Solution
{
	vector<string> queries;
	vector<int> qData;
public:
	ProductLastKNumbers();
	void solve();
	void fillInput();
};


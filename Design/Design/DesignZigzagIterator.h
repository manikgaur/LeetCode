#pragma once
#include "Solution.h"
class DesignZigzagIterator :
	public Solution
{
	vector<string> queries;
	vector<int> arr1;
	vector<int> arr2;
public:
	DesignZigzagIterator();
	void solve();
	void fillInput();
};


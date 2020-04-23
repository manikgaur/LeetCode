#pragma once
#include "Solution.h"
#include <vector>
class GroupThePeople :
	public Solution
{
public:
	vector<int> data;
	GroupThePeople();
	virtual void solve();
	virtual void fillInput();
};


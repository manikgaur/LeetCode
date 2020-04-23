#pragma once
#include "Solution.h"
class UniqueWordAbbreviation :
	public Solution
{
	vector<string> words;
	vector<string> queries;
	vector<string> qData;
public:
	UniqueWordAbbreviation();
	void solve();
	void fillInput();
};


#pragma once
#include "Solution.h"
class DesignSearchAutocompleteSystem :
	public Solution
{
	vector<string> queries;
	vector<string> sentences;
	vector<int> times;
	vector<char> qData;
public:
	DesignSearchAutocompleteSystem();
	void solve();
	void fillInput();
};


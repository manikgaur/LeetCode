#pragma once
#include "Solution.h"
class Gmockfirst :
	public Solution
{
	vector<int> heights;
	string name;
	string typed;
public:
	Gmockfirst();
	int heightChecker(vector<int>& heights);
	bool isLongPressedName(string name, string typed);
	void solve();
	void fillInput();
	void fillInput2();
};


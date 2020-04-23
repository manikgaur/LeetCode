#pragma once
#include "Solution.h"
class DesignTicTacToe :
	public Solution
{
	int size;
	vector<string> queries;
	vector<vector<int>> qData;
public:
	DesignTicTacToe();
	void solve();
	void fillInput();
};


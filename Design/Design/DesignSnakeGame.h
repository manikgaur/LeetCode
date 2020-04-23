#pragma once
#include "Solution.h"
class DesignSnakeGame :
	public Solution
{
	vector<string> queries;
	vector<int> grid;
	vector<vector<int>> food;
	vector<string> qData;
public:
	DesignSnakeGame();
	void solve();
	void fillInput();
};


#pragma once
#include "Solution.h"
class CatAndMouse :
	public Solution
{
	vector<vector<int>> graph;
public:
	CatAndMouse();
	int catMouseGame(vector<vector<int>>& graph);
	int catMouseGame2(vector<vector<int>>& graph);
	void solve();
	void fillInput();
};


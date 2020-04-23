#include "Solution.h"

#pragma once

struct Results {
	bool visited;
	bool win;
	int winCount;
	int lostCount;
	Results() :visited(false), win(false), winCount(0), lostCount(0) {}
};

class StoneGame :
	public Solution
{
	vector<vector<Results>> data;
	vector<vector<vector<int>>> dataII;
	vector<int> arr;
public:
	StoneGame();
	bool game(vector<int>& piles, int start, int end);
	bool stoneGame(vector<int>& piles);
	int maxStones(vector<int>& piles, int start, int end, int M);
	int stoneGameII(vector<int>& piles);
	void solve();
	void fillInput();
};



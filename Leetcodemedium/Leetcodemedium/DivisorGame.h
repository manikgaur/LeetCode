#pragma once
#include "Solution.h"
class DivisorGame :
	public Solution
{
	vector<bool> data;
	int N;
public:
	DivisorGame();
	void solve();
	bool divisorGame(int N);
	void fillInput();
};


#pragma once
#include "Solution.h"
class CanIWin :
	public Solution
{
	int a;
	int b;
public:
	CanIWin();
	bool canIWin(int maxChoosableInteger, int desiredTotal);
	void solve();
	void fillInput();
};


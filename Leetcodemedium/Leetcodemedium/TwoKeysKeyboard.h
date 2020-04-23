#pragma once
#include "Solution.h"
class TwoKeysKeyboard :
	public Solution
{
	int num;
public:
	TwoKeysKeyboard();
	void solve();
	int minSteps(int n);
	void fillInput();
};


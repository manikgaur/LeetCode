#pragma once
#include "Solution.h"
class RandomizedSet :
	public Solution
{
	unordered_map<int, int> positons;
	vector<int> elements;
	vector<string> queries;
	vector<int> data;
public:
	RandomizedSet();
	bool insert(int val);
	bool remove(int val);
	int getRandom();
	void solve();
	void fillInput();
};


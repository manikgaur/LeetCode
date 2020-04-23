#pragma once
#include "Solution.h"
class RandomizedCollection :
	public Solution
{
	unordered_map<int, list<int>> positons;
	vector<int> elements;
	vector<string> queries;
	vector<int> data;
public:
	RandomizedCollection();
	bool insert(int val);
	bool remove(int val);
	int getRandom();
	void solve();
	void fillInput();
};


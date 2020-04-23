#pragma once
#include "Solution.h"

class OOneNode
{
public:
	string val;
	int count;
	OOneNode *next;
	OOneNode *prev;
	OOneNode(string value = ""):val(value), count(1), next(NULL), prev(NULL){}
};

class AllOoneDS :
	public Solution
{
	map<int, list<OOneNode*>> data;
	unordered_map<string, OOneNode*> hashData;
	vector<string> queries;
	vector<string> qData;
public:
	AllOoneDS();
	void addNode(OOneNode * node);
	void removeNode(OOneNode * node);
	void inc(string key);
	void dec(string key);
	string getMaxKey();
	string getMinKey();
	void solve();
	void fillInput();
};


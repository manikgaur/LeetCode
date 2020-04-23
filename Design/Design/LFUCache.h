#pragma once
#include "Solution.h"

class DListNode
{
public:
	int key;
	int val;
	int freq;
	DListNode* next;
	DListNode* prev;
	DListNode(int k, int v) :key(k), val(v), freq(0), next(NULL), prev(NULL) {}
	DListNode() :key(0), val(0), freq(0), next(NULL), prev(NULL) {}
};

class LFUCache :
	public Solution
{
	int capacity;
	int size;
	map<int, pair<DListNode, DListNode>> cache;
	map<int, DListNode*> ref;
	vector<string> queries;
	vector<vector<int>> data;
public:
	LFUCache();
	LFUCache(int capacity);
	void setCapacity(int capacity);
	void addNode(int key, int val);
	void removeNode(DListNode *);
	DListNode * eviction();
	void moveNode(int key);
	int get(int key);
	void put(int key, int value);
	void solve();
	void fillInput();
};


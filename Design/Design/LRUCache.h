#pragma once
#include "Solution.h"

class ListNode
{
public:
	int key;
	int val;
	ListNode* next;
	ListNode* prev;
	ListNode(int k, int v) :key(k), val(v), next(NULL), prev(NULL) {}
	ListNode() :key(0), val(0), next(NULL), prev(NULL){}
};

class LRUCache :
	public Solution
{
	int capacity;
	int size;
	ListNode* head;
	ListNode* tail;
	map<int, ListNode*> ref;
	vector<string> queries;
	vector<vector<int>> data;
public:
	LRUCache();    
	LRUCache(int capacity);
	void setCapacity(int capacity);
	void addNode(int key, int val);
	ListNode* removeNode();
	void moveNode(int key);
	int get(int key);
	void put(int key, int value);
	void solve();
	void fillInput();
};

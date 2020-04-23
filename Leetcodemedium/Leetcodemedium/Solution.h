#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class MaxHeap
{
	vector<int> data;
	void heapify(int index);
	void swap(int i, int j);
public:
	MaxHeap() {};
	int size() { return data.size(); }
	void insert(int ele);
	void removeMax();
	int top();
	void init(vector<int> nums);
};

class MinHeap
{
	vector<int> data;
	void heapify(int index);
	void swap(int i, int j);
public:
	MinHeap() {};
	int size() { return data.size(); }
	void insert(int ele);
	void removeMin();
	int top();
	void init(vector<int> nums);
};

class Solution
{

public:
	ifstream file;
	Solution();
	string getNextLine();
	virtual void solve() = 0;
	virtual void fillInput() = 0;
	string getString();
	void get2DStrings(vector<vector<string>>& array);
	void getCharArray(vector<char>& array);
	void getStrings(vector<string>& array);
	int getInt();
	void get2Darray(vector<vector<int>>& array);
	void getIntArray(vector<int>& array);
	void getBinaryTree(TreeNode ** root);
};




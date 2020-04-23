#pragma once
#include "Solution.h"

class AVLNode
{
	int val;
	AVLNode *left;
	AVLNode *right;
	int nodeCount;
	int hight;
public:
	AVLNode():left(NULL), right(NULL), hight(0), nodeCount(1){}
	AVLNode *insertElement(int Element, int &count);
	AVLNode *leftRotate();
	AVLNode *rightRotate();
	AVLNode * adjustHight(int & balance, int ele);
	void setVal(int ele) { val = ele; }
};

class CountLessAfterSelf :
	public Solution
{
	vector<int> nums;
	AVLNode *root;
public:
	CountLessAfterSelf();
	void solve();
	vector<int> countSmaller(vector<int>& nums);
	void fillInput();
};


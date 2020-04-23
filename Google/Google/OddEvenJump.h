#pragma once
#include "Solution.h"
class BSTNode
{
public:
	int val;
	BSTNode* left;
	BSTNode* right;
	BSTNode* middle;
	int pos;
	int rightMax;
	int rightMin;
	BSTNode() :val(-1), left(NULL), right(NULL), pos(-1), rightMax(-1), rightMin(-1) {}
	BSTNode(int v, int p) :val(v), left(NULL), right(NULL), pos(p), rightMax(-1), rightMin(-1) {}
};

class OddEvenJump :
	public Solution
{
	vector<int> nums;
public:
	OddEvenJump();
	BSTNode * insertInBST(BSTNode * root, vector<int>& A, int pos, unordered_map<int, BSTNode*>& data, int rMax, int rMin);
	BSTNode * insertInBST2(BSTNode * root, vector<int>& A, int pos, unordered_map<int, BSTNode*>& data, int rMax, int rMin);
	bool isPossible(unordered_map<int, BSTNode*>& data, int startPos, int endPos, int evenOdd);
	int oddEvenJumps(vector<int>& A);
	void solve();
	void fillInput();
};


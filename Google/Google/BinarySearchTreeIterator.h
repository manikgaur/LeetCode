#pragma once
#include "Solution.h"
class BinarySearchTreeIterator :
	public Solution
{
	int maxWidth;
	vector<string> words;
public:
	BinarySearchTreeIterator();
	BinarySearchTreeIterator(TreeNode* root);
	int next();
	void solve();
	void fillInput();
};


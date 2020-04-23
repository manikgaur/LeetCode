#pragma once
#include "Solution.h"


class SumEvenGrandParents :
	public Solution
{
public:
	TreeNode *root;
	SumEvenGrandParents();
	void solve();
	void fillInput();
	int sumEvenGrandparent(TreeNode* root);
	int DFS(TreeNode *root, int retSum);
};


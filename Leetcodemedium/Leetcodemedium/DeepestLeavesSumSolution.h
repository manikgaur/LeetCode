#pragma once
#include "Solution.h"



class DeepestLeavesSumSolution :
	public Solution
{
public:
	TreeNode *root;
	DeepestLeavesSumSolution();
	void solve();
	void fillInput();
	int deepestLeavesSum(TreeNode* root);
	int DFS(TreeNode *root, int &deepestLevel, int currentLevel);
};



#pragma once
#include "Solution.h"
#include <vector>
class PathSum :
	public Solution
{
public:
	TreeNode *root;
	int sum;
	PathSum();
	void solve();
	void fillInput();
	vector<vector<int>> pathSum(TreeNode* root, int sum);
	int DFS(TreeNode *root, int sum, int currentSum, vector<int> &traverse, vector<vector<int>> &result);
};


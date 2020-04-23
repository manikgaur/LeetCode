#pragma once
#include "Solution.h"
class BTFromInPre :
	public Solution
{
	vector<int> pre;
	vector<int> inorder;
public:
	BTFromInPre();
	void solve();
	int findIndex(vector<int> &inorder, int ele, int start, int end);
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int index, int start, int end);
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
	void fillInput();
};


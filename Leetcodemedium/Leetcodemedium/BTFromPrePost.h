#pragma once
#include "Solution.h"
class BTFromPrePost :
	public Solution
{
	vector<int> pre;
	vector<int> post;
	map<int, bool> visited;
public:
	BTFromPrePost();
	void solve();
	int findElement(vector<int> p, int ele, int index);
	TreeNode* construct(vector<int>& pre, vector<int>& post, int i, int j);
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post);
	void fillInput();
};


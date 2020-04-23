#pragma once
#include "Solution.h"
class SegmentTreeApplication :
	public Solution
{
	int L;
	int R;
	TreeNode* root;
	vector<string> queries;
	vector<vector<int>> qData;
	vector<int> nums;
	vector<int>STData;
public:
	SegmentTreeApplication();
	int rangeSumBST(TreeNode* root, int L, int R);
	void NumArray(vector<int>& nums);
	void update(int i, int val);
	int sumRange(int i, int j);
	void solve();
	int countRangeSum(vector<int>& nums, int lower, int upper);
	void fillInput();
};


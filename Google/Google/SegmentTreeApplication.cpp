#include "SegmentTreeApplication.h"

SegmentTreeApplication::SegmentTreeApplication()
{
	file.open("SegmentTreeApplicationInput.txt");
}

int findSumBST(TreeNode * root, int L, int R)
{
	if (root == NULL)
		return 0;

	int sum = 0;
	sum += findSumBST(root->left, L, R);
	if (root->val <= R && root->val >= L)
		sum += root->val;
	sum += findSumBST(root->right, L, R);
}

int SegmentTreeApplication::rangeSumBST(TreeNode * root, int L, int R)
{
	int sum = 0;
	return findSumBST(root, min(L,R), max(L, R));
}

int createSegmentTree(vector<int>& STData, int s, int e, int pos, vector<int>& nums)
{
	if (s == e) {
		STData[pos] = nums[s];
		return nums[s];
	}
	
	int mid = s + ((e - s) / 2);
	int sum = 0;
	sum += createSegmentTree(STData, s, mid, (pos * 2) + 1, nums);
	sum += createSegmentTree(STData, mid + 1, e, (pos * 2) + 2, nums);
	STData[pos] = sum;
	return sum;
}

void SegmentTreeApplication::NumArray(vector<int>& nums) {
	int size = nums.size();
	STData = vector<int>(size * 2);
	for (int i = 0; i < nums.size(); i++) {
		STData[i + size] = nums[i];
	}
	for (int i = size - 1; i > 0; i--) {
		STData[i] = STData[i << 1] + STData[i << 1 | 1];
	}
}

void SegmentTreeApplication::update(int i, int val) {
	if (i >= STData.size() / 2)
		return;
	int size = nums.size();
	int value = val - STData[size + i];
	STData[size + i] += value;
	size = size + i;
	while (size = size >> 1) {
		STData[size] += value;
	}
}

int SegmentTreeApplication::sumRange(int i, int j) {
	int res = 0;
	int n = nums.size();
	if (i >= n)
		return 0;
	if (j >= n)
		j = n - 1;
	// loop to find the sum in the range 
	for (i += n, j += n; i <= j; i >>= 1, j >>= 1)
	{
		if (i & 1)
			res += STData[i++];

		if (!(j & 1))
			res += STData[j--];
	}

	return res;
}

int countWithMergeSort(vector<int>& nums, int s, int e, int lower, int upper)
{
	if (e - s <= 1) {
		return 0;
	}
	int mid = s + (e - s) / 2;
	int count = 0;
	count = countWithMergeSort(nums, s, mid, lower, upper) + 
		countWithMergeSort(nums, mid, e, lower, upper);
	vector<int> tmp;
	for (int i = s; i < mid; i++)
	{
		int j = mid;
		int k = mid;
		while(j < e && nums[j] - nums[i] < lower) j++;
		while (k < e && nums[k] - nums[i] < lower) k++;
		count += k - j;
		for (j = mid; j < e && nums[j] < nums[i]; j++)
		{
			tmp.push_back(nums[j]);
		}
		tmp.push_back(nums[i]);
	}
	copy(tmp.begin(), tmp.end(), nums.begin() + s);
	return count;
}

int SegmentTreeApplication::countRangeSum(vector<int>& nums, int lower, int upper)
{
	vector<int> sums(nums.size() + 1);
	for (int i = 0; i < nums.size(); i++) {
		sums[i+1] = nums[i] + sums[i];
	}
	return countWithMergeSort(sums, 0, sums.size(), lower, upper);
}

void SegmentTreeApplication::solve()
{
	fillInput();
	cout << countRangeSum(nums, L, R);
	return;
/*	rangeSumBST(root, L, R);*/
//	NumArray(nums);
//	update(1, 7);
/*	for (int i = 0; i < queries.size(); i++) {
		if (queries[i] == "sumRange") {
			cout <<sumRange(qData[i][0], qData[i][1]);
		}
		if (queries[i] == "update") {
			update(qData[i][0], qData[i][1]);
		}
	}*/
}

void SegmentTreeApplication::fillInput()
{
/*	getBinaryTree(&root);
	L = getInt();
	R = getInt();
	*/

//	getStrings(queries);
	getIntArray(nums);
	L = getInt();
	R = getInt();
//	get2Darray(qData);

}

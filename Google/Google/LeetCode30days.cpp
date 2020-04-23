#include "LeetCode30days.h"

LeetCode30days::LeetCode30days()
{
	file.open("LeetCode30daysInput.txt");
}

int findMaxSumSubArrayfull(vector<int>& nums, int s, int m, int e)
{
	int sum = 0;
	int leftSum = INT_MIN;

	for (int i = m; i >= s; i--)
	{
		sum += nums[i];
		if (leftSum < sum)
			leftSum = sum;
	}
	sum = 0;
	int rightSum = INT_MIN;

	for (int i = m+1; i <= e; i++)
	{
		sum += nums[i];
		if (rightSum < sum)
			rightSum = sum;
	}

	return leftSum + rightSum;
}

int findMaxSumSubArray(vector<int>& nums, int s, int e)
{
	if (s == e)
		return nums[s];

	int mid = s + (e - s) / 2;
	return max(max(findMaxSumSubArray(nums, mid + 1, e), findMaxSumSubArray(nums, s, mid)),
		   findMaxSumSubArrayfull(nums, s, mid, e));
}

int LeetCode30days::maxSubArray(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];

	return findMaxSumSubArray(nums, 0, nums.size() - 1);
}

void LeetCode30days::solve()
{
	fillInput();
	cout << maxSubArray(nums);
	return;
}

void LeetCode30days::fillInput()
{
	getIntArray(nums);
}

#include "SplitConsecutiveSubsequences.h"

SplitConsecutiveSubsequences::SplitConsecutiveSubsequences()
{
	file.open("SplitConsecutiveSubsequencesInput.txt");
}

bool SplitConsecutiveSubsequences::isPossible(vector<int>& nums)
{
	priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 1, nums[0] });
	for (int i = 1; i < nums.size(); i++)
	{
		int ele = nums[i];
		pair<int, int> p = pq.top();
		if (p.second == nums[i] - 1) {
			pq.pop();
			p.first++;
			p.second = nums[i];
			pq.push(p);
		}
		else
		{
			if (p.second < 3)
				return false;
			pq.push({1, nums[i]});
			continue;
		}
	}
	return true;
}

void SplitConsecutiveSubsequences::solve()
{
	fillInput();
	cout << isPossible(nums);
	return;
}

void SplitConsecutiveSubsequences::fillInput()
{
	getIntArray(nums);
}

#include "SplitArrayLargestSum.h"

SplitArrayLargestSum::SplitArrayLargestSum()
{
	file.open("splitArrayLargestSumInput.txt");
}

void SplitArrayLargestSum::solve()
{
	fillInput();
	cout << splitArray(nums, m);
	return;
}
// find the lower bound and upperbound
// do binary search if that can fit in between
int SplitArrayLargestSum::splitArray(vector<int>& nums, int m)
{
	int lo = 0;
	unsigned int hi = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (lo < nums[i])
			lo = nums[i];
		hi += nums[i];
	}
	if (m == 1)
		return hi;
	if (m = nums.size())
		return lo;

	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		int splits = findMax(nums, mid);
		if (splits > m) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}

	return lo;
}

int SplitArrayLargestSum::findMax(vector<int> &nums, int sum)
{
	int split = 1;
	unsigned int total = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (total + nums[i] > sum) {
			split++;
			total = nums[i];
		}
		else total += nums[i];
	}
	return split;
}

void SplitArrayLargestSum::fillInput()
{
	string line = getNextLine();
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			nums.push_back(stoi(tmp));
		}
	}
	line = getNextLine();
	m = stoi(line);
}

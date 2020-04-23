#include "KSmallestPairDistance.h"

KSmallestPairDistance::KSmallestPairDistance()
{
	file.open("KSmallestPairDistanceInput.txt");
}

void KSmallestPairDistance::solve()
{
	fillInput();
	cout << smallestDistancePair(nums, m);
	return;
}

int countPairs(vector<int>& nums, int mid)
{
	int res = 0;
	for (int i = 0; i < nums.size(); ++i)
		res += upper_bound(nums.begin() + i, nums.end(), nums[i] + mid) -
		(nums.begin() + i + 1);
	return res;
}
// sort the numbers O(nlogn)
// create a max heap O(klogn)
// find k smallest O(kn)
int KSmallestPairDistance::smallestDistancePair(vector<int>& nums, int k)
{
	//MaxHeap heap;
	sort(nums.begin(), nums.end());
	int low = nums[1] - nums[0];
	for (int i = 1; i < nums.size()-1; ++i)
		low = min(low, nums[i + 1] - nums[i]);

	// Maximum absolute difference 
	int high = nums[nums.size() - 1] - nums[0];

	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (countPairs(nums, mid) < k)
			low = mid + 1;
		else
			high = mid;
	}

	return low;

/*
	int inserted = 1;
	for (int i = 1; i < nums.size()-1 && inserted; i++) {
		inserted = 0;
		for (int j = 0; j < nums.size()-i; j++) {
			int diff = nums[j+i] - nums[j];
			if (heap.size() < k) {
				heap.insert(diff);
				inserted = 1;
			}
			else {
				int max = heap.top();
				if (diff < max) {
					heap.removeMax();
					heap.insert(diff);
					inserted = 1;
				}
			}
		}
	}

	return heap.top();
*/
}

void KSmallestPairDistance::fillInput()
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



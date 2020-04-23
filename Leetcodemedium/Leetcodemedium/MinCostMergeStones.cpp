#include "MinCostMergeStones.h"

MinCostMergeStones::MinCostMergeStones()
{
	file.open("MinCostMergeStonesInput.txt");
}

int MinCostMergeStones::mergeKstones(vector<int>& stones, vector<int>& sumArray, int K, int s, int e)
{
	if (s == e)
		return 0;
	if (data[s][e] != -1)
		return data[s][e];
	int lSum = 0;
	int rSum = 0;
	int sum = INT_MAX;
	for (int i = s; i < e; i += K-1) {
		lSum = mergeKstones(stones, sumArray, K, s, i);
		rSum = mergeKstones(stones, sumArray, K, i+1, e);
		if (sum > lSum + rSum)
			sum = lSum + rSum;
	}

	if ((e - s) % (K - 1) == 0) sum += sumArray[e + 1] - sumArray[s];
	data[s][e] = sum;
	return sum;
}

int MinCostMergeStones::mergeStones(vector<int>& stones, int K)
{
	if ((stones.size()-1) % (K - 1) != 0)
		return -1;
	int n = stones.size();
	data = vector<vector<int>>(n, vector<int>(n, -1));
	vector<int> sumArray(stones.size() + 1);
	sumArray[0] = 0;
	for (int i = 0; i < stones.size(); i++)
	{
		sumArray[i+1] = stones[i] + sumArray[i];
	}
	return mergeKstones(stones, sumArray, K, 0, stones.size() - 1);
}

void MinCostMergeStones::solve()
{
	fillInput();
	cout << mergeStones(stones, K);
	return;
}

void MinCostMergeStones::fillInput()
{
	string line = getNextLine();
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			stones.push_back(stoi(tmp));
		}
	}
	line = getNextLine();
	K = stoi(line);
}

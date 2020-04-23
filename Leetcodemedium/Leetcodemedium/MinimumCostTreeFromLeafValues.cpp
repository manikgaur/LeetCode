#include "MinimumCostTreeFromLeafValues.h"

MinimumCostTreeFromLeafValues::MinimumCostTreeFromLeafValues():
	data(vector<vector<values>>(40, vector<values>(40)))
{	
	file.open("MinimumCostTreeFromLeafValuesInput.txt");
}

void MinimumCostTreeFromLeafValues::solve()
{
	fillInput();
	cout << mctFromLeafValues(nums);
	return;
}

int MinimumCostTreeFromLeafValues::minCost(vector<int>& arr, int start, int end, int &max)
{
	int mincost = INT_MAX;

	if (data[start][end].visited) {
		max = data[start][end].max;
		return data[start][end].cost;
	}

	if (start == end) {
		data[start][end].max = arr[start];
		data[start][end].cost = 0;
		data[start][end].visited = true;
		max = arr[start];
		return 0;
	}

	for (int i = start + 1; i <= end; i++) {
		int maxL = 0;
		int maxR = 0;
		int minLeft = minCost(arr, start, i-1, maxL);
		int minRight = minCost(arr, i, end, maxR);
		int cost = minLeft + minRight + (maxL * maxR);
		if (mincost > cost) {
			mincost = cost;
			max = std::max(maxL, maxR);
			data[start][end].max = max;
			data[start][end].cost = mincost;
			data[start][end].visited = true;
		}
	}

	return mincost;
}

int MinimumCostTreeFromLeafValues::minCostDP(vector<int>& arr) {
	if (arr.size() <= 1)
		return 0;
	int size = arr.size();
	for (int k = 0; k < size; k++) {
		data[k][k].max = arr[k];
		data[k][k].cost = 0;
	}
	for (int k = 2; k <= size; k++) {
		for (int r = 0; r < size - k + 1; r++) {
			int c = r + k - 1;

			cout << r << "," << c << endl;

			int mincost = INT_MAX;
			for (int sep = r + 1; sep <= c; sep++) {
				int minLeft = data[r][sep - 1].cost;
				int minRight = data[sep][c].cost;
				int maxL = data[r][sep - 1].max;
				int maxR = data[sep][c].max;
				int cost = minLeft + minRight + (maxL * maxR);
				if (mincost > cost) {
					mincost = cost;
					data[r][c].max = std::max(maxL, maxR);
					data[r][c].cost = mincost;
					data[r][c].visited = true;
				}
			}

		}
	}
	return data[0][size - 1].cost;

}

int MinimumCostTreeFromLeafValues::mctFromLeafValues(vector<int>& arr)
{
	data = vector<vector<values>>(40, vector<values>(40));
	int max = 0;
	//return minCost(arr, 0, arr.size()-1, max);
	return minCostDP(arr);
}

void MinimumCostTreeFromLeafValues::fillInput()
{
	string line = getNextLine();
	std::stringstream s(line);
	string tmp;
	while (getline(s, tmp, ','))
	{
		nums.push_back(stoi(tmp));
	}
}

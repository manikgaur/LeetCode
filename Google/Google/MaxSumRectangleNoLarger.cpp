#include "MaxSumRectangleNoLarger.h"

MaxSumRectangleNoLarger::MaxSumRectangleNoLarger()
{
	file.open("MaxSumRectangleNoLargerInput.txt");
}

int MaxSumRectangleNoLarger::maxSumSubmatrix(vector<vector<int>>& matrix, int k)
{
	int R = matrix.size() + 1;
	int C = matrix[0].size() + 1;

	vector<vector<int>> data = vector<vector<int>>(R, vector<int>(C, 0));

	for (int i = 1; i < R; i++) {
		for (int j = 1; j < C; j++) {
			data[i][j] = matrix[i - 1][j - 1];
			data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
		}
	}

	int max = INT_MIN;
	for (int i = 1; i < C; i++) {
		for (int j = i; j < C; j++) {
			set<int> cache;
			cache.insert(0);
			for (int r = 1; r < R; r++) {
				int currSum = data[r][j] - data[r][i - 1];
				if (currSum == k)
					return k;
				else {
					set<int>::iterator it = cache.lower_bound(currSum - k);
					if (it != cache.end()) {
						max = std::max(max, currSum - *it);
					}
				}
				cache.insert(currSum);
			}
		}
	}

	return max == INT_MIN ? -1 : max;
}

void MaxSumRectangleNoLarger::solve()
{
	fillInput();
	cout << maxSumSubmatrix(matrix, K);
	return;
}

void MaxSumRectangleNoLarger::fillInput()
{
	get2Darray(matrix);
	K = getInt();
}

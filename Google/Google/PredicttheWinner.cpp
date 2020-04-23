#include "PredicttheWinner.h"

PredicttheWinner::PredicttheWinner()
{
	file.open("PredicttheWinnerInput.txt");
}

int countMax(vector<int>& nums, vector<int>& sums, vector<vector<int>>& data, int s, int e)
{
	if (s == e)
		return 0;
	if (data[s][e] != -1)
		return data[s][e];
	int count = 0;
	count = max(count, nums[s] + countMax(nums, sums, data, s + 1, e));
	count = max(count, nums[e] + countMax(nums, sums, data, s, e - 1));
	data[s][e] = sums[e + 1] - sums[s] - count;
	return data[s][e];
}

bool PredicttheWinner::PredictTheWinner(vector<int>& nums)
{
	vector<vector<int>> data(nums.size(), vector<int>(nums.size(), -1));
	vector<int> sums(nums.size() + 1, 0);
	for (int i = 0; i < nums.size(); i++)
	{
		sums[i + 1] = nums[i] + sums[i];
	}
	int total = countMax(nums, sums, data, 0, nums.size() - 1);

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			cout << data[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;

	if (sums[nums.size()] - total > total)
		return true;
	return false;
}
bool PredicttheWinner::PredictTheWinner2(vector<int>& nums)
{
	if (nums.size() < 3)
		return true;

	vector<vector<int>> data(nums.size(), vector<int>(nums.size(), -1));
	vector<int> sums(nums.size() + 1, 0);
	for (int i = 0; i < nums.size(); i++)
	{
		sums[i + 1] = nums[i] + sums[i];
	}
	for (int i = 0; i < nums.size(); i++)
	{
		data[i][i] = 0;
	}
	int size = nums.size();
	for (int k = 1; k < size; k++)
	{
		for (int i = 0; i < size - k; i++) {
			int j = i + k;
			data[i][j] = sums[j + 1] - sums[i] - max(nums[i] + data[i + 1][j], nums[j] + data[i][j - 1]);
		}
	}
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			cout << data[i][j] << ", ";
		}
		cout << endl;
	}
	if (sums[nums.size()] - data[0][size - 1] >= data[0][size - 1])
		return true;
	return false;
}

void PredicttheWinner::solve()
{
	fillInput();
	cout << PredictTheWinner2(nums);
	return;
}

void PredicttheWinner::fillInput()
{
	getIntArray(nums);
}

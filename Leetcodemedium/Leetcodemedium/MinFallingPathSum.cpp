#include "MinFallingPathSum.h"

MinFallingPathSum::MinFallingPathSum()
{
	file.open("MinFallingPathSum.txt");
}

int MinFallingPathSum::minFallingPathSum2(vector<vector<int>>& arr) {

	vector<vector<int>> data(arr.size() + 1, vector<int>(arr[0].size() + 2, 20000));

	for (int i = 1; i <= arr.size(); i++) {
		for (int j = 1; j <= arr[0].size(); j++) {
			data[i][j] = arr[i - 1][j - 1];
		}
	}
	for (int j = 0; j <= arr[0].size(); j++) {
		data[0][j] = 0;
	}

	for (int i = 1; i <= arr.size(); i++) {
		for (int j = 1; j <= arr[0].size(); j++) {
			int m = min(arr[i - 1][j - 1], arr[i - 1][j]);
			m = min(m, arr[i - 1][j + 1]);
			data[i][j] += m;
		}
	}
	int minEle = INT_MAX;
	int r = arr.size();
	for (int j = 1; j <= arr[0].size(); j++) {
		if (arr[r][j] < minEle)
			minEle = arr[r][j];
	}
	return minEle;
}

int MinFallingPathSum::minFallingPathSum(vector<vector<int>>& arr)
{
	int r = arr.size();
	int c = arr[0].size();
	int min1 = 0;
	int min2 = 1;
	for (int i = 0; i < r; i++) {
		arr[i].push_back(20000);
	}
	arr.push_back(vector<int>(c));
	for (r = r-1; r >= 0; r--) {
		int minf = c;
		int mins = c;
		for (int j = 0; j < c; j++) {
			if (j == min1)
				arr[r][j] += arr[r + 1][min2];
			else
				arr[r][j] += arr[r + 1][min1];
			if (j == 0) {
				minf = j;
			}
			else if (arr[r][minf] > arr[r][j]) {
				mins = minf;
				minf = j;				
			}
			else if (arr[r][mins] > arr[r][j]) {
				mins = j;
			}
		}
		cout << arr[r][minf] << "," << arr[r][mins] << endl;
		min1 = minf;
		min2 = mins;
	}
	return arr[0][min1];
}

void MinFallingPathSum::solve()
{
	fillInput();
	minFallingPathSum2(arr);
	return;
}

void MinFallingPathSum::fillInput()
{
	string line = getNextLine();
	line.erase(std::remove(line.begin(), line.end(), '['), line.end());

	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		int i = 0;
		while (getline(s, tmp, ']'))
		{
			vector<int> vRow;
			if (tmp.length()) {
				std::stringstream row(tmp);
				while (getline(row, tmp, ','))
				{
					if (tmp.length())
						vRow.push_back(stoi(tmp));
				}
				arr.push_back(vRow);
			}
			i++;
		}
	}
}

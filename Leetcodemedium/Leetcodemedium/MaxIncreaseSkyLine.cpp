#include "MaxIncreaseSkyLine.h"
#include <vector>
#include <sstream>
#include <algorithm>

void MaxIncreaseSkyLine::fillInput()
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
					if(tmp.length())
						vRow.push_back(stoi(tmp));
				}
				data.push_back(vRow);
			}			
			i++;
		}
	}
}

int MaxIncreaseSkyLine::maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
	int row = grid.size();
	int col = grid[0].size();
	for (int i = 0; i < row; i++) {
		int max = 0;
		for (int j = 0; j < col; j++) {
			if (grid[i][j] > max)
				max = grid[i][j];
		}
		grid[i].push_back(max);
	}
	vector<int> maxRow;
	for (int i = 0; i < col; i++) {
		int max = 0;
		for (int j = 0; j < row; j++) {
			if (grid[j][i] > max)
				max = grid[j][i];
		}
		maxRow.push_back(max);
	}
	grid.push_back(maxRow);
	int total = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			total += grid[i][col] < grid[row][j] ? grid[i][row] - grid[i][j] : grid[col][j] - grid[i][j];
		}
	}


	return total;
}


MaxIncreaseSkyLine::MaxIncreaseSkyLine()
{
	file.open("maxIncreaseSkyLineInput.txt");
}

void MaxIncreaseSkyLine::solve()
{
	fillInput();
	maxIncreaseKeepingSkyline(data);
}
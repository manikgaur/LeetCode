#include "MaximalSquare.h"

MaximalSquare::MaximalSquare()
{
	file.open("maximalSquareInput.txt");
}

void MaximalSquare::solve()
{
	fillInput();
	maximalSquare(matrix);
}

int MaximalSquare::maximalSquare(vector<vector<char>>& matrix)
{
	int max = 0;
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] = matrix[i][j] - '0';
			if (matrix[i][j] == 1)
				max = 1;
		}
	for (int i = 1; i < matrix.size(); i++)
		for (int j = 1; j < matrix[i].size(); j++) {
			int min = matrix.size();
			if (min > matrix[i - 1][j - 1])
				min = matrix[i - 1][j - 1];
			if (min > matrix[i - 1][j])
				min = matrix[i - 1][j];
			if (min > matrix[i][j - 1])
				min = matrix[i][j - 1];
			if (matrix[i][j])
				matrix[i][j] = min + 1;
			if (max < matrix[i][j])
				max = matrix[i][j];
		}
	return max * max;
}

void MaximalSquare::fillInput()
{
	string line;
	while (!(line = getNextLine()).empty()) {
		std::stringstream s(line);
		string tmp;
		vector<char> row;
		while (getline(s, tmp, ' '))
		{
			row.push_back(tmp[0]);
		}
		matrix.push_back(row);
	}
}

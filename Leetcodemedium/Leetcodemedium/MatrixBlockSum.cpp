#include "MatrixBlockSum.h"

MatrixBlockSum::MatrixBlockSum()
{
	file.open("MatrixBlockSumInput.txt");
}

void MatrixBlockSum::solve()
{
	fillInput();
	//matrixBlockSum(mat, K);
	numSubmatrixSumTarget(mat, K);
	return;
}

int MatrixBlockSum::findSum(vector<vector<int>>& data, int xi, int xj, int yi, int yj) {
	return data[yi][yj] + data[xi-1][xj-1] - data[xi-1][yj] - data[yi][xj-1];
}
vector<vector<int>> MatrixBlockSum::matrixBlockSum(vector<vector<int>>& mat, int K)
{
	int m = mat.size();
	int n = mat[0].size();
	vector<vector<int>> data(m + 1, vector<int>(n + 1));
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			data[i + 1][j + 1] += mat[i][j] + data[i + 1][j] + data[i][j + 1] - data[i][j];
		}
	}

	int xi, xj, yi, yj;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			xi = i - K < 1 ? 1 : i - K;
			xj = j - K < 1 ? 1 : j - K;
			yi = i + K > m ? m : i + K;
			yj = j + K > n ? n : j + K;
			mat[i-1][j-1] = data[yi][yj] + data[xi - 1][xj - 1] - data[xi - 1][yj] - data[yi][xj - 1];

		}
	}
	return mat;
}

int MatrixBlockSum::numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
{
	int m = mat.size();
	int n = mat[0].size();
	vector<vector<int>> data(m + 1, vector<int>(n + 1));
	int count = 0;
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			data[i + 1][j + 1] += mat[i][j] + data[i + 1][j] + data[i][j + 1] - data[i][j];
		}
	}
	for (int xi = 1; xi <= m; xi++)
	{
		for (int yi = xi; yi <= m; yi++)
		{
			map<int, int> preVals;
			for (int yj = 1; yj <= n; yj++)
			{
				int sum = data[yi][yj] - data[xi - 1][yj];
				
				if (sum == target)
					count++;
				map<int, int>::iterator it = preVals.find(sum - target);
				if (it != preVals.end())
					count += preVals[sum - target];
				preVals[sum]++;
			}
		}
	}

	return count;
}


void MatrixBlockSum::fillInput()
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
				mat.push_back(vRow);
			}
			i++;
		}
	}
	line = getNextLine();
	K = stoi(line);
}

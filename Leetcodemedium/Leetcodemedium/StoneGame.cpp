#include "StoneGame.h"



StoneGame::StoneGame()
{
	file.open("StoneGameInput.txt");
}

bool StoneGame::game(vector<int> &piles, int start, int end) {
	if (data[start][end].visited) {
		return data[start][end].win;
	}
	if (start == end) {
		data[start][end].win = true;
		data[start][end].winCount = piles[start];
		data[start][end].visited = true;
		return true;
	}
	int wCountf = 0;
	int lCountf = 0;
	int wCounts = 0;
	int lCounts = 0;
	bool fWin = false;
	bool sWin = false;

	game(piles, start + 1, end);
	if (data[start + 1][end].win) {
		lCountf = data[start + 1][end].lostCount + piles[start];
		wCountf = data[start + 1][end].winCount;
		if (lCountf >= wCountf) {
			int tmp = wCountf; wCountf = lCountf; lCountf = tmp;
			fWin = true;
		}
	}
	else {
		wCountf = data[start + 1][end].winCount + piles[start];
		lCountf = data[start + 1][end].lostCount;
		fWin = true;
	}
	game(piles, start, end - 1);
	if (data[start][end-1].win) {
		lCounts = data[start][end - 1].lostCount + piles[end];
		wCounts = data[start][end - 1].winCount;
		if (lCounts >= wCounts) {
			int tmp = wCounts; wCounts = lCounts; lCounts = tmp;
			sWin = true;
		}
	}
	else {
		wCounts = data[start][end - 1].winCount += piles[end];
		lCounts = data[start][end - 1].lostCount;
		sWin = true;
	}

	if (fWin && sWin) {
		data[start][end].winCount = wCountf > wCounts ? wCountf : wCounts;
		data[start][end].lostCount = wCountf > wCounts ? lCountf : lCounts;
		data[start][end].win = true;
	}
	else if (fWin || sWin) {
		data[start][end].winCount = fWin ? wCountf : wCounts;
		data[start][end].lostCount = fWin ? lCountf : lCounts;
		data[start][end].win = true;
	}
	else {
		data[start][end].winCount = wCountf > wCounts ? wCountf : wCounts;
		data[start][end].lostCount = wCountf > wCounts ? lCountf : lCounts;
	}
	data[start][end].visited = true;
	cout << start << "-" << end << " : " << data[start][end].winCount << "," << data[start][end].lostCount << "," << data[start][end].win << endl;
	return data[start][end].win;
}

bool StoneGame::stoneGame(vector<int>& piles)
{
	data = vector<vector<Results>>(500, vector<Results>(500));	
	return game(piles, 0, piles.size() - 1);
}

int StoneGame::maxStones(vector<int>& piles, int start, int end, int M) {
	if (dataII[start][end][M] != -1)
		return dataII[start][end][M];
	if (2 * M >= end - start + 1)
		return piles[end] - piles[start - 1];

	int count = 0;
	int maxCount = 0;

	for (int i = 1; i <= M * 2; i++) {
		count = (piles[end] - piles[start-1]) - maxStones(piles, start + i, end, max(M,i));
		cout << start << "," << i << "," << end << ":" << count << endl;
		if (maxCount < count) {
			maxCount = count;
			dataII[start][end][M] = maxCount;
		}
	}

	return maxCount;
}
int StoneGame::stoneGameII(vector<int>& piles)
{
	vector<int> p(piles.size() + 1);
	p[0] = 0;
	for (int i = 1; i <= piles.size(); i++) {
		p[i] = p[i - 1] + piles[i - 1];
	}
	dataII = vector<vector<vector<int>>>(101, vector<vector<int>>(101, vector<int>(101, -1)));
	return maxStones(p, 1, piles.size(), 1);
}


void StoneGame::solve()
{
	fillInput();
//	cout << stoneGame(arr);
	cout << stoneGameII(arr);
	return;
}

void StoneGame::fillInput()
{
	string line = getNextLine();
	vector<int> data;
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			arr.push_back(stoi(tmp));
		}
	}
}

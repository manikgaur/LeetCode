#include "DivisorGame.h"

DivisorGame::DivisorGame()
{
	data = vector<bool>(1000);
	file.open("DivisorGameInput.txt");
}

void DivisorGame::solve()
{
	fillInput();
	int i = 1;
	cout << divisorGame(33);
	return;
}

bool DivisorGame::divisorGame(int N)
{
	if (N <= 1)
		return false;
	if (data[N])
		return data[N];

	for (int i = 1; i <= sqrt(N); i++)
	{
		if (N%i == 0)
		{
			if (!divisorGame(N - i)) {
				data[N] = true;
				return true;
			}
			if (N / i != i && N / i != N) {
				if (!divisorGame(N - (N / i))) {
					data[N] = true;
					return true;
				}
			}
		}
	}
	data[N] = false;
	return false;
}

void DivisorGame::fillInput()
{
	string line = getNextLine();
	N = stoi(line);
}

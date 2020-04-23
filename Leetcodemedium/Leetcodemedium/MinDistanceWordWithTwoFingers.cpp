#include "MinDistanceWordWithTwoFingers.h"

MinDistanceWordWithTwoFingers::MinDistanceWordWithTwoFingers()
{
	file.open("MinDistanceWordWithTwoFingersInput.txt");
}

int MinDistanceWordWithTwoFingers::distance(int p1, int p2)
{
	if (p1 == 500 || p2 == 500)
		return 0;

	int id1 = word[p1] - 'A';
	int id2 = word[p2] - 'A';
	int r1 = id1 / 6;
	int c1 = id1 % 6;

	int r2 = id2 / 6;
	int c2 = id2 % 6;

	return abs(r1 - r2) + abs(c1 - c2);
}

int MinDistanceWordWithTwoFingers::minimumDistancefromIndex(string& word, int index, int p1, int p2)
{
	if (index == word.length())
		return 0;
	unsigned int hashVal = (index << 16) + (p1 << 8) + p2;

	if (cache.find(hashVal) != cache.end())
		return cache[hashVal];

	int total1 = distance(index, p1) + minimumDistancefromIndex(word, index + 1, index, p2);
	int total2 = distance(index, p2) + minimumDistancefromIndex(word, index + 1, p1, index);
	int minDist = min(total1, total2);

	cache[hashVal] = minDist;
	return minDist;
}

int MinDistanceWordWithTwoFingers::minimumDistance(string word)
{
	if (word.length() < 3)
		return 0;
	cache = unordered_map<unsigned int, int>();
	return minimumDistancefromIndex(word, 1, 0, 500);
}

void MinDistanceWordWithTwoFingers::solve()
{
	fillInput();
	cout << minimumDistance(word);
	return;
}

void MinDistanceWordWithTwoFingers::fillInput()
{
	word = getString();
}

#pragma once
#include "Solution.h"
#include <unordered_map>
class keyPos
{
	int x;
	int y;
public:
	keyPos() :x(0), y(0) {}
	keyPos(int i, int j):x(i), y(j){}
	static int getDistance(keyPos &p1, keyPos &p2)
	{
		return abs(abs(p1.x - p2.x) + abs(p1.y - p2.y));
	}
};
class MinDistanceWordWithTwoFingers :
	public Solution
{
	string word;
	unordered_map<unsigned int, int> cache;
public:
	MinDistanceWordWithTwoFingers();
	int distance(int p1, int p2);
	int minimumDistancefromIndex(string& word, int index, int p1, int p2);
	int minimumDistance(string word);
	void solve();
	void fillInput();
};


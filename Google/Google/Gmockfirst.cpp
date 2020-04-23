#include "Gmockfirst.h"

Gmockfirst::Gmockfirst()
{
	file.open("GmockfirstInput.txt");
}

int Gmockfirst::heightChecker(vector<int>& heights)
{
	if (heights.size() < 2)
		return 0;
	map<int, int> hCnt;
	vector<int> output(heights.size() + 1);
	for (auto i : heights) {
		hCnt[i]++;
	}
	map<int, int>::iterator it1, it2;
	it1 = it2 = hCnt.begin();
	it2++;
	while (it2 != hCnt.end())
	{
		it2->second += it1->second;
		it1++;
		it2++;
	}
	int cnt = 0;
	for (int i = 0; i < heights.size(); i++) {
		if (heights[i] != heights[hCnt[heights[i]]-1])
		{
			cnt++;
		}
		hCnt[heights[i]]--;
	}

	return cnt;
}

bool Gmockfirst::isLongPressedName(string name, string typed) {
	int i, j;
	if (name[0] != typed[0])
		return false;
	int cnt1, cnt2;
	cnt1 = cnt2 = 1;
	for (i = 1, j = 1; i < name.size() && j < typed.size(); i++, j++) {
		while (name[i] == name[i - 1]) {
			i++;
			cnt1++;
		}
		while (typed[j] == name[i - 1]) {
			j++;
			cnt2++;
		}
		if (cnt2 < cnt1)
			return false;
		if (name[i] != typed[j])
			return false;
		else
			cnt1 = cnt2 = 1;
	}
	while (j < typed.size() && typed[j] == typed[j - 1]) {
		j++;
		cnt2++;
	}
	if (i < name.size() || j < typed.size())
		return false;
	return true;
}

void Gmockfirst::solve()
{
//	fillInput();
//	heightChecker(heights);
	fillInput2();
	cout << isLongPressedName(name, typed);
	return;
}

void Gmockfirst::fillInput()
{
	getIntArray(heights);
}
void Gmockfirst::fillInput2()
{
	name = getNextLine();
	typed = getNextLine();
}

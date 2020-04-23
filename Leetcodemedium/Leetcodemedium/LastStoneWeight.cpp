#include "LastStoneWeight.h"

LastStoneWeight::LastStoneWeight()
{
	file.open("LastStoneWeightInput.txt");
}

void LastStoneWeight::solve()
{
	fillInput();
	cout << lastStoneWeight(nums);
	return;
}

int LastStoneWeight::lastStoneWeight(vector<int>& stones)
{
	MaxHeap heap;
	heap.init(nums);

	while (heap.size() > 1) {
		int top1 = heap.top();
		heap.removeMax();
		int top2 = heap.top();
		heap.removeMax();
		heap.insert(top1 - top2);
	}

	return heap.top();
}

void LastStoneWeight::fillInput()
{
	string line = getNextLine();
	std::stringstream s(line);
	string tmp;
	while (getline(s, tmp, ','))
	{
		nums.push_back(stoi(tmp));
	}
}

#include "RandomizedSet.h"

RandomizedSet::RandomizedSet()
{
	file.open("RandomizedSetInput.txt");
}

bool RandomizedSet::insert(int val)
{
	if (positons.find(val) != positons.end())
		return false;
	elements.push_back(val);
	positons[val] = elements.size() - 1;
	return true;
}

bool RandomizedSet::remove(int val)
{
	auto it = positons.find(val);
	if (it == positons.end())
		return false;
	int pos = it->second;
	int endPos = elements.size() - 1;
	elements[pos] = elements[endPos];
	positons[elements[pos]] = pos;
	elements.pop_back();
	positons.erase(val);
	return true;
}

int RandomizedSet::getRandom()
{
	int size = elements.size();
	int pos = rand() % size;
	return elements[pos];
}

void RandomizedSet::solve()
{
	fillInput();
	int j = 0;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "insert") {
			cout << insert(data[j++]) << endl;
		}
		else if (queries[i] == "remove") {
			cout << remove(data[j++]) << endl;
		}
		else if(queries[i] == "getRandom")
		{
			cout << getRandom() << endl;
		}
	}
	return;
}

void RandomizedSet::fillInput()
{
	getStrings(queries);
	getIntArray(data);
}

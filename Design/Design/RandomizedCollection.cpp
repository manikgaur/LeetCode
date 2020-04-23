#include "RandomizedCollection.h"

RandomizedCollection::RandomizedCollection()
{
	file.open("RandomizedCollectionInput.txt");
}

bool RandomizedCollection::insert(int val)
{
	bool ret = false;
	if (positons.find(val) == positons.end()) {
		positons[val] = list<int>();
		ret = true;
	}

	positons[val].push_back(elements.size());
	elements.push_back(val);
	return ret;
}

bool RandomizedCollection::remove(int val)
{
	if (positons.find(val) == positons.end())
		return false;

	int pos = positons[val].back();
	int lEle = elements.back();
	if (lEle != val) {
		elements[pos] = lEle;
		positons[lEle].remove(elements.size()-1);
		positons[lEle].push_back(pos);
	}
	positons[val].pop_back();
	if (positons[val].size() == 0)
		positons.erase(val);
	elements.pop_back();
	return true;
}

int RandomizedCollection::getRandom()
{
	if (elements.size() == 0)
		return 0;
	int r = rand();
	//cout << r;
	int pos = r % elements.size();

	return elements[pos];
}

void RandomizedCollection::solve()
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
		else if (queries[i] == "getRandom")
		{
			int k = 0;
			while (k++ < 10) {
				cout << getRandom() << endl;
			}
		}
	}
	return;
}

void RandomizedCollection::fillInput()
{
	getStrings(queries);
	getIntArray(data);
}

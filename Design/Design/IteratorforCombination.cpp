#include "IteratorforCombination.h"

IteratorforCombination::IteratorforCombination()
{
	file.open("IteratorforCombinationInput.txt");
}

class CombinationIterator {
	vector<int> pos;
	string str;
	int size;
public:
	CombinationIterator(string characters, int combinationLength) {
		pos = vector<int>(combinationLength);
		str = characters;
		size = characters.length();
		for (int i = 0; i < pos.size(); i++) {
			pos[i] = i;
		}
		pos[combinationLength - 1]--;
	}

	string next() {
		if (!hasNext())
			return "";
		int maxInc = size - pos.size();
		for (int i = pos.size() - 1; i >= 0; i--) {
			if (pos[i] < i + maxInc) {
				pos[i]++;
				while (++i < pos.size()) {
					pos[i] = pos[i - 1] + 1;
				}
				break;
			}
		}
		string retStr;
		for (int i = 0; i < pos.size(); i++) {
			retStr.push_back(str[pos[i]]);
		}
		return retStr;
	}

	bool hasNext() {
		for (int i = 0; i < pos.size(); i++) {
			if (pos[i] != (size - pos.size() + i)) {
				return true;
			}
		}
		return false;
	}
};

void IteratorforCombination::solve()
{
	fillInput();
	CombinationIterator obj(qData[0], stoi(qData[1]));
	int j = 1;
	while (obj.hasNext())
	{
		cout << "next :" << obj.next() << endl;
	}
/*
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "next")
			cout << "next :" << obj.next() << endl;
		else if (queries[i] == "hasNext")
			cout << "hasNext :" << obj.hasNext() << endl;

		//cout << endl;
	}
	*/
	return;
}

void IteratorforCombination::fillInput()
{
	getStrings(queries);
	getStrings(qData);
}

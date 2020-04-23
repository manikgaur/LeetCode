#include "FlattenNestedListIterator.h"

class NestedInteger {
public:
	     // Return true if this NestedInteger holds a single integer, rather than a nested list.
		     bool isInteger() const;
	
		     // Return the single integer that this NestedInteger holds, if it holds a single integer
		     // The result is undefined if this NestedInteger holds a nested list
		     int getInteger() const;
	
		     // Return the nested list that this NestedInteger holds, if it holds a nested list
		     // The result is undefined if this NestedInteger holds a single integer
		     const vector<NestedInteger> &getList() const;
	
};

class NestedIterator {
	list<int> fList;
	list<int>::iterator it;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		flattenList(nestedList, fList);
		it = fList.begin();
	}

	void flattenList(const vector<NestedInteger> &nestedList, list<int>& fList)
	{
		for (int i = 0; i < nestedList.size(); i++)
		{
			if (nestedList[i].isInteger())
			{
				fList.push_back(nestedList[i].getInteger());
			}
			else
			{
				flattenList(nestedList[i].getList(), fList);
			}
		}
	}

	int next() {
		if (it == fList.end())
			return -1;
		return *it++;
	}

	bool hasNext() {
		if (it == fList.end())
			return false;
		return true;
	}
};
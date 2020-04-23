#include "HashMap.h"

HashMap::HashMap()
{
	file.open("HashMapInput.txt");
}

class hashNode
{
public:
	int key;
	int value;
	hashNode(int key = -1, int value = -1):key(key), value(value){}
};

class MyHashMap {
	int size;
	vector<list<hashNode*>> hash;
public:
	/** Initialize your data structure here. */
	MyHashMap() {
		size = 100;
		hash = vector<list<hashNode*>>(size, list<hashNode*>());
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		list<hashNode*>& list = hash[key % size];
		auto it = list.begin();
		while (it != list.end()) {
			if ((*it)->key == key)
				break;
			it++;
		}
		if (it == list.end())
			hash[key % size].push_back(new hashNode(key, value));
		else
			(*it)->value = value;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		list<hashNode*>& list = hash[key % size];
		auto it = list.begin();
		while (it != list.end()) {
			if ((*it)->key == key)
				break;
			it++;
		}
		if (it == list.end())
			return -1;
		else
			return (*it)->value;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		list<hashNode*>& list = hash[key % size];
		auto it = list.begin();
		while (it != list.end()) {
			if ((*it)->key == key)
				break;
			it++;
		}
		if (it != list.end())
			list.erase(it);
	}
};

void HashMap::solve()
{
	fillInput();
	MyHashMap obj;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "put")
			obj.put(qData[i-1][0], qData[i-1][1]);
		else if (queries[i] == "get")
			cout << obj.get(qData[i-1][0]);
		else if (queries[i] == "remove")
			obj.remove(qData[i-1][0]);
	}
	return;
}

void HashMap::fillInput()
{
	getStrings(queries);
	get2Darray(qData);
}

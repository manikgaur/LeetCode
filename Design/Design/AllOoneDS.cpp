#include "AllOoneDS.h"
/** Initialize your data structure here. */
AllOoneDS::AllOoneDS()
{
	file.open("AllOoneDSInput.txt");
}

void AllOoneDS::addNode(OOneNode* node)
{
	int cnt = node->count;
	if (cnt == 0)
		return;
	OOneNode* head = NULL;
	OOneNode* tail = NULL;
	if (data.find(cnt) == data.end())
	{
		head = new OOneNode();
		tail = new OOneNode();
		head->next = tail;
		tail->prev = head;
		data[cnt] = list<OOneNode*>({ head, tail });
	}
	else {
		head = data[cnt].front();
		tail = data[cnt].back();
	}
	node->next = head->next;
	node->prev = head;
	head->next = node;
	node->next->prev = node;
}

void AllOoneDS::removeNode(OOneNode* node)
{
	int cnt = node->count;
	node->next->prev = node->prev;
	node->prev->next = node->next;
	if (data[cnt].front()->next == data[cnt].back()) {
		delete data[cnt].front();
		delete data[cnt].back();
		data.erase(cnt);
	}
	node->next = node->prev = NULL;
}
/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
void AllOoneDS::inc(string key)
{
	OOneNode* node = NULL;
	if (hashData.find(key) == hashData.end())
	{
		node = new OOneNode(key);
		addNode(node);
		hashData[key] = node;
		return;
	}
	node = hashData.find(key)->second;
	removeNode(node);
	node->count++;
	addNode(node);
}

/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
void AllOoneDS::dec(string key)
{
	OOneNode* node = NULL;
	if (hashData.find(key) == hashData.end())
	{
		return;
	}
	node = hashData.find(key)->second;
	removeNode(node);
	node->count--;
	if (node->count == 0) {
		hashData.erase(key);
	}
	else
		addNode(node);
}

/** Returns one of the keys with maximal value. */
string AllOoneDS::getMaxKey()
{
	if (hashData.size() == 0)
		return string();

	auto it = data.end();
	it--;
	return it->second.front()->next->val;
}

/** Returns one of the keys with Minimal value. */
string AllOoneDS::getMinKey()
{
	if(hashData.size() == 0)
		return string();

	auto it = data.begin();
	return it->second.front()->next->val;
}

void AllOoneDS::solve()
{
	fillInput();
	int j = 1;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "inc")
			inc(qData[j]);
		if (queries[i] == "dec")
			dec(qData[j]);
		if (queries[i] == "getMaxKey")
			cout << getMaxKey() << endl;
		if (queries[i] == "getMinKey")
			cout << getMinKey() << endl;
		j++;
	}
	return;
}

void AllOoneDS::fillInput()
{
	getStrings(queries);
	getStrings(qData);
}

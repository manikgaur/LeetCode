#include "LRUCache.h"

LRUCache::LRUCache()
{
	file.open("LRUCacheInput.txt");
	head = new ListNode();
	tail = new ListNode();
	head->next = tail;
	tail->prev = head;
	size = 0;
}

LRUCache::LRUCache(int capacity)
{
	this->capacity = capacity;
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void LRUCache::addNode(int key, int val)
{
	ListNode *node;
	if (capacity == size) {
		node = removeNode();
	}
	else {
		node = new ListNode();
	}
	ref[key] = node;
	node->key = key;
	node->val = val;
	node->next = head->next;
	head->next = node;
	node->prev = head;
	node->next->prev = node;
	size++;
}

ListNode* LRUCache::removeNode()
{
	ListNode* delNode = tail->prev;
	tail->prev = delNode->prev;
	tail->prev->next = tail;
	ref.erase(delNode->key);
	size--;
	return delNode;
}

void LRUCache::moveNode(int key)
{
	ListNode* node = ref[key];
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = head->next;
	head->next = node;
	node->next->prev = node;
	node->prev = head;
}

int LRUCache::get(int key)
{
	if (ref.find(key) == ref.end())
		return -1;
	moveNode(key);
	return ref[key]->val;
}

void LRUCache::put(int key, int value)
{
	if (ref.find(key) == ref.end())
		addNode(key, value);
	ref[key]->val = value;
	moveNode(key);
}

void LRUCache::solve()
{
	fillInput();
	setCapacity(data[0][0]);

	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "put")
		{
			put(data[i][0], data[i][1]);
		}
		if (queries[i] == "get")
		{
			cout << get(data[i][0]) << endl;
		}
	}
	return;
}

void LRUCache::fillInput()
{
	getStrings(queries);
	get2Darray(data);
}

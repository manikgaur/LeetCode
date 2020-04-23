#include "LFUCache.h"

LFUCache::LFUCache()
{
	file.open("LFUCacheInput.txt");	
	size = 0;
}

LFUCache::LFUCache(int capacity)
{
}

void LFUCache::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void LFUCache::addNode(int key, int val)
{
	DListNode* node = NULL;
	if (size == capacity) {
		node = eviction();
		if (node == NULL)
			return;
		ref.erase(node->key);
	}
	else {
		if (ref.find(key) == ref.end())
			node = new DListNode(key, val);
		else {
			node = ref[key];
			ref.erase(key);
		}
	}
	ref[key] = node;
	node->freq = 1;
	node->key = key;
	node->val = val;
	if (cache.find(node->freq) == cache.end()) {
		cache[node->freq] = pair<DListNode, DListNode>();
		DListNode* head = &cache[node->freq].first;
		DListNode* tail = &cache[node->freq].second;
		head->next = tail;
		tail->prev = head;
	}
	pair<DListNode, DListNode>& p = cache[node->freq];
	DListNode* head = &p.first;
	node->next = head->next;
	node->next->prev = node;
	node->prev = head;
	head->next = node;
	size++;
	return;
}

void LFUCache::removeNode(DListNode* node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
	int freq = node->freq;
	pair<DListNode, DListNode>& fList = cache[freq];
	if (fList.first.next == &fList.second) {
		cache.erase(freq);
	}
	size--;
	return;
}

DListNode* LFUCache::eviction()
{
	auto it = cache.begin();
	if (it == cache.end())
		return NULL;
	DListNode* node = it->second.second.prev;
	removeNode(node);
	return node;
}

void LFUCache::moveNode(int key)
{
	DListNode* node = ref[key];
	removeNode(node);
	node->freq++;
	auto it = cache.find(node->freq);
	if (it == cache.end()) {
		cache[node->freq] = pair<DListNode, DListNode>();
		DListNode* head = &cache[node->freq].first;
		DListNode* tail = &cache[node->freq].second;
		head->next = tail;
		tail->prev = head;
	}
	pair<DListNode, DListNode>& p = cache[node->freq];
	DListNode* head = &p.first;
	node->next = head->next;
	node->next->prev = node;
	node->prev = head;
	head->next = node;
	size++;
}

int LFUCache::get(int key)
{
	if (ref.find(key) == ref.end())
		return -1;
	moveNode(key);
	return ref[key]->val;
}

void LFUCache::put(int key, int value)
{
	if (ref.find(key) == ref.end()) {
		addNode(key, value);
	}
	else {
		moveNode(key);
		ref[key]->val = value;
	}
}

void LFUCache::solve()
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

void LFUCache::fillInput()
{
	getStrings(queries);
	get2Darray(data);
}

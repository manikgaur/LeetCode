#pragma once
#include "Solution.h"

class TrieNode 
{
public:
	bool isWord;
	vector<TrieNode*> nodes;

	TrieNode():isWord(false), nodes(vector<TrieNode*>(26)){}
};

class Trie :
	public Solution
{
	vector<string> queries;
	vector<string> data;
	TrieNode *root;
public:
	Trie();
	void insert(string word);
	bool search(string word);
	bool startsWith(string prefix);
	void solve();
	void fillInput();
};


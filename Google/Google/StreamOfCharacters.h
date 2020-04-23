#pragma once
#include "Solution.h"
class TrieNode
{
public:
	bool word;
	unordered_map<char, TrieNode*> trie;
	TrieNode() :word(false), trie(unordered_map<char, TrieNode*>()) {}
};

class StreamOfCharacters :
	public Solution
{
	TrieNode *data;

	vector<char> stack;
	vector<string> queries;
	vector<string> words;
public:
	StreamOfCharacters();
	void StreamChecker(vector<string>& words);
	bool query(char letter);
	void solve();
	void fillInput();
};


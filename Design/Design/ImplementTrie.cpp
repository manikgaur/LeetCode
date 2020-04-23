#include "ImplementTrie.h"

Trie::Trie()
{
	file.open("TrieInput.txt");
	root = new TrieNode();
}

void Trie::insert(string word)
{
	TrieNode* node = root;
	for (int i = 0; i < word.length(); i++)
	{
		if (node->nodes[word[i] - 'a'] == NULL)
		{
			node->nodes[word[i] - 'a'] = new TrieNode();
		}
		node = node->nodes[word[i] - 'a'];
	}
	node->isWord = true;
}

bool Trie::search(string word)
{
	if (root == NULL)
		return false;
	TrieNode* node = root;

	for (int i = 0; i < word.length(); i++)
	{
		if (node->nodes[word[i] - 'a'] == NULL)
		{
			return false;
		}
		node = node->nodes[word[i] - 'a'];
	}
	return node->isWord;
}

bool Trie::startsWith(string prefix)
{
	if (root == NULL)
		return false;
	TrieNode* node = root;

	for (int i = 0; i < prefix.length(); i++)
	{
		if (node->nodes[prefix[i] - 'a'] == NULL)
		{
			return false;
		}
		node = node->nodes[prefix[i] - 'a'];
	}
	return true;
}

void Trie::solve()
{
	fillInput();

	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "insert")
		{
			insert(data[i]);
		}
		if (queries[i] == "search")
		{
			cout << search(data[i]);
		}
		if (queries[i] == "startsWith")
		{
			cout << startsWith(data[i]);
		}
	}
	return;
}

void Trie::fillInput()
{
	getStrings(queries);
	getStrings(data);
}

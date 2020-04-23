#include "AddandSearchWord.h"

class TrieNode
{
public:
	bool isWord;
	map<char, TrieNode*> next;
	TrieNode(): isWord(false), next(map<char, TrieNode*>()){}
};

class WordDictionary {
	TrieNode* root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		if (root == NULL)
		{
			root = new TrieNode();
		}
		TrieNode* node = root;
		for (int i = 0; i < word.size(); i++)
		{
			if(node->next.find(word[i]) == node->next.end())
				node->next[word[i]] = new TrieNode();
			node = node->next[word[i]];
		}
		node->isWord = true;
	}

	bool findWord(string word, int pos, TrieNode* node)
	{
		if (pos == word.size()) {
			return node->isWord;
		}

		for (int i = pos; i < word.size(); i++)
		{
			if (word[i] != '.') {
				if (node->next.find(word[i]) == node->next.end())
					return false;
				node = node->next[word[i]];
			}
			else
			{
				auto it = node->next.begin();
				while (it != node->next.end()) {
					bool found = findWord(word, i+1, it->second);
					if (found)
						return true;
					it++;
				}
				return false;
			}
		}
		return node->isWord;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {

		if (root == NULL)
		{
			return false;
		}
		return findWord(word, 0, root);
	}
};


AddandSearchWord::AddandSearchWord()
{
	file.open("AddandSearchWordInput.txt");
}

void AddandSearchWord::solve()
{
	fillInput();
	WordDictionary wd;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "addWord")
			wd.addWord(qData[i]);
		else if (queries[i] == "search")
			cout << wd.search(qData[i]);
	}
	return;
}

void AddandSearchWord::fillInput()
{
	getStrings(queries);
	getStrings(qData);
}

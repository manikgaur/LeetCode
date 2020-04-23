#include "UniqueWordAbbreviation.h"

UniqueWordAbbreviation::UniqueWordAbbreviation()
{
	file.open("UniqueWordAbbreviationInput.txt");
}

class TrieNodeL
{
public:
	bool isWord;
	set<string> words;
	map<char, TrieNodeL*> next;
	TrieNodeL():isWord(false), words(set<string>()), next(map<char, TrieNodeL*>()){}
};

class ValidWordAbbr {
	TrieNodeL* root;
public:
	string getAbbr(string s)
	{
		if (s.length() == 0)
			return "";
		string res;
		res.push_back(s[0]);
		int len = s.length() - 2;
		if (len < 0)
			return res;
		res.append(to_string(len));
		res.push_back(s[len + 1]);
		return res;
	}
	ValidWordAbbr(vector<string>& dictionary) {
		root = new TrieNodeL();
		for (auto w : dictionary) {
			string s = getAbbr(w);
			TrieNodeL* node = root;
			for (auto c : s) {
				if (node->next.find(c) == node->next.end())
				{
					node->next[c] = new TrieNodeL();
				}
				node = node->next[c];
			}
			node->isWord = true;
			node->words.insert(w);
		}
	}

	bool isUnique(string word) {
		if (root == NULL)
			return false;
		TrieNodeL* node = root;

		string s = getAbbr(word);
		for (auto c : s) {
			if (node->next.find(c) == node->next.end())
				return true;
			node = node->next[c];
		}
		if (node->isWord) {
			if (node->words.size() > 1)
				return false;
			if (node->words.find(word) == node->words.end())
				return false;
		}
		return true;
	}
};

void UniqueWordAbbreviation::solve()
{
	fillInput();
	ValidWordAbbr obj(words);
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "isUnique") {
			cout << obj.isUnique(qData[i - 1]) << endl;
		}

		//cout << endl;
	}
	return;
}

void UniqueWordAbbreviation::fillInput()
{
	getStrings(queries);
	getStrings(words);
	getStrings(qData);
}

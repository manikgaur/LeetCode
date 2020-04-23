#include "StreamOfCharacters.h"



StreamOfCharacters::StreamOfCharacters()
{
	file.open("StreamOfCharactersInput.txt");
}
void StreamOfCharacters::StreamChecker(vector<string>& words) {
	data = new TrieNode();
	for (int i = 0; i < words.size(); i++) {
		string s = words[i];
		TrieNode *t = data;
		for (int j = s.length() - 1; j >= 0; j--) {
			if (t->trie.find(s[j]) == t->trie.end()) {
				t->trie[s[j]] = new TrieNode();
			}
			t = t->trie[s[j]];
		}
		t->word = true;
	}

	stack = vector<char>(40000);
}

bool StreamOfCharacters::query(char letter) {
	stack.push_back(letter);
	TrieNode *t = data;
	int stacktop = stack.size() - 1;
	while (t) {
		if (t->word)
			return true;
		t = t->trie[stack[stacktop--]];
	}

	return false;
}
void StreamOfCharacters::solve()
{
	fillInput();
	StreamChecker(words);

	for (int i = 0; i < queries.size(); i++)
		cout << query(queries[i][0]) << endl;

	return;

}

void StreamOfCharacters::fillInput()
{
	getStrings(words);
	getStrings(queries);
}

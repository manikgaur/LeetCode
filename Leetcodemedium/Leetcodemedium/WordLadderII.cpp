#include "WordLadderII.h"

WordLadderII::WordLadderII()
{
	file.open("WordLadderIIInput.txt");
}

void fillGraph(unordered_map<string, list<string>>& graph, set<string>& wordSet, string startWord, string endWord)
{
	set<string>::iterator it = wordSet.begin();
	list<string> queue;
	queue.push_back(startWord);

	while (queue.size()) {
		
		string word = queue.front();
		if (word == endWord)
			break;
		string w = word; 
		queue.pop_front();
		graph[word] = list<string>();
		for (int i = 0; i < word.length(); i++) {
			char c = word[i];
			for (int j = 0; j < 26; j++) {
				word[i] = 'a' + j;
				if (wordSet.find(word) != wordSet.end() && word != w) {
					queue.push_back(word);
					graph[w].push_back(word);
				}
			}
			word[i] = c;
		}
		wordSet.erase(word);
	}
}

void fillResult(unordered_map<string, list<string>>& finalGraph, string startWord, string endWord, vector<string>& results, vector<vector<string>>& res)
{
	results.push_back(startWord);
	if (startWord == endWord) {
		res.push_back(results);
		return;
	}

	unordered_map<string, list<string>>::iterator it = finalGraph.find(startWord);
	if (it != finalGraph.end()) {
		list<string>::iterator it2 = it->second.begin();
		while (it2 != it->second.end()) {
			fillResult(finalGraph, *it2, endWord, results, res);
		}
	}
}

vector<vector<string>> WordLadderII::findLadders(string beginWord, string endWord, vector<string>& wordList)
{
	vector<vector<string>> res;
	unordered_map<string, list<string>> graph;
	set<string> wordSet(wordList.begin(), wordList.end());
	wordSet.insert(beginWord);
	if (wordSet.find(endWord) == wordSet.end())
		return res;
	fillGraph(graph, wordSet, beginWord, endWord);
	unordered_map<string, list<string>> finalGraph;
/*	list<string> queue;
	queue.push_back(beginWord);
	queue.push_back("");
	bool found = false;
	while (!queue.empty()) {
		string top = queue.front();
		queue.pop_front();
		if (top == "") {
			if (found) {
				break;
			}
			queue.push_back("");
			continue;
		}
		finalGraph[top] = list<string>();
		unordered_map<string, list<string>>::iterator it = graph.find(top);
		if (it != graph.end()) {
			list<string>& list = it->second;
			while (list.size()) {
				queue.push_back(list.front());
				finalGraph[top].push_back(list.front());				
				if (list.front() == endWord) {
					found = true;
				}
				list.pop_front();
			}
		}
	}*/
	vector<string> results;
	fillResult(graph, beginWord, endWord, results, res);

	return res;
}

void WordLadderII::solve()
{
	fillInput();
	findLadders(beginWord, endWord, wordList);
	return;
}

void WordLadderII::fillInput()
{
	beginWord = getNextLine();
	endWord = getNextLine();
	getStrings(wordList);

}

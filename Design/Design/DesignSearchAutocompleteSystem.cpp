#include "DesignSearchAutocompleteSystem.h"

DesignSearchAutocompleteSystem::DesignSearchAutocompleteSystem()
{
	file.open("DesignSearchAutocompleteSystem.txt");
}

class TrieNodeAS;
struct classcomp
{
	bool operator ()(const TrieNodeAS* lhs, const TrieNodeAS* rhs) const;
};
class TrieNodeAS
{
public:
	bool isSentance;
	string sentence;
	int frequency;
	set<TrieNodeAS*, classcomp> results;
	map<char, TrieNodeAS*> next;
	TrieNodeAS():isSentance(false),next(map<char, TrieNodeAS*>()) {}
	void addToResults(TrieNodeAS* node, int times)
	{
		auto it = results.begin();
		while (it != results.end()) {
			if (*it == node)
				break;
			it++;
		}
		if (it != results.end())
			results.erase(it);
		results.insert(node);
		if (results.size() <= 3) {
			return;
		}
		it = prev(results.end());
		results.erase(it);
	}
	bool operator < (const TrieNodeAS& rhs) const{
		if (this->frequency == rhs.frequency)
			return this->sentence.compare(rhs.sentence) <= 0;

		return this->frequency > rhs.frequency;
	}
};
inline bool classcomp::operator()(const TrieNodeAS* lhs, const TrieNodeAS* rhs) const
{
	if (lhs->frequency == rhs->frequency)
		return lhs->sentence.compare(rhs->sentence) < 0;

	return lhs->frequency > rhs->frequency;
}

class AutocompleteSystem {
	static TrieNodeAS* cNode;
	static string cString;
	TrieNodeAS* root;
public:
	AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
		root = new TrieNodeAS();
		int i = 0;
		for (auto s : sentences) {
			TrieNodeAS* node = root;
			addSentence(s, node, times[i++]);
		}
		cNode = root;
		cString = string();
	}

	void reset() {
		cNode = root;
		cString = string();
	}

	void addSentence(std::string &s, TrieNodeAS * node, int time)
	{
		list<TrieNodeAS*> stack;
		for (auto c : s) {
			if (node->next.find(c) == node->next.end())
				node->next[c] = new TrieNodeAS();
			node = node->next[c];
			stack.push_back(node);
		}
		if(node->isSentance)
			node->frequency += 1;
		else node->frequency = time;
		node->isSentance = true;
		node->sentence = s;
		while (stack.size())
		{
			TrieNodeAS* top = stack.back();
			stack.pop_back();
			top->addToResults(node, time);
		}
	}

	vector<string> input(char c) {
		static bool found = true;
		if (c == '#') {
			found = true;
			addSentence(cString, root, 1);
			reset();
			return vector<string>();
		}
		cString.push_back(c);
		if (found == false)
			return vector<string>();
		if (cNode->next.find(c) == cNode->next.end()) {
			found = false;
			return vector<string>();
		}
		vector<string> res;
		cNode = cNode->next[c];
		if(cNode->results.size() == 0)
			return vector<string>();
		auto it = cNode->results.begin();
		while(it != cNode->results.end())
		{
			res.push_back((*it)->sentence);
			it++;
		}
		return res;
	}
};
TrieNodeAS* AutocompleteSystem::cNode;
string AutocompleteSystem::cString;
void DesignSearchAutocompleteSystem::solve()
{
	fillInput();
	AutocompleteSystem obj(sentences, times);
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "input") {
			vector<string> res = obj.input(qData[i - 1]);
			cout << "Input : " << qData[i - 1] << endl;
			for (auto s : res) {
				cout << s << endl;
			}	
		}	
	}
	return;
}

void DesignSearchAutocompleteSystem::fillInput()
{
	getStrings(queries);
	getStrings(sentences);
	getIntArray(times);
	getCharArray(qData);
}

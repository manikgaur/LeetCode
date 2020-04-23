#include "LongestStringChain.h"

LongestStringChain::LongestStringChain()
{
	file.open("longestStringChainInput.txt");
}

int LongestStringChain::getDiff(string & s1, string & s2)
{
	vector<int> countChar(26);
	if (s2.length() != s1.length() + 1)
		return 0;
	for (int i = 0; i < s2.length(); i++) {
		countChar[s2[i] - 'a']++;
	}
	for (int i = 0; i < s1.length(); i++) {
		countChar[s1[i] - 'a']--;
	}
	int count = 0;
	for (int i = 0; i < countChar.size(); i++) {
		count += abs(countChar[i]);
	}
	return count;
}
bool LongestStringChain::compare(string &s1, string &s2)
{
	return s1.size() < s2.size();
}

int LongestStringChain::longestStrChain(vector<string>& words)
{
	if (words.size() < 2)
		return words.size();

	sort(words.begin(), words.end(), compare);
	vector<int> longChain(words.size(), 1);
	int maxResult = 0;
	for (int i = 0; i < words.size(); i++) {
		int max = 1;
		for (int j = i - 1; j >= 0; j--) {
			int diff = getDiff(words[j], words[i]);
			if (diff == 1) {
				if (max < longChain[j] + 1)
					max = longChain[j] + 1;
			}
		}
		longChain[i] = max;
		if (maxResult < max)
			maxResult = max;
	}
	return maxResult;
}

void LongestStringChain::fillInput()
{
	string line = getNextLine();
	std::stringstream s(line);
	string tmp;
	while (getline(s, tmp, ','))
	{
		words.push_back(tmp);
	}
}

void LongestStringChain::solve()
{
	fillInput();
	longestStrChain(words);
}


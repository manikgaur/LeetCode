#include "MinWindowSubstring.h"

MinWindowSubstring::MinWindowSubstring()
{
	file.open("minWindowSubstringInput.txt");
}

string MinWindowSubstring::minWindow(string s, string t)
{
	if(s.length() < t.length())
		return string();

	map<char,int> tChars;
	for (int i = 0; i < t.length(); i++) {
		tChars[t[i]]++;
	}
	map<char, int>sChar;
	list<int> indexes;
	int mini = 0;
	int minj = 0;
	int min = s.length()+1;
	for (int i = 0; i < s.length(); i++) {
		if (tChars.find(s[i]) != tChars.end()) {
			sChar[s[i]]++;
			indexes.push_back(i);
			if (sChar.size() == tChars.size()) {
				while (sChar[s[indexes.front()]] > tChars[s[indexes.front()]]) {
					sChar[s[indexes.front()]]--;
					indexes.pop_front();
				}
				map<char, int>::iterator it = sChar.begin();
				while (it != sChar.end()) {
					if (tChars[it->first] > it->second)
						break;
					it++;
				}

				if ((it == sChar.end()) && min > indexes.back() - indexes.front() + 1) {
					mini = indexes.front();
					minj = indexes.back();
					min = minj - mini + 1;
				}
			}
		}		
	}
	if (min <= s.length())
		return s.substr(mini, min);

	return string();
}

void MinWindowSubstring::solve()
{
	fillInput();
	cout << minWindow(S, T);
	return;
}

void MinWindowSubstring::fillInput()
{
	S = getNextLine();
	T = getNextLine();
}

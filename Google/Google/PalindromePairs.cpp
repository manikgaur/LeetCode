#include "PalindromePairs.h"

PalindromePairs::PalindromePairs()
{
	file.open("PalindromePairsInput.txt");
}

bool PalindromePairs::isPailndrome(string str1, string str2)
{
	str1.append(str2);

	int i = 0;
	int j = str1.length()-1;
	while (i < j) {
		if (str1[i] != str1[j])
			return false;
		i++;
		j--;
	}

	return true;
}

vector<vector<int>> PalindromePairs::palindromePairs(vector<string>& words)
{
	vector<vector<int>> result;
	unordered_map<string, int> data;

	for (int i = 0; i < words.size(); i++) {
		string str = words[i];
		reverse(str.begin(), str.end());
		data[str] = i;
	}
	unordered_map<string, int>::iterator it;
	for (int i = 0; i < words.size(); i++) {
		string str = words[i];
		for (int j = 0; j < str.length(); j++) {
			string s(str, 0, j);
			string s2(str, j, str.length());
			if ((it = data.find(s)) != data.end() && isPailndrome(s2, "")) {
				if (i != it->second) {
					vector<int> pair{ i, it->second };
					result.push_back(pair);
					if (s.empty()) {
						vector<int> pair2{ it->second, i };
						result.push_back(pair2);
					}
				}
			}
			if ((it = data.find(s2)) != data.end() && isPailndrome(s, "")) {
				if (i != it->second) {
					vector<int> pair{ it->second, i };
					result.push_back(pair);
				}
			}
		}
	}
	return result;
}


vector<vector<int>> PalindromePairs::palindromePairs2(vector<string>& words)
{
	vector<vector<int>> result;
	unordered_map<char, vector<int>> data;

	for (int i = 0; i < words.size(); i++) {
		int n = words[i].length();
		if (n)
			data[words[i][n - 1]].push_back(i);
		else
			data['0'].push_back(i);
	}

	for (int i = 0; i < words.size(); i++) {
		vector<int>& pos = data[words[i][0]];
		for (int j = 0; j < pos.size(); j++) {
			int p = pos[j];			
			if (i != p && isPailndrome(words[i], words[p])) {
				vector<int> pair{ i, p };
				result.push_back(pair);
			}
		}
		if (isPailndrome(words[i], "")) {
			vector<int>& emptyPos = data['0'];
			for (int k = 0; k < emptyPos.size(); k++) {
				int p = emptyPos[k];
				if (p != i) {
					vector<int> pair1{ i, p };
					result.push_back(pair1);
					vector<int> pair2{ p, i };
					result.push_back(pair2);
				}
			}
		}
	}


/*	for (int i = 0; i < words.size()-1; i++) {
		for (int j = i + 1; j < words.size(); j++) {
			if (isPailndrome(words[i], words[j])) {
				vector<int> pair{i, j};
				result.push_back(pair);
			}
			if (isPailndrome(words[j], words[i])) {
				vector<int> pair{ j, i };
				result.push_back(pair);
			}
		}
	}
*/
	return result;
}

void PalindromePairs::solve()
{
	fillInput();
	palindromePairs(words);
	return;
}

void PalindromePairs::fillInput()
{
	getStrings(words);
}

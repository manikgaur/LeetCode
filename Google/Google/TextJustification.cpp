#include "TextJustification.h"

TextJustification::TextJustification()
{
	file.open("TextJustificationInput.txt");
}

void TextJustification::adjustLine(string& line, int maxWidth)
{
	if (line.length() == maxWidth && line[maxWidth - 1] != ' ')
		return;
	stringstream s(line); // Used for breaking words 
	string word; // to store individual words 

	int count = 0;
	int length = 0;
	while (s >> word) {
		length += word.length();
		count++;
	}
	count--;

	stringstream s1(line);
	line.clear();
	if (count) {
		int spaceLength = maxWidth - length;
		int spaceQ = spaceLength / count;
		int spaceR = spaceLength % count;
		while (s1 >> word) {
			line.append(word);
			int n = count-- ? spaceQ + (spaceR-- > 0 ? 1 : 0) : 0;
			string tmp(n, ' ');
			line.append(tmp);
		}
	}
	else {
		s1 >> line;
		string tmp(maxWidth - length, ' ');
		line.append(tmp);
	}
}

vector<string> TextJustification::fullJustify(vector<string>& words, int maxWidth)
{
	vector<string> result;
	int currLen = maxWidth;
	string line;
	for (int i = 0; i < words.size(); i++) {
		if (maxWidth - line.length() >= words[i].length()) {
			line.append(words[i]);
			if (line.length() < maxWidth)
				line.append(" ");
		}
		else {
			adjustLine(line, maxWidth);
			result.push_back(line);
			line.clear();
			line.append(words[i]);
			if (line.length() < maxWidth)
				line.append(" ");
		}
	}
	if (line.length()) {
		string tmp(maxWidth - line.length(), ' ');
		line.append(tmp);
		result.push_back(line);
	}
	return result;
}

void TextJustification::solve()
{
	fillInput();
	fullJustify(words, maxWidth);
	return;
}

void TextJustification::fillInput()
{
	getStrings(words);
	maxWidth = getInt();
}

#include "PalindromePartitioning3.h"

PalindromePartitioning3::PalindromePartitioning3()
{
	file.open("PalindromePartitioning3Input.txt");
}

int PalindromePartitioning3::calculateChanges(string s, int start, int end)
{
	int i = start;
	int j = end - 1;
	int count = 0;
	while (i <= j) {
		if (s[i] != s[j])
			count++;
		i++;
		j--;
	}
	return count;
}

int PalindromePartitioning3::doPalindromePartition(string s, int k, int start, int end)
{
	if (data[start][end][k] != -1)
		return data[start][end][k];
	if (end - start == k)
		return 0;
	if (k > end - start)
		return s.length();

	if (k == 1) {
		return calculateChanges(s, start, end);
	}
	int count = 0;
	int minCount = INT_MAX;
	for (int i = start + 1; i < end; i++) {
		count += doPalindromePartition(s, 1, start, i);
		count += doPalindromePartition(s, k - 1, i, end);
		if (minCount > count) {
			minCount = count;
		}
		count = 0;
	}
	data[start][end][k] = minCount;
	return minCount;
}

int PalindromePartitioning3::palindromePartition(string s, int k)
{
	data = vector<vector<vector<int>>>(101, vector<vector<int>>(101, vector<int>(101, -1)));
	return doPalindromePartition(s, k, 0, s.length());
}

void PalindromePartitioning3::solve()
{
	fillInput();
	cout << palindromePartition(str, K);
	return;
}

void PalindromePartitioning3::fillInput()
{
	str = getNextLine();
	string line = getNextLine();
	K = stoi(line);
	return;
}

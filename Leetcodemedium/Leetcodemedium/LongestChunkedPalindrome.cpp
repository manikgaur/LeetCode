#include "LongestChunkedPalindrome.h"

LongestChunkedPalindrome::LongestChunkedPalindrome()
{
	file.open("LongestChunkedPalindromeInput.txt");
}

int LongestChunkedPalindrome::longestDecomposition(string text)
{
	if (text.length() == 0)
		return 0;
	int len = 0;

	int i = 0;
	int j = text.length() - 1;
	int end = j;
	int start = i;
	int count = 0;
	while (start<= end) {
		while (text[j] != text[i])
			j--;
		if (i == j) {
			count++;
			break;
		}
		int k = j;
		while (j <= end) {
			if (text[i] != text[j]) {
				j = k-1;
				i = start;
				break;
			}
			i++;
			j++;
		}
		if (j > end) {
			count += 2;
			end = end - (i - start);
			start = i;
			j = end;
		}
	}


	return count;
}

void LongestChunkedPalindrome::solve()
{
	fillInput();
	cout << longestDecomposition(str);
	return;
}

void LongestChunkedPalindrome::fillInput()
{
	str = getNextLine();
	return;
}

#include "MedianFromDataStream.h"

MedianFromDataStream::MedianFromDataStream()
{
	file.open("SplitConsecutiveSubsequencesInput.txt");
}

void MedianFromDataStream::MedianFinder()
{
	result.clear();
	total = 0;
}

void MedianFromDataStream::addNum(int num)
{
	result[num]++;
	total++;
	if (total == 1) {
		i = j = result.begin();
		iPos = jPos = 1;
	}
	else if (total % 2) {
		if (num >= j->first) {
			i = j;
			if (num == j->first)
				jPos++;
			iPos = jPos;
		}
		else if (num <= i->first) {
			j = i;
			jPos = iPos;
		}
		else {
			i++;
			j--;
			iPos = jPos = 1;
		}
	}
	else {
		if (num < i->first) {
			iPos++;
			if (iPos > j->second) {
				iPos = 1;
				i--;
			}
		}
		else if (num > i->first) {
			jPos--;
			if (jPos == 0) {
				j++;
				jPos = j->second;
			}
		}
		else {
			iPos++;
		}
	}
	return;

}

double MedianFromDataStream::findMedian()
{
	return double(i->first + j->first)/2;
}

void MedianFromDataStream::solve()
{
	fillInput();
	int j = 0;
	for (int i = 0; i < queries.size(); i++) {
		if (queries[i] == "addNum")
			addNum(stream[j++]);
		else if (queries[i] == "findMedian")
			cout << findMedian() << endl;
	}
	return;
}

void MedianFromDataStream::fillInput()
{
	getStrings(queries);
	getIntArray(stream);
}

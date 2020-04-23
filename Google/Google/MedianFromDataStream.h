#pragma once
#include "Solution.h"
class MedianFromDataStream :
	public Solution
{
	map<int, int> result;
	map<int, int>::iterator i;
	map<int, int>::iterator j;
	int iPos;
	int jPos;
	int total;
	vector<int> stream;
	vector<string> queries;
public:
	MedianFromDataStream();    
	void MedianFinder();
	void addNum(int num);
	double findMedian();
	void solve();
	void fillInput();
};


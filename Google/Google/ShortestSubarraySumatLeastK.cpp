#include "ShortestSubarraySumatLeastK.h"
/*
class SumPos {
public:
	int sum;
	int pos;
	SumPos() :sum(0), pos(0) {};
	SumPos(int s, int p) :sum(s), pos(p) {};
	bool operator < (const SumPos& ele) const {
		return sum < ele.sum;
	}
};
*/
ShortestSubarraySumatLeastK::ShortestSubarraySumatLeastK()
{
	file.open("ShortestSubarraySumatLeastKInput.txt");
}

int ShortestSubarraySumatLeastK::shortestSubarray(vector<int>& A, int K)
{
	map<int, int> res;
	
	res[0] = -1;
	int currSum = 0;
	map<int, int>::iterator itr;
	int minW = A.size()+1;
	for (int i = 0; i < A.size(); i++) {
		currSum += A[i];
		itr = res.upper_bound(currSum - K);
		if (itr != res.begin()) {
			map<int, int>::iterator tmp;
			for (auto itrr = res.begin(); itrr != itr; itrr++)
				if (i - itrr->second < minW) minW = i - itrr->second;
			res.erase(res.begin(), itr);
		}
		res[currSum] = i;
	}


	return minW == A.size() + 1 ? -1 : minW;
}

void ShortestSubarraySumatLeastK::solve()
{
	fillInput();
	cout << shortestSubarray(data, K);
	return;
}

void ShortestSubarraySumatLeastK::fillInput()
{
	getIntArray(data);
	K = getInt();
}

#include "DesignZigzagIterator.h"

DesignZigzagIterator::DesignZigzagIterator()
{
	file.open("DesignZigzagIteratorInput.txt");
}

class ZigzagIterator {
	int vect;
	int v1Pos;
	int v2Pos;
	vector<vector<int>> vects;

public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		vects = vector<vector<int>>(2);
		vects[0] = v1;
		vects[1] = v2;
		v1Pos = 0;
		v2Pos = 0;
	}

	int next() {
		if (v1Pos >= vects[0].size()) {
			return vects[1][v2Pos++];
		}
		else if (v2Pos >= vects[1].size()) {
			return vects[0][v1Pos++];
		}
		else if(v1Pos == v2Pos)
			return vects[0][v1Pos++];
		else if (v1Pos > v2Pos)
			return vects[1][v2Pos++];
	}

	bool hasNext() {
		if (v1Pos < vects[0].size() || v2Pos < vects[1].size())
			return true;
		return false;
	}
};

void DesignZigzagIterator::solve()
{
	fillInput();
	ZigzagIterator obj(arr1, arr2);
	while (obj.hasNext())
	{
		cout << obj.next() << endl;
	}
	return;
}

void DesignZigzagIterator::fillInput()
{
	getIntArray(arr1);
	getIntArray(arr2);
}

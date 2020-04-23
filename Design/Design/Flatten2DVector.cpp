#include "Flatten2DVector.h"

Flatten2DVector::Flatten2DVector()
{
	file.open("Flatten2DVector.txt");
}
class Vector2D {
	vector<vector<int>> data;
	int rows;
	int cRow;
	int cCol;
public:
	Vector2D(vector<vector<int>>& v) {
		data = v;
		rows = v.size();
		cRow = 0;
		cCol = 0;
	}

	int next() {
		int val = data[cRow][cCol++];
		if (cCol >= data[cRow].size()) {
			cRow++;
			cCol = 0;
		}
		return val;
	}

	bool hasNext() {
		if (cRow >= rows)
			return false;
		return true;
	}
};
void Flatten2DVector::solve()
{
	fillInput();
	Vector2D obj(data);
	while (obj.hasNext()) {
		cout << obj.next() << endl;
	}
	return;
}

void Flatten2DVector::fillInput()
{
	getStrings(queries);
	get2Darray(data);
}

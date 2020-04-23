#include "KClosestToOrigin.h"
#include "MaxHeap.h"

class Pair
{
	int i;
	int j;
	double dist;
	double distance() {
		return sqrt(i * i + j * j);
	}
public:
	Pair():i(0), j(0){}
	Pair(int x, int y){
		i = x;
		j = y;
		dist = distance();
	}
	bool operator < (Pair& point) {
		return dist < point.dist ? 1 : 0;
	}
	bool operator > (Pair& point) {
		return dist > point.dist ? 1 : 0;
	}
	int getI() { return i; }
	int getJ() { return j; }
};

KClosestToOrigin::KClosestToOrigin()
{
	file.open("KClosestToOriginInput.txt");
}

void KClosestToOrigin::solve()
{
	fillInput();
	kClosest(points, K);
	return;	
}

vector<vector<int>> KClosestToOrigin::kClosest(vector<vector<int>>& points, int K)
{
	MaxHeapT<Pair> heap;
	for (int i = 0; i < points.size(); i++) {
		Pair p(points[i][0], points[i][1]);
		if (heap.size() < K) {
			heap.insert(p);
			continue;
		}
		Pair top = heap.top();
		if (p < top) {
			heap.removeMax();
			heap.insert(p);
		}
	}
	vector<vector<int>> retVals;
	while (heap.size()) {
		vector<int> pairs;
		Pair p = heap.top();
		heap.removeMax();
		pairs.push_back(p.getI());
		pairs.push_back(p.getJ());
		retVals.push_back(pairs);
	}
	
	return retVals;
}


void KClosestToOrigin::fillInput()
{
	string line = getNextLine();
	std::stringstream s(line);
	string tmp;
	int i = 0;
	vector<int> pair;
	while (getline(s, tmp, ','))
	{
		pair.push_back(stoi(tmp));
		i++;
		if (i == 2) {
			points.push_back(pair);
			pair.clear();
			i = 0;
		}
	}
	line = getNextLine();
	K = stoi(line);
}

#pragma once
#include "Solution.h"


class Node {
	int col;
	int row;
	int height;
	int dist;
public:
	Node() :col(0), row(0), height(0), dist(INT_MAX) {}
	Node(int i, int j, int h) :col(j), row(i), height(h),dist(INT_MAX) {}
	int getDistance() {
		return dist;
	}
	int updateDistance(int distance) {
		dist = distance;
		return 0;
	}
	int getHeight() { return height; }
	int getCol() { return col; }
	int getRow() { return row; }
	bool operator < (Node &node) {
		return dist < node.dist;
	}
	bool operator > (Node &node) {
		return dist > node.dist;
	}
};

class SwimInWater :
	public Solution
{
	vector<vector<int>> grid;
public:
	SwimInWater();
	void solve();
	int findNode(vector<Node *> &heap, int c, int r);
	int swimInWater(vector<vector<int>>& grid);
	void fillInput();
};


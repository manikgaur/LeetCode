#include "SwimInWater.h"
#include "MinHeap.h"


SwimInWater::SwimInWater()
{
	file.open("SwimInWaterInput.txt");
}

void SwimInWater::solve()
{
	fillInput();
	cout << swimInWater(grid);
	return;
}
/*
nodes , i,j, dist from origin
apply dijkstra algo
using heap.
*/

int SwimInWater::swimInWater(vector<vector<int>>& grid)
{
	MinHeapT<Node *> heap;
	vector<vector<Node *>> nodeData;
	for (int i = 0; i < grid.size(); i++) {
		vector<Node *> nodeRow;
		for (int j = 0; j < grid.size(); j++) {
			Node *p = new Node(i, j, grid[i][j]);
			if (i == 0 && j == 0)
				p->updateDistance(grid[i][j]);
			heap.insert(p);
			nodeRow.push_back(p);
		}
		nodeData.push_back(nodeRow);
	}
	int s = grid.size() - 1;
	while (heap.size()) {
		Node *p = heap.top();
		heap.removeMin();
		int r = p->getRow();
		int c = p->getCol();
		int h = p->getDistance();

		if (r > 0) {
			// r-1, c
			Node *n = nodeData[r - 1][c];
			int index = heap.findElement(n);
			if (index >= 0) {
				n->updateDistance(n->getHeight());
				if (h > n->getDistance()) {
					n->updateDistance(h);
				}
				heap.modifyElement(index);
			}
		}
		if (c > 0) {
			// r, c-1
			Node *n = nodeData[r][c - 1];
			int index = heap.findElement(n);
			if (index >= 0) {
				n->updateDistance(n->getHeight());
				if (h > n->getDistance()) {
					n->updateDistance(h);
				}
				heap.modifyElement(index);
			}
		}
		if (r < s) {
			// r+1, c
			Node *n = nodeData[r + 1][c];
			int index = heap.findElement(n);
			if (index >= 0) {
				n->updateDistance(n->getHeight());
				if (h > n->getDistance()) {
					n->updateDistance(h);
				}
				heap.modifyElement(index);
			}
		}
		if (c < s) {
			// r, c+1
			Node *n = nodeData[r][c + 1];
			int index = heap.findElement(n);
			if (index >= 0) {
				n->updateDistance(n->getHeight());
				if (h > n->getDistance()) {
					n->updateDistance(h);
				}
				heap.modifyElement(index);
			}
		}
	}

	return nodeData[s][s]->getDistance();
}

void SwimInWater::fillInput()
{
	string line = getNextLine();
	line.erase(std::remove(line.begin(), line.end(), '['), line.end());

	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		int i = 0;
		while (getline(s, tmp, ']'))
		{
			vector<int> vRow;
			if (tmp.length()) {
				std::stringstream row(tmp);
				while (getline(row, tmp, ','))
				{
					if (tmp.length())
						vRow.push_back(stoi(tmp));
				}
				grid.push_back(vRow);
			}
			i++;
		}
	}
}

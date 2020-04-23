#include "SumEvenGrandParents.h"
#include <sstream>
#include <vector>
#include <list>

SumEvenGrandParents::SumEvenGrandParents()
{
	file.open("inputsumEventGrandparent.txt");
	root = NULL;
}


void SumEvenGrandParents::fillInput()
{
	string line = getNextLine();
	vector<int> data;
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			data.push_back(stoi(tmp));
		}
	}
	vector<int>::iterator it = data.begin();
	list<TreeNode *> queue;
	TreeNode *parent;
	for (; it != data.end(); it++) {
		if (root == NULL) {
			int ele = *it;
			if (ele) {
				TreeNode *p = new TreeNode(ele);
				root = p;
				queue.push_back(root);
			}
		}
		else {
			it--;
		}

		parent = queue.front();
		queue.pop_front();
		for (int i = 0; i < 2; i++) {
			it++;
			int ele = *it;
			if (ele) {
				TreeNode *p = new TreeNode(ele);
				if (!i)
					parent->left = p;
				else
					parent->right = p;
				queue.push_back(p);
			}
		}
	}
}

int SumEvenGrandParents::DFS(TreeNode *root, int retSum)
{
	if (root == NULL)
		return 0;
	int sum = 0;
	if (root->left) {
		if (retSum)
			sum += root->left->val;
		sum += DFS(root->left, !(root->val % 2));
	}
	if (root->right) {
		if (retSum)
			sum += root->right->val;
		sum += DFS(root->right, !(root->val % 2));
	}
	return sum;
}

int SumEvenGrandParents::sumEvenGrandparent(TreeNode* root) {
	return DFS(root, 0);
}

void SumEvenGrandParents::solve()
{
	fillInput();
	cout << sumEvenGrandparent(root) << endl;
}

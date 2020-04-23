#include "DeepestLeavesSumSolution.h"

#include <sstream>
#include <vector>
#include <list>

DeepestLeavesSumSolution::DeepestLeavesSumSolution()
{
	file.open("deepestleavesInput.txt");
	root = NULL;
}


void DeepestLeavesSumSolution::fillInput()
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

int DeepestLeavesSumSolution::DFS(TreeNode *root, int &deepestLevel, int currentLevel)
{
	if (root == NULL)
		return 0;
	int sum = 0;

	if (root->left == NULL && root->right == NULL) {
		if (deepestLevel <= currentLevel) {
			deepestLevel = currentLevel;
			return root->val;
		}
	}
	int leftSum = 0;
	int leftDeep = 0;
	if (root->left) {
		leftSum = DFS(root->left, deepestLevel, currentLevel + 1);
		leftDeep = deepestLevel;
	}
	int rightSum = 0;
	int rightDeep = 0;
	if (root->right) {
		rightSum = DFS(root->right, deepestLevel, currentLevel + 1);
		rightDeep = deepestLevel;
	}

	if (leftDeep == rightDeep)
		return leftSum + rightSum;

	return rightDeep > leftDeep ? rightSum : leftSum;
}

int DeepestLeavesSumSolution::deepestLeavesSum(TreeNode* root) {
	int deepestLevel = 0;
	return DFS(root, deepestLevel, 0);
}

void DeepestLeavesSumSolution::solve()
{
	fillInput();
	cout << deepestLeavesSum(root) << endl;
}

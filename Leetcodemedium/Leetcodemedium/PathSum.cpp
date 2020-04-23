#include "PathSum.h"

#include <sstream>
#include <vector>
#include <list>

PathSum::PathSum()
{
	file.open("PathSumInput.txt");
	root = NULL;
	sum = 0;
}


void PathSum::fillInput()
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
			if (it != data.end()) {
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
}

int PathSum::DFS(TreeNode *root, int sum, int currentSum, vector<int> &traverse, vector<vector<int>> &result)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL) {
		if (sum == currentSum + root->val) {
			traverse.push_back(root->val);
			result.push_back(traverse);
			traverse.pop_back();
			return 0;
		}
	}

	currentSum += root->val;
	traverse.push_back(root->val);
	if(root->left)
		DFS(root->left, sum, currentSum, traverse, result);
	if (root->right)
		DFS(root->right, sum, currentSum, traverse, result);
	currentSum -= root->val;
	traverse.pop_back();
	return 0;
}

vector<vector<int>> PathSum::pathSum(TreeNode* root, int sum) {
	vector<vector<int>> result;
	vector<int> traverse;
	DFS(root, sum, 0, traverse, result);
	return result;
}

void PathSum::solve()
{
	fillInput();
	pathSum(root, 22);
}
#include "BTFromInPre.h"

BTFromInPre::BTFromInPre()
{
	file.open("BTFromInPreInput.txt");
}

void BTFromInPre::solve()
{
	fillInput();
	buildTree(inorder, pre);
	return;
}

int BTFromInPre::findIndex(vector<int>& inorder, int ele, int start, int end)
{
	for (int i = start; i <= end; i++) {
		if (inorder[i] == ele)
			return i;
	}
	return -1;
}

TreeNode * BTFromInPre::build(vector<int>& preorder, vector<int>& inorder, int index, int start, int end)
{
	if (index >= preorder.size())
		return nullptr;
	if (end < 0 || start >= inorder.size())
		return nullptr;
	int ele = preorder[index];
	int rootIndex = findIndex(inorder, ele, start, end);
	if (rootIndex < start || rootIndex > end)
		return nullptr;

	TreeNode *root = new TreeNode(ele);

	if (root->right = build(preorder, inorder, index - 1, rootIndex + 1, end)) {
		index -= end - rootIndex;
	}
	root->left = build(preorder, inorder, index - 1, start, rootIndex - 1);
	return root;
}

TreeNode * BTFromInPre::buildTree(vector<int>& preorder, vector<int>& inorder)
{
	return build(inorder, preorder, preorder.size() - 1, 0, preorder.size() - 1);
}

void BTFromInPre::fillInput()
{
	string line = getNextLine();
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			inorder.push_back(stoi(tmp));
		}
	}
	line = getNextLine();
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			pre.push_back(stoi(tmp));
		}
	}
}

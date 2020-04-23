#include "BTFromPrePost.h"


BTFromPrePost::BTFromPrePost()
{
	file.open("BTFromPrePostInput.txt");
}

int BTFromPrePost::findElement(vector<int>p, int ele, int index) 
{
	for (int i = index; i >= 0; i--) {
		if (p[i] == ele)
			return i;
	}
	return -1;
}
TreeNode* BTFromPrePost::construct(vector<int>& pre, vector<int>& post, int i, int j) 
{
	if (i >= pre.size() || j < 0)
		return nullptr;
	if (pre[i] != post[j])
		return nullptr;
	if (visited[pre[i]])
		return nullptr;
	TreeNode *root = new TreeNode(pre[i]);
	i++;
	j--;
	if (i < pre.size())
		root->left = construct(pre, post, i, findElement(post, pre[i], j+1));
	if (j >= 0) {
		root->right = construct(pre, post, findElement(pre, post[j], pre.size() - 1), j);
	}
	visited[root->val] = true;
	return root;
}
TreeNode* BTFromPrePost::constructFromPrePost(vector<int>& pre, vector<int>& post)
{
	TreeNode* root = construct(pre, post, 0, post.size()-1);
	return root;
}

void BTFromPrePost::fillInput()
{
	string line = getNextLine();
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			pre.push_back(stoi(tmp));
		}
	}
	line = getNextLine();
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			post.push_back(stoi(tmp));
		}
	}
}
void BTFromPrePost::solve()
{
	fillInput();
	constructFromPrePost(pre, post);
	return;
}

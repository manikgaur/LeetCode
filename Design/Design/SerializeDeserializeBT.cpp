#include "SerializeDeserializeBT.h"

SerializeDeserializeBT::SerializeDeserializeBT()
{
	file.open("SerializeDeserializeBTInput.txt");
}

string SerializeDeserializeBT::serialize(TreeNode * root)
{
	if (root == NULL)
		return "null";
	string res;
	list<TreeNode *> queue;
	queue.push_back(root);
	while (queue.size())
	{
		TreeNode* node = queue.front();
		queue.pop_front();
		if (node == NULL) {
			res.append("null,");
			continue;
		}
		else {
			res.append(to_string(node->val));
			res.push_back(',');
		}
		if (node->left != NULL)
			queue.push_back(node->left);
		else queue.push_back(NULL);
		if (node->right != NULL)
			queue.push_back(node->right);
		else queue.push_back(NULL);
	}
	//res[res.length() - 1] = 0;
	return res;
}

TreeNode * SerializeDeserializeBT::deserialize(string data)
{
	TreeNode *node = nullptr;
	list<TreeNode*> queue;
	if (data.length()) {
		std::stringstream s(data);
		string tmp;
		getline(s, tmp, ',');
		if (tmp != "null") {
			node = new TreeNode(stoi(tmp));
			queue.push_back(node);
		}
		while (queue.size()) {
			TreeNode *p = queue.front();
			queue.pop_front();
			int i = 2;
			while (i && getline(s, tmp, ',')) {
				if (tmp != "null") {
					int val = stoi(tmp);
					if (i == 2) {
						p->left = new TreeNode(val);
						queue.push_back(p->left);
					}
					if (i == 1) {
						p->right = new TreeNode(val);
						queue.push_back(p->right);
					}
				}
				i--;
			}
		}
	}
	return node;
}

void SerializeDeserializeBT::solve()
{
	fillInput();
	serializeBT = serialize(root);
	cout << deserialize(serializeBT);
	return;
}

void SerializeDeserializeBT::fillInput()
{
	getBinaryTree(&root);
}

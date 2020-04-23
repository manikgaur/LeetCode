#pragma once
#include "Solution.h"
class SerializeDeserializeBT :
	public Solution
{
	TreeNode* root;
	string serializeBT;
public:
	SerializeDeserializeBT();
	string serialize(TreeNode* root);
	TreeNode* deserialize(string data);
	void solve();
	void fillInput();
};


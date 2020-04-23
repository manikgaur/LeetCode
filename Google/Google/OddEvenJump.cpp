#include "OddEvenJump.h"

OddEvenJump::OddEvenJump()
{
	file.open("OddEvenJumpInput.txt");
//	freopen("output2.txt", "w", stdout);
}

BSTNode* OddEvenJump::insertInBST(BSTNode* root, vector<int>& A, int pos, unordered_map<int, BSTNode*>& data, int rMax, int rMin) {
	if (root == NULL) {
		root = new BSTNode(A[pos], pos);
		root->rightMax = rMax;
		root->rightMin = rMin;
		data[pos] = root;
		return root;
	}

	if (A[pos] < root->val) {
		if (root->right && root->right->val == root->val) {
				root->right = insertInBST(root->right, A, pos, data, rMax, root->pos);
		}
		else
		root->left = insertInBST(root->left, A, pos, data, root->pos, rMin);
	}
	else if (A[pos] > root->val) {
		root->right = insertInBST(root->right, A, pos, data, rMax, root->pos);
	}
	else {
		root->right = insertInBST(root->right, A, pos, data, root->pos, root->pos);
	}


	return root;
}

BSTNode* OddEvenJump::insertInBST2(BSTNode* root, vector<int>& A, int pos, unordered_map<int, BSTNode*>& data, int rMax, int rMin) {

	if (root == NULL) {
		root = new BSTNode(A[pos], pos);
		root->rightMax = rMax;
		root->rightMin = rMin;
		data[pos] = root;
		return root;
	}

	if (A[pos] < root->val) {
		root->left = insertInBST2(root->left, A, pos, data, root->pos, rMin);
	}
	else if (A[pos] > root->val) {
		root->right = insertInBST2(root->right, A, pos, data, rMax, root->pos);
	}
	else {
		return insertInBST2(root->middle, A, pos, data, root->pos, root->pos);
	}
	return root;
}

bool OddEvenJump::isPossible(unordered_map<int, BSTNode*>& data, int startPos, int endPos, int evenOdd)
{
	if (startPos == endPos)
		return true;
	if (startPos == -1)
		return false;

	if (evenOdd == 1) {
		return isPossible(data, data[startPos]->rightMax, endPos, !evenOdd);
	}
	else {
		return isPossible(data, data[startPos]->rightMin, endPos, !evenOdd);
	}
	return false;
}
/*
int OddEvenJump::oddEvenJumpsX(vector<int>& A)
{
	BSTNode* root = NULL;
	unordered_map<int, BSTNode*> data;
	unordered_map<int, BSTNode*> data2;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		root = insertInBST(root, A, i, data, -1, -1);
	}
	root = NULL;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		root = insertInBST2(root, A, i, data2, -1, -1);
	}
	int count = 0;
	for (int i = 0; i < A.size(); i++)
	{
//		count += isPossible(data, i, A.size() - 1, 1);
		count += isPossible(data2, i, A.size() - 1, 1);
	}
	return count;

}
*/
int OddEvenJump::oddEvenJumps(vector<int>& A)
{
	if (A.size() < 2)
		return A.size();
	map<int, int> data;
	vector<vector<int>> oe(2, vector<int>(A.size(), 0));
	int size = A.size();
	data[A[size - 1]] = size - 1;
	oe[0][size - 1] = oe[1][size - 1] = 1;
	int cnt = 1;
	for (int i = size - 2; i >= 0; i--)
	{
		map<int, int>::iterator itL = data.upper_bound(A[i]);
		map<int, int>::iterator itR = data.lower_bound(A[i]);
		if (itR != data.end()) {
            oe[1][i] = oe[0][itR->second];
		}
		if (itL != data.begin()) {
			itL--;
			oe[0][i] = oe[1][itL->second];
		}
		cnt += oe[1][i];
		data[A[i]] = i;
	}
	return cnt;
}

void OddEvenJump::solve()
{
	fillInput();
	cout << oddEvenJumps(nums);
	return;
}

void OddEvenJump::fillInput()
{
	getIntArray(nums);
}

#include "CountLessAfterSelf.h"

CountLessAfterSelf::CountLessAfterSelf()
{
	file.open("countLessAfterSelfInput.txt");
	root = NULL;
}

vector<int> CountLessAfterSelf::countSmaller(vector<int>& nums)
{
	vector<int> result;
	AVLNode *root = NULL;
	if (nums.size()) {
		root = new AVLNode();
		root->setVal(nums.back());
	}
	else 
		return vector<int>();

	result.push_back(0);
	for (int i = nums.size() - 2; i >= 0; i--) {
		int count = 0;
		if (nums[i] == 6548)
			int j = 0;
		root = root->insertElement(nums[i], count);
		result.push_back(count);
	}
	reverse(result.begin(), result.end());
	return result;
}

void CountLessAfterSelf::fillInput()
{
	string line = getNextLine();
	std::stringstream s(line);
	string tmp;
	while (getline(s, tmp, ','))
	{
		nums.push_back(stoi(tmp));
	}
}

void CountLessAfterSelf::solve()
{
	fillInput();
	countSmaller(nums);
}


AVLNode *AVLNode::insertElement(int Element, int &count)
{
	AVLNode *root = this;
	nodeCount++;
	if (Element <= val) {
		if(left)
			left = left->insertElement(Element, count);
		else {
			left = new AVLNode();
			left->val = Element;
		}
	}
	else {
		count += 1;
		if(left)
			count += left->nodeCount;
		if (right)
			right = right->insertElement(Element, count);
		else {
			right = new AVLNode();
			right->val = Element;
		}
	}
	if(left && right)
		hight = left->hight > right->hight ? left->hight+1 : right->hight+1;
	else
	{
		hight = left ? left->hight + 1 : right->hight + 1;
	}
	int leftH = left ? left->hight : -1;
	int rightH = right ? right->hight : -1;

	int diff = leftH - rightH;

	if (abs(diff) > 1) {
		root = adjustHight(diff, Element);
	}
	return root;
}

AVLNode * AVLNode::rightRotate()
{
	AVLNode * root = this;
	AVLNode *X = root->left;

	root->left = X->right;
	X->right = root;
	
	if (root->left && root->right) {
		root->hight = root->left->hight > root->right->hight ? root->left->hight + 1 : root->right->hight + 1;
		root->nodeCount = root->left->nodeCount + root->right->nodeCount + 1;
	}
	else if (!root->left && !root->right) {
		root->hight = 0;
		root->nodeCount = 1;
	}
	else {
		root->hight = root->left ? root->left->hight + 1 : root->right->hight + 1;
		root->nodeCount = root->left ? root->left->nodeCount + 1 : root->right->nodeCount + 1;
	}

	if (X->left && X->right) {
		X->hight = X->left->hight > X->right->hight ? X->left->hight + 1 : X->right->hight + 1;
		X->nodeCount = X->left->nodeCount + X->right->nodeCount + 1;
	}
	else
	{
		X->hight = X->left ? X->left->hight + 1 : X->right->hight + 1;
		X->nodeCount = X->left ? X->left->nodeCount + 1 : X->right->nodeCount + 1;
	}
	root = X;
	return root;
}
AVLNode * AVLNode::leftRotate()
{
	AVLNode * root = this;
	AVLNode *X = root->right;
	AVLNode *Y = X->right;

	root->right = X->left;
	X->left = root;

	if (root->left && root->right) {
		root->hight = root->left->hight > root->right->hight ? root->left->hight + 1 : root->right->hight + 1;
		root->nodeCount = root->left->nodeCount + root->right->nodeCount + 1;
	}
	else if (!root->left && !root->right) {
		root->hight = 0;
		root->nodeCount = 1;
	}
	else {
		root->hight = root->left ? root->left->hight + 1 : root->right->hight + 1;
		root->nodeCount = root->left ? root->left->nodeCount + 1 : root->right->nodeCount + 1;
	}

	if (X->left && X->right) {
		X->hight = X->left->hight > X->right->hight ? X->left->hight + 1 : X->right->hight + 1;
		X->nodeCount = X->left->nodeCount + X->right->nodeCount + 1;
	}
	else
	{
		X->hight = X->left ? X->left->hight + 1 : X->right->hight + 1;
		X->nodeCount = X->left ? X->left->nodeCount + 1 : X->right->nodeCount + 1;
	}
	root = X;
	return root;
}

AVLNode * AVLNode::adjustHight(int & balance, int key)
{
	AVLNode*root = this;
	if (balance > 1 && key <= left->val)
		return rightRotate();

	// Right Right Case  
	if (balance < -1 && key > right->val)
		return leftRotate();

	// Left Right Case  
	if (balance > 1 && key >= left->val)
	{
		left = left->leftRotate();
		return rightRotate();
	}

	// Right Left Case  
	if (balance < -1 && key < right->val)
	{
		right = right->rightRotate();
		return leftRotate();
	}

	return root;
}

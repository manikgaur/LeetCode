#include "Solution.h"

using namespace std;
Solution::Solution() 
{
	
}

string Solution::getNextLine()
{
	string line;
	getline(file, line);
	return line;
}

string Solution::getString()
{
	return getNextLine();
}

void Solution::getStrings(vector<string>& array)
{
	string line = getNextLine();
	line.append(",");
	line.erase(std::remove(line.begin(), line.end(), '['), line.end());
	line.erase(std::remove(line.begin(), line.end(), '"'), line.end());
	line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
	line.erase(std::remove(line.begin(), line.end(), ']'), line.end());

	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		int i = 0;
		while (getline(s, tmp, ','))
		{
			array.push_back(tmp);
		}
	}
}

int Solution::getInt()
{
	return stoi(getNextLine());
}

void Solution::getIntArray(vector<int>& array)
{
	string line = getNextLine();
	line.erase(std::remove(line.begin(), line.end(), '['), line.end());
	line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
	line.erase(std::remove(line.begin(), line.end(), ']'), line.end());

	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		int i = 0;
		while (getline(s, tmp, ','))
		{
			if(!tmp.empty())
				array.push_back(stoi(tmp));
		}
	}
}
void Solution::getFloatArray(vector<double>& array)
{
	string line = getNextLine();
	line.erase(std::remove(line.begin(), line.end(), '['), line.end());
	line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
	line.erase(std::remove(line.begin(), line.end(), ']'), line.end());

	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		int i = 0;
		while (getline(s, tmp, ','))
		{
			if (!tmp.empty())
				array.push_back(stof(tmp));
		}
	}
}


void Solution::get2DStrings(vector<vector<string>>& array)
{
	string line = getNextLine();
	line.erase(std::remove(line.begin(), line.end(), '['), line.end());
	line.erase(std::remove(line.begin(), line.end(), '"'), line.end());

	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		int i = 0;
		while (getline(s, tmp, ']'))
		{
			vector<string> vRow;
			if (tmp.length()) {
				std::stringstream row(tmp);
				while (getline(row, tmp, ','))
				{
					if (tmp.length())
						vRow.push_back(tmp);
				}
				array.push_back(vRow);
			}
			i++;
		}
	}
}

void Solution::get2Darray(vector<vector<int>>& array)
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
				array.push_back(vRow);
			}
			i++;
		}
	}
}

void Solution::getBinaryTree(TreeNode ** root)
{
	string line = getNextLine();
	line.erase(std::remove(line.begin(), line.end(), '['), line.end());
	line.erase(std::remove(line.begin(), line.end(), ']'), line.end());
	TreeNode *node = nullptr;
	list<TreeNode*> queue;
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		getline(s, tmp, ',');
		*root = new TreeNode(stoi(tmp));
		queue.push_back(*root);
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
}

void MaxHeap::heapify(int index)
{
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;
	int max = index;
	if (data.size() > left) {
		if (data[max] < data[left])
			max = left;
	}
	if (data.size() > right) {
		if (data[max] < data[right])
			max = right;
	}
	if (max != index) {
		swap(max, index);
		heapify(max);
	}
}

void MaxHeap::swap(int i, int j)
{
	int tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

void MaxHeap::insert(int ele)
{
	data.push_back(ele);
	int index = data.size() - 1;
	int parent = (index - 1) / 2;
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (data[parent] < data[index]) {
			swap(parent, index);
			index = parent;
		}
		else
			break;
	}
}

void MaxHeap::removeMax()
{
	if (!data.size())
		return;

	if (data.size() == 1) {
		data.pop_back();
		return;
	}

	swap(0, data.size() - 1);
	data.pop_back();
	heapify(0);
}

int MaxHeap::top()
{
	if (data.size())
		return data[0];
	return INT_MAX;
}

void MaxHeap::init(vector<int> nums)
{
	data.assign(nums.begin(), nums.end());
	for (int i = data.size() / 2; i >= 0; i--) {
		heapify(i);
	}
}

void MinHeap::heapify(int index)
{
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;
	int min = index;
	if (data.size() > left) {
		if (data[min] > data[left])
			min = left;
	}
	if (data.size() > right) {
		if (data[min] > data[right])
			min = right;
	}
	if (min != index) {
		swap(min, index);
		heapify(min);
	}
}

void MinHeap::swap(int i, int j)
{
	int tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

void MinHeap::insert(int ele)
{
	data.push_back(ele);
	int index = data.size() - 1;
	int parent = (index - 1) / 2;
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (data[parent] > data[index]) {
			swap(parent, index);
			index = parent;
		}
		else
			break;
	}
}

void MinHeap::removeMin()
{
	if (!data.size())
		return;

	if (data.size() == 1) {
		data.pop_back();
		return;
	}

	swap(0, data.size() - 1);
	data.pop_back();
	heapify(0);
}

int MinHeap::top()
{
	if (data.size())
		return data[0];
	return INT_MAX;
}

void MinHeap::init(vector<int> nums)
{
	data.assign(nums.begin(), nums.end());
	for (int i = data.size() / 2; i >= 0; i--) {
		heapify(i);
	}
}


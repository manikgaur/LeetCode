#pragma once
#include <vector>
#include <map>
using namespace std;
template<typename T>
class MinHeapT
{
	vector<T> data;
	map<T, int> position;
	void heapify(int index);
	void swap(int i, int j);
public:
	MinHeapT() {};
	int size() { return data.size(); }
	void insert(T ele);
	void removeMin();
	T top();
	void init(vector<T> nums);
	int findElement(T ele);
	void modifyElement(int index);
};


template<typename T>
void MinHeapT<T>::heapify(int index)
{
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;
	int min = index;
	if (data.size() > left) {
		if (*data[min] > *data[left])
			min = left;
	}
	if (data.size() > right) {
		if (*data[min] > *data[right])
			min = right;
	}
	if (min != index) {
		swap(min, index);
		heapify(min);
	}
}

template<typename T>
void MinHeapT<T>::swap(int i, int j)
{
	T tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
	position[data[i]] = i;
	position[data[j]] = j;
}

template<typename T>
inline void MinHeapT<T>::insert(T ele)
{
	data.push_back(ele);
	position[ele] = data.size() - 1;
	int index = data.size() - 1;
	int parent = (index - 1) / 2;
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (*data[index] < *data[parent]) {
			swap(parent, index);
			index = parent;
		}
		else
			break;
	}
}

template<typename T>
inline void MinHeapT<T>::removeMin()
{
	if (!data.size())
		return;

	if (data.size() == 1) {
		position.erase(top());
		data.pop_back();
		return;
	}

	swap(0, data.size() - 1);
	position.erase(data.back());
	data.pop_back();
	heapify(0);
}

template<typename T>
inline T MinHeapT<T>::top()
{
	if (data.size())
		return data[0];
	return T();
}

template<typename T>
inline void MinHeapT<T>::init(vector<T> nums)
{
	data.assign(nums.begin(), nums.end());
	for (int i = data.size() / 2; i >= 0; i--) {
		heapify(i);
	}
}

template<typename T>
inline int MinHeapT<T>::findElement(T ele)
{
	if(position.find(ele) == position.end())
		return -1;
	return position.find(ele)->second;
}

template<typename T>
inline void MinHeapT<T>::modifyElement(int index)
{
	int parent = (index - 1) / 2;
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (*data[index] < *data[parent]) {
			swap(parent, index);
			index = parent;
		}
		else
			break;
	}
}

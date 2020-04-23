#pragma once

#include <vector>
#include <map>

using namespace std;
template<typename T>
class MaxHeapT
{
	vector<T> data;
	void heapify(int index);
	void swap(int i, int j);
public:
	MaxHeapT() {};
	int size() { return data.size(); }
	void insert(T ele);
	void removeMax();
	T top();
	void init(vector<T> nums);
};


template<typename T>
void MaxHeapT<T>::heapify(int index)
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

template<typename T>
void MaxHeapT<T>::swap(int i, int j)
{
	T tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

template<typename T>
inline void MaxHeapT<T>::insert(T ele)
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

template<typename T>
inline void MaxHeapT<T>::removeMax()
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

template<typename T>
inline T MaxHeapT<T>::top()
{
	if (data.size())
		return data[0];
	return T();
}

template<typename T>
inline void MaxHeapT<T>::init(vector<T> nums)
{
	data.assign(nums.begin(), nums.end());
	for (int i = data.size() / 2; i >= 0; i--) {
		heapify(i);
	}
}
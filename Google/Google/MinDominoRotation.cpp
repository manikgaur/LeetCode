#include "MinDominoRotation.h"
#include <vector>
#include <sstream>
#include <algorithm>

void MinDominoRotation::fillInput()
{
	string line = getNextLine();
	std::stringstream s(line);
	string tmp;
	while (getline(s, tmp, ','))
	{
		A.push_back(stoi(tmp));
	}
	line = getNextLine();
	stringstream s1(line);
	tmp;
	while (getline(s1, tmp, ','))
	{
		B.push_back(stoi(tmp));
	}
}

int MinDominoRotation::minDominoRotations(vector<int>& A, vector<int>& B) {
	if (A.size() != B.size())
		return -1;
	int minAA = 0;
	int minBB = 0;
	int minAB = 0;
	int minBA = 0;
	int a = A[0];
	int b = B[0];
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] != a) {
			if (B[i] != a) {
				a = -1;
				minAA = A.size() + 1;
			}
			else
				minAA++;
		}
		if (B[i] != a) {
			if (A[i] != a) {
				a = -1;
				minAB = A.size() + 1;
			}
			else
				minAB++;
		}
		if (B[i] != b) {
			if (A[i] != b) {
				b = -1;
				minBB = B.size() + 1;
			}
			else
				minBB++;
		}
		if (A[i] != b) {
			if (B[i] != b) {
				b = -1;
				minBA = B.size() + 1;
			}
			else
				minBA++;
		}
		if (a == -1 && b == -1)
			return -1;
	}
	int min = A.size();
	if (minAA <= A.size()) {
		minAA = (A.size() - minAA) < minAA ? (A.size() - minAA) : minAA;
		if (minAA < min)
			min = minAA;
	}
	if (minBB <= B.size()) {
		minBB = (B.size() - minBB) < minBB ? (B.size() - minBB) : minBB;
		if (minBB < min)
			min = minBB;
	}
	if (minAB <= A.size()) {
		minAB = (A.size() - minAB) < minAB ? (A.size() - minAB) : minAB;
		if (minAB < min)
			min = minAB;
	}
	if (minBA <= B.size()) {
		minBA = (B.size() - minBA) < minBA ? (B.size() - minBA) : minBA;
		if (minBA < min)
			min = minBA;
	}
	return min;
}


MinDominoRotation::MinDominoRotation()
{
	file.open("minDominoRotationInput.txt");
}

void MinDominoRotation::solve()
{
	fillInput();
	minDominoRotations(A, B);
}

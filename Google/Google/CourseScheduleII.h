#pragma once
#include "Solution.h"
class CourseScheduleII :
	public Solution
{
	int n;
	vector<vector<int>> p;
public:
	CourseScheduleII();
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
	int longestIncreasingPath(vector<vector<int>>& matrix);
	void solve();
	void fillInput();
};


#pragma once
#include "Solution.h"
class StudentAttendanceRecord :
	public Solution
{
	int N;
public:
	StudentAttendanceRecord();
	int checkRecord(int n);
	void solve();
	void fillInput();
};


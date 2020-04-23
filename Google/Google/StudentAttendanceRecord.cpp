#include "StudentAttendanceRecord.h"

StudentAttendanceRecord::StudentAttendanceRecord()
{
	file.open("StudentAttendanceRecordInput.txt");
}

int StudentAttendanceRecord::checkRecord(int n)
{
	if (N == 0)
		return 0;
	if (N == 1)
		return 3;
	int m = 1000000007;
	int lastA[4] = { 0, };
	int lastP[4] = { 0, };
	int lastL[4] = { 0, };
	lastA[1] = 1;
	lastA[2] = 2;
	lastA[3] = 4;
	lastP[1] = 1;
	lastP[2] = 3;
	lastL[1] = 1;
	lastL[2] = 3;
	for (int i = 3; i <= N; i++) {
		lastP[i % 4] = ((lastP[(i - 1) % 4] + lastA[(i - 1) % 4]) % m + lastL[(i - 1) % 4]) % m;
		lastL[i % 4] = ((lastP[(i - 1) % 4] + lastA[(i - 1) % 4]) % m +
			(lastP[(i - 2) % 4] + lastA[(i - 2) % 4]) % m) % m;
		if (i > 3)
			lastA[i % 4] = ((lastA[(i - 1) % 4] + lastA[(i - 2) % 4]) % m + 
				lastA[(i - 3) % 4]) % m;
	}
	return ((lastA[N % 4] + lastP[N % 4]) % m + lastL[N % 4]) % m;
}

void StudentAttendanceRecord::solve()
{
	fillInput();
	cout << checkRecord(N);
	return;
}

void StudentAttendanceRecord::fillInput()
{
	N = getInt();
}

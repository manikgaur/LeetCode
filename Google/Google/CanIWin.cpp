#include "CanIWin.h"

CanIWin::CanIWin()
{
	file.open("CanIWinInput.txt");
}

bool isPossible(vector<bool> nums, int total) {
	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		if(nums[i])
			count += i;
	}
	if (count < total)
		return false;
	return true;
}

bool isWinningPossible(vector<bool>& nums, int desiredTotal, unordered_map<string, bool>& memo)
{
	if (desiredTotal == 0)
		return true;
	string hashkey;
	hashkey.resize(nums.size());
	for (int i = 1; i < nums.size(); i++) {
		hashkey[i] = nums[i];
	}
	if (memo.find(hashkey) != memo.end()) {
		return memo[hashkey];
	}
	bool res = false;
	for (int i = nums.size() - 1; i > 0; i--) {
		if (nums[i]) {
			nums[i] = false;
			if (i >= desiredTotal || !isWinningPossible(nums, desiredTotal - i, memo)) {
				res = true;
				nums[i] = true;
				break;
			}
			nums[i] = true;
		}
	}
	memo[hashkey] = res;
	return res;
}

bool CanIWin::canIWin(int maxChoosableInteger, int desiredTotal)
{
	if (desiredTotal == 0)
		return true;
	vector<bool> nums(maxChoosableInteger+1, 1);
	if (!isPossible(nums, desiredTotal))
		return false;
	unordered_map<string, bool> memo;
	return isWinningPossible(nums, desiredTotal, memo);
}

void CanIWin::solve()
{
	fillInput();
	cout << canIWin(a, b);
	return;
}

void CanIWin::fillInput()
{
	a = getInt();
	b = getInt();
}

#pragma once
#include "Solution.h"
class BestTimeBuySellStock :
	public Solution
{
	int fee;
	vector<int> prices;
	vector<vector<int>> data;
public:
	BestTimeBuySellStock();
	int maxProfitWithTransactionFee2(vector<int>& prices, int fee);
	int maxProfitWithKTransactions(vector<int>& prices, int k);
	int maxProfitWith2Transactions(vector<int>& prices);
	int maxProfitWithCooldown(vector<int>& prices);
	int maxProfitWithTransactionFee(vector<int>& prices, int fee, int s, int e);
	int maxProfit(vector<int>& prices, int fee);
	void solve();
	void fillInput();
};


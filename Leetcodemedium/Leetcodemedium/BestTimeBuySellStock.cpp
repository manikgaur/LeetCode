#include "BestTimeBuySellStock.h"

BestTimeBuySellStock::BestTimeBuySellStock()
{
	file.open("BestTimeBuySellStockInput.txt");
}

int BestTimeBuySellStock::maxProfitWithTransactionFee2(vector<int>& prices, int fee)
{
	int n = prices.size();
	if (n <= 1)
		return 0;

	int lastbuy = -1 * prices[0] - fee;
	int lastsell = 0;
	int tmp = lastbuy;
	for (int i = 1; i < n; i++) {
		tmp = lastbuy;
		lastbuy = max(lastbuy, lastsell - prices[i] - fee);
		lastsell = max(lastsell, tmp + prices[i]);
	}
	return lastsell;

}
int BestTimeBuySellStock::maxProfitWithKTransactions(vector<int>& prices, int k)
{
	int n = prices.size();
	if (n < 2 || k < 1)
		return 0;

	if (k > n / 2) {
		int maxProfit = 0;
		for (int i = 1; i < n; i++)
			maxProfit += max(prices[i] - prices[i - 1], 0);
		return maxProfit;
	}

	vector<int> buy(k, INT_MIN);
	vector<int> sell(k, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (j == 0) {
				buy[j] = max(buy[j], -1 * prices[i]);
				sell[j] = max(sell[0], buy[0] + prices[i]);
			}
			else {
				buy[j] = max(buy[j], sell[j-1] - prices[i]);
				sell[j] = max(sell[j], buy[j] + prices[i]);
			}
		}
	}
	return sell[k-1];
}
int BestTimeBuySellStock::maxProfitWith2Transactions(vector<int>& prices)
{
	int n = prices.size();
	if (n <= 1)
		return 0;
	
	int firstBuy = -1 * prices[0];
	int firstSell = 0;
	int secondBuy = -1 * prices[0];
	int secondSell = 0;
	int tmpBuy = firstBuy;
	int tmp2Buy;
	for (int i = 1; i < n; i++) {
		tmpBuy = firstBuy;
		tmp2Buy = secondBuy;
		firstBuy = max(firstBuy, -1 * prices[i]);
		firstSell = max(firstSell, tmpBuy + prices[i]);
		secondBuy = max(secondBuy, firstSell - prices[i]);
		secondSell = max(secondSell, tmp2Buy + prices[i]);
	}
	return secondSell;

}


int BestTimeBuySellStock::maxProfitWithCooldown(vector<int>& prices)
{
	int n = prices.size();
	if (n <= 1)
		return 0;
	if (n == 2)
		return prices[1] - prices[0];

	int lastbuy = -1 * prices[0];
	int lastsell = 0;
	int tmp = lastbuy;
	int tmpSell = 0;
	for (int i = 1; i < n; i++) {
		tmp = lastbuy;
		lastbuy = max(lastbuy, tmpSell - prices[i]);
		tmpSell = lastsell;
		lastsell = max(lastsell, tmp + prices[i]);
	}
	return lastsell;

}

int BestTimeBuySellStock::maxProfitWithTransactionFee(vector<int>& prices, int fee, int s, int e)
{
	if (s == e)
		return 0;
	if (e - s == 1)
		return prices[e] - prices[s] - fee;
	if (data[s][e] != -1)
		return data[s][e];
	int maxPrice = 0;
	int minPrice = prices[s];
	for (int i = s; i <= e; i++) {
		maxPrice = max(maxPrice, prices[i] - minPrice-fee);
		minPrice = min(minPrice, prices[i]);
	}
	int lMax = 0;
	int rMax = 0;
	for (int i = s; i < e; i++) {
		lMax = maxProfitWithTransactionFee(prices, fee, s, i);
		rMax = maxProfitWithTransactionFee(prices, fee, i+1, e);
		maxPrice = max(maxPrice, lMax + rMax);
	}
	data[s][e] = maxPrice;
	return maxPrice;
}

int BestTimeBuySellStock::maxProfit(vector<int>& prices, int fee)
{
	if (prices.size() <= 1)
		return 0;
	int n = prices.size();
	data = vector<vector<int>>(n, vector<int>(n, -1));
	//return maxProfitWithTransactionFee(prices, fee, 0, prices.size()-1);
	//return maxProfitWithTransactionFee2(prices, fee);
	//return maxProfitWithCooldown(prices);
	//return maxProfitWith2Transactions(prices);
	return maxProfitWithKTransactions(prices, fee);
}

void BestTimeBuySellStock::solve()
{
	fillInput();
	cout << maxProfit(prices, fee);
	return;
}

void BestTimeBuySellStock::fillInput()
{
	string line = getNextLine();
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			prices.push_back(stoi(tmp));
		}
	}
	line = getNextLine();
	fee = stoi(line);
}

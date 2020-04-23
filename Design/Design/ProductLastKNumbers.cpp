#include "ProductLastKNumbers.h"

ProductLastKNumbers::ProductLastKNumbers()
{
	file.open("HashMapInput.txt");
}

	class ProductOfNumbers {
		vector<int> products;
		set<int> zeroPos;
	public:
		ProductOfNumbers() {

		}

		void add(int num) {
			int size = products.size();
			if (size == 0 || num == 0 || products.back() == 0)
			{
				products.push_back(num);
				if (num == 0) zeroPos.insert(size);
				return;
			}
			products.push_back(num * products.back());
		}

		int getProduct(int k) {
			int size = products.size();
			int pos = size - k;

			int div;
			if (k == size)
				div = 1;
			else {
				div = products[size - k - 1];
			}
			auto it = zeroPos.lower_bound(pos);
			if (it != zeroPos.end())
				return 0;
		
			if (div == 0)
				return products.back();
			return products.back() / div;
		}
	};

void ProductLastKNumbers::solve()
{
	fillInput();
	ProductOfNumbers obj;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "add")
			obj.add(qData[i-1]);
		else if (queries[i] == "getProduct")
			cout << obj.getProduct(qData[i-1]);
	}
	return;
}

void ProductLastKNumbers::fillInput()
{
	getStrings(queries);
	getIntArray(qData);
}

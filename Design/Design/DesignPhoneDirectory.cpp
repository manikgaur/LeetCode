#include "DesignPhoneDirectory.h"

DesignPhoneDirectory::DesignPhoneDirectory()
{
	file.open("DesignPhoneDirectory.txt");
}
class PhoneDirectory {
	unordered_map<int, bool> dictionary;
public:
	/** Initialize your data structure here
		@param maxNumbers - The maximum numbers that can be stored in the phone directory. */
	PhoneDirectory(int maxNumbers) {
		for (int i = 0; i < maxNumbers; i++)
			dictionary[i] = true;
	}

	/** Provide a number which is not assigned to anyone.
		@return - Return an available number. Return -1 if none is available. */
	int get() {
		if (!dictionary.size())
			return 0;
		auto it = dictionary.begin();
		int res = it->first;
		dictionary.erase(it);
		return res;
	}

	/** Check if a number is available or not. */
	bool check(int number) {
		if (dictionary.find(number) == dictionary.end())
			return false;
		return true;
	}

	/** Recycle or release a number. */
	void release(int number) {
		dictionary[number] = true;
	}
};
void DesignPhoneDirectory::solve()
{
	fillInput();
	PhoneDirectory obj(qData[0]);
	int j = 1;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "get") {
			cout << obj.get();
		}
		if (queries[i] == "check") {
			obj.check(qData[j++]);
		}
		if (queries[i] == "release") {
			obj.release(qData[j++]);
		}
	}
	return;
}

void DesignPhoneDirectory::fillInput()
{
	getStrings(queries);
	getIntArray(qData);
}

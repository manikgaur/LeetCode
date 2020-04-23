#include "LoggerRateLimiter.h"

LoggerRateLimiter::LoggerRateLimiter()
{
	file.open("LoggerRateLimiter.txt");
}
class Logger {
	unordered_map<string, int> logger;
	int maxDiff;
public:
	/** Initialize your data structure here. */
	Logger() {
		maxDiff = 10;
	}

	/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
		If this method returns false, the message will not be printed.
		The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, string message) {
		if (logger.find(message) == logger.end()) {
			logger[message] = timestamp;
			return true;
		}
		if (logger[message] <= timestamp - maxDiff) {
			logger[message] = timestamp;
			return true;
		}
		return false;
	}
};
void LoggerRateLimiter::solve()
{
	fillInput();
	Logger obj;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "shouldPrintMessage") {
			cout << obj.shouldPrintMessage(stoi(qData[i - 1][0]), qData[i - 1][1]) << endl;
		}
	}
	return;
}

void LoggerRateLimiter::fillInput()
{
	getStrings(queries);
	get2DStrings(qData);
}

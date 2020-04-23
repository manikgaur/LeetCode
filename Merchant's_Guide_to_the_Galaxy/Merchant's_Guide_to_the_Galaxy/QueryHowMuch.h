#ifndef H_QUERIES_HOW_MUCH
#define H_QUERIES_HOW_MUCH
#include "Queries.h"
#include <string>
class QueryHowMuch :
	public Queries
{
public:
	QueryHowMuch() {}
	string prepareResult(int value);
	string prepareResult(string initial, int value);
	string evaluateString(string code);
};

#endif


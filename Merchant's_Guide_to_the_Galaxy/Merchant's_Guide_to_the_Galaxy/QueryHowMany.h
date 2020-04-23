#ifndef H_QUERIES_HOW_MANY
#define H_QUERIES_HOW_MANY
#include "Queries.h"
#include <string>
class QueryHowMany :
	public Queries
{
public:
	QueryHowMany() {}
	string prepareResult(string initial, int value);
	string evaluateString(string code);
};

#endif


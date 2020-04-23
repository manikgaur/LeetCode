#ifndef H_QUERIES
#define H_QUERIES

#include <string>
using namespace std;
class Queries
{
public:
	Queries() {}
	virtual string evaluateString(string code) = 0;
};
#endif // !H_QUERIES


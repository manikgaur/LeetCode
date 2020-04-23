#include "Parser.h"
#include "QueryHowMany.h"
#include "QueryHowMuch.h"
#include "Metals.h"
#include "Codes.h"

using namespace std;

Parser::Parser()
{

}
string Parser::parseString(string code)
{
	const char *str = code.c_str();
	string retVal;
	if (code.find("how much is") != string::npos)
	{
		Queries *queries = new QueryHowMuch();
		return queries->evaluateString(code);
	}
	else if (code.find("how many Credits is") != string::npos)
	{
		Queries *queries = new QueryHowMany();
		return queries->evaluateString(code);
	}
	else if (code.find(" is") != string::npos)
	{
		if (code.find(" Credits") != string::npos)
		{
			Metals *metals = Metals::getInstance();
			return metals->evaluateString(code);
		}
		else
		{
			Codes *codes = Codes::getInstance();
			return codes->evaluateString(code);
		}
	}
	else
	{
		retVal = "I have no idea what you are talking about";
	}
	return retVal;
}
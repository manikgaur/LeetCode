#pragma once
#include "Solution.h"
class EvaluateDivision :
	public Solution
{
	vector<vector<string>> equations;
	vector<double> values; 
	vector<vector<string>> queries;
public:
	EvaluateDivision();
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);
	double getQueryResult(string n, string d, map<string, list<string>>& divGraph, map<pair<string, string>, double>& divResults, map<string, bool>& visited);
	void solve();
	void fillInput();
};


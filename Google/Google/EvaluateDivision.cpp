#include "EvaluateDivision.h"

EvaluateDivision::EvaluateDivision()
{
	file.open("EvaluateDivisionInput.txt");
}
double EvaluateDivision::getQueryResult(string n, string d, map<string, list<string>>& divGraph, map<pair<string, string>, double>& divResults, map<string, bool>& visited)
{
	if (n == d)
	{
		return 1.0;
	}
	double res = -1.0;
	visited[n] = true;
	if (divGraph.find(n) != divGraph.end()) {
		auto it = divGraph[n].begin();
		while (it != divGraph[n].end())
		{
			if (!visited[*it]) {
				double ret = getQueryResult(*it, d, divGraph, divResults, visited);
				if (ret != -1.0) {
					res = ret * divResults[{n,*it}];
					break;
				}
			}
			it++;
		}
	}
	return res;
}
vector<double> EvaluateDivision::calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	map<pair<string, string>, double> divResults;
	map<string, list<string>> divGraph;
	vector<double> res(queries.size(), -1.0);

	for (int i = 0; i < equations.size(); i++)
	{
		divResults[make_pair(equations[i][0], equations[i][1])] = values[i];
		divResults[make_pair(equations[i][1], equations[i][0])] = 1 / values[i];
		if (divGraph.find(equations[i][0]) == divGraph.end())
			divGraph[equations[i][0]] = list<string>();
		divGraph[equations[i][0]].push_back(equations[i][1]);
		if (divGraph.find(equations[i][1]) == divGraph.end())
			divGraph[equations[i][1]] = list<string>();
		divGraph[equations[i][1]].push_back(equations[i][0]);
	}
	map<string, bool> visited;
	for (int i = 0; i < queries.size(); i++) {
		if(divGraph.find(queries[i][0]) != divGraph.end() && divGraph.find(queries[i][1]) != divGraph.end())
			res[i] = getQueryResult(queries[i][0], queries[i][1], divGraph, divResults, visited);
		visited.clear();
	}
	return res;
}

void EvaluateDivision::solve()
{
	fillInput();
	calcEquation(equations, values, queries);
	return;
}

void EvaluateDivision::fillInput()
{
	get2DStrings(equations);
	getFloatArray(values);
	get2DStrings(queries);	
}

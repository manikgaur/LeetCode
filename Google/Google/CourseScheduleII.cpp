#include "CourseScheduleII.h"

CourseScheduleII::CourseScheduleII()
{
	file.open("CourseScheduleIIInput.txt");
}
bool getCourses(vector<vector<int>>& g, vector<bool>& visited, vector<int>& stack, unordered_map<int, bool>& fStack, int node)
{
	visited[node] = true;

	cout << "pushing " << node << endl;
	for (int i = 0; i < g[node].size(); i++)
	{
		cout << "inside " << node << endl;
		if (fStack.find(g[node][i]) != fStack.end()) {
			return false;
		}
		if (!visited[g[node][i]]) {
			fStack[g[node][i]] = true;
			if (!getCourses(g, visited, stack, fStack, g[node][i])) {
				return false;
			}
			fStack.erase(g[node][i]);
		}
		cout << "for outside" << endl;

	}
	cout << "pushed " << node << endl;
	stack.push_back(node);
	return true;
}

vector<int> CourseScheduleII::findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
	vector<vector<int>> g(numCourses, vector<int>());
	for (int i = 0; i < prerequisites.size(); i++)
	{
		g[prerequisites[i][1]].push_back(prerequisites[i][0]);
	}
	vector<int> stack;
	vector<bool> visited(numCourses, 0);
	unordered_map<int, bool> fStack;

	for (int i = 0; i < numCourses; i++)
	{
		if (!visited[i]) {
			fStack[i] = true;
			if (!getCourses(g, visited, stack, fStack, i))
				fStack.erase(i);
		}
	}
	reverse(stack.begin(), stack.end());
	return stack;
}

int getMaxincreasingPath(vector<vector<int>>& g, vector<int>& visited, int pos) {
	visited[pos] = 1;
	int maxLen = 0;
	for (int i = 0; i < g[pos].size(); i++) {
		if (!visited[g[pos][i]]) {
			maxLen = max(maxLen, getMaxincreasingPath(g, visited, g[pos][i]));
		}
		else {
			maxLen = max(maxLen, visited[g[pos][i]]);
		}
	}
	visited[pos] = maxLen + 1;
	return visited[pos];
}

int CourseScheduleII::longestIncreasingPath(vector<vector<int>>& matrix)
{
	int r = matrix.size();
	if (r == 0)
		return 0;
	int c = matrix[0].size();
	if (c == 0)
		return 0;
	vector<vector<int>> g(matrix.size() * matrix[0].size(), vector<int>());
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (j + 1 < c) {
				if (matrix[i][j] < matrix[i][j + 1])
					g[i*c + j].push_back(i*c + j + 1);
				if (matrix[i][j + 1] < matrix[i][j])
					g[i*c + j + 1].push_back(i*c + j);
			}
			if (i + 1 < r) {
				if (matrix[i][j] < matrix[i + 1][j])
					g[i*c + j].push_back((i + 1)*c + j);
				if (matrix[i + 1][j] < matrix[i][j])
					g[(i + 1)*c + j].push_back(i*c + j);
			}
		}
	}
	vector<int> visited(g.size());
	int maxLen = 0;
	for (int i = 0; i < g.size(); i++) {
		if(!visited[i])
			maxLen = max(maxLen, getMaxincreasingPath(g, visited, i));
	}
	return maxLen;
}

void CourseScheduleII::solve()
{
	fillInput();
	//findOrder(n, p);
	cout << longestIncreasingPath(p);
	return;
}

void CourseScheduleII::fillInput()
{
//	n = getInt();
	get2Darray(p);
}

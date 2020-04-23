#include "CatAndMouse.h"
#define MOUSE 1
#define CAT 2
#define DRAW 0
CatAndMouse::CatAndMouse()
{
	file.open("CatAndMouseInput.txt");
}

int whoWins(vector<vector<int>>& graph, int cPos, int mPos, vector<vector<int>>& visited, bool isCat) {
	if (visited[cPos][mPos] != -1)
		return visited[cPos][mPos];

	int ret = DRAW;
	int turn = isCat ? cPos : mPos;
	for (int i = 0; i < graph[turn].size(); i++) {
		//if (!visited[isCat][graph[turn][i]] && !(!isCat && graph[turn][i] == cPos)) {
			if (isCat && graph[turn][i] == mPos)
				return 2;
			if (!isCat && graph[turn][i] == 0)
				return 1;
			if (!(isCat && visited[!isCat][graph[turn][i]]))
			{
				continue;
			}
			visited[isCat][graph[turn][i]] = 1;
			int res;
			if(isCat)
				res = whoWins(graph, graph[turn][i], mPos, visited, !isCat);
			else
				res = whoWins(graph, cPos, graph[turn][i], visited, !isCat);
			visited[isCat][graph[turn][i]] = 0;
			if (isCat && res == CAT)
				return 2;
			if (!isCat && res == MOUSE)
				return 1;
			ret = res;
		//}
	}
	return visited[cPos][mPos];
}

int CatAndMouse::catMouseGame(vector<vector<int>>& graph)
{
	vector<vector<int>> visited(graph.size(), vector<int>(graph.size(), 0));
	for (int i = 0; i < graph.size(); ++i) { visited[i][i] = 2; visited[0][i] = 1; }
/*	visited[0][1] = 1;
	visited[1][2] = 1;
	visited[1][0] = 1;*/
	return whoWins(graph, 2, 1, visited, 0);
}

int dfs(vector<vector<int>>& graph, vector<vector<int>>& memo, int mouse, int cat) {
	if (memo[mouse][cat] == -1) {
		memo[mouse][cat] = 0;// if the mouse and cat come back to these locations, it is a loop, i.e. a draw.
		int r = 2;
		//traverse all mouse's choices
		for (int next_m : graph[mouse]) {
			if (next_m == cat) continue;// if the mouse's next step is cat's location, mouse is caught, pass this situation.
			int res = 1;
			//traverse all cat's choices
			for (int next_c : graph[cat]) {
				if (next_c == 0) continue;// pass the illegal case.
				int ret = dfs(graph, memo, next_m, next_c);
				if (ret == 2) {
					res = 2;
					break;
				}
				if (ret == 0)
					res = 0;
			}
			if (res == 1) {
				r = 1;
				break;
			}
			if (res == 0)
				r = 0;
		}
		memo[mouse][cat] = r;
	}
	return memo[mouse][cat];
}

int CatAndMouse::catMouseGame2(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<vector<int>> memo(n, vector<int>(n, -1));
	for (int i = 0; i < n; ++i) { memo[i][i] = 2; memo[0][i] = 1; }
	return dfs(graph, memo, 1, 2);
}

void CatAndMouse::solve()
{
	fillInput();
	cout << catMouseGame(graph);
	return;
}

void CatAndMouse::fillInput()
{
	get2Darray(graph);
}

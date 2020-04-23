#include "MinimumAreaRectangle.h"

MinimumAreaRectangle::MinimumAreaRectangle()
{
	file.open("MinimumAreaRectangleInput.txt");
}

void MinimumAreaRectangle::solve()
{
	fillInput();
	cout << minAreaRect(points);
	return;
}

bool MinimumAreaRectangle::compare(vector<int> &p1, vector<int> &p2) 
{
	if (p1[1] < p2[1])
		return true;
	if (p1[1] == p2[1])
		return p1[0] < p2[0];
	return false;
}

int MinimumAreaRectangle::minAreaRect(vector<vector<int>>& points)
{
	map<int, map<int, bool>> maps;
	for (int i = 0; i < points.size(); i++) {
		map<int, bool> x;
		if (maps.find(points[i][1]) != maps.end())
			x = maps[points[i][1]];
		x[points[i][0]] = true;
		maps[points[i][1]] = x;
	}
	map<int, map<int, bool>>::iterator Yit = maps.begin();
	if (maps.size() < 2)
		return 0;

	int maxArea = INT_MAX;
	int i = 0;
	while (Yit != maps.end()) {
		if (maps[Yit->first].size() > 1) {
			map<int, bool>::iterator Xit = maps[Yit->first].begin();
			while (Xit != maps[Yit->first].end()) {
				map<int, bool>::iterator Xit2 = Xit;
				Xit2++;
				while (Xit2 != maps[Yit->first].end()) {
					map<int, map<int, bool>>::iterator Yit2 = Yit;
					Yit2++;
					while (Yit2 != maps.end()) {
						if (maps[Yit2->first].size() > 1) {
							int x1, x2;
							x1 = Xit->first;
							x2 = Xit2->first;
							if (maps[Yit2->first].find(x1) != maps[Yit2->first].end() && 
								maps[Yit2->first].find(x2) != maps[Yit2->first].end()) {
								int area = abs(Yit2->first - Yit->first) * (x2 - x1);
								if (area < maxArea)
									maxArea = area;
							}
							if (maxArea == 1)
								return 1;
						}
						Yit2++;
					} 
					Xit2++;
				}
				Xit++;
			}
		}
		Yit++;
	}

	return maxArea == INT_MAX ? 0 : maxArea;
}

void MinimumAreaRectangle::fillInput()
{
	string line = getNextLine();
	line.erase(std::remove(line.begin(), line.end(), '['), line.end());

	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		int i = 0;
		while (getline(s, tmp, ']'))
		{
			vector<int> vRow;
			if (tmp.length()) {
				std::stringstream row(tmp);
				while (getline(row, tmp, ','))
				{
					if (tmp.length())
						vRow.push_back(stoi(tmp));
				}
				points.push_back(vRow);
			}
			i++;
		}
	}
}

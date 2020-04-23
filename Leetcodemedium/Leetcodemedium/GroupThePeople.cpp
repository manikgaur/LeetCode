#include "GroupThePeople.h"
#include <vector>
#include <sstream>

void GroupThePeople::fillInput()
{
	string line = getNextLine();

	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			data.push_back(stoi(tmp));
		}
	}
}

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
	vector<vector<int>> data(500);
	for (int i = 0; i < groupSizes.size(); i++) {
		data[groupSizes[i]].push_back(i);
	}
	vector<vector<int>> result;
	int pos = 0;

	for (int i = 0; i < data.size(); i++) {
		vector<int> temp;
		for (int j = 0; j < data[i].size(); j++) {
			if (j % i == 0) {
				if(temp.size())
					result.push_back(temp);
				pos++;
				temp.clear();
			}
			temp.push_back(data[i][j]);
		}
		if (temp.size())
			result.push_back(temp);
	}
	return result;
}


GroupThePeople::GroupThePeople()
{
	file.open("groupThePeople.txt");	
}

void GroupThePeople::solve()
{
	fillInput();
	groupThePeople(data);
}

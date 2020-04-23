#include "LogStorageSystem.h"

LogStorageSystem::LogStorageSystem()
{
	file.open("LogStorageSystem.txt");
}
#define longMax 0x7fffffffffffffff
class TrieNodeLS
{
public:
	bool isWord;
	int id;
	long long minTime;
	long long maxTime;
	list<int> ids;
	map<string, TrieNodeLS*> next;
	TrieNodeLS():isWord(false), id(-1), minTime(longMax), maxTime(0), next(map<string, TrieNodeLS*>()){}
};

class LogSystem {
	
	TrieNodeLS* root;
	map<string, int> levels;
	vector<vector<int>> minMax;
public:
	LogSystem() {
		root = new TrieNodeLS();
		levels["Year"] = 0;
		levels["Month"] = 1;
		levels["Day"] = 2;
		levels["Hour"] = 3;
		levels["Minute"] = 4;
		levels["Second"] = 5;
		minMax = vector<vector<int>>(2, vector<int>(6, 0));
		minMax[1].insert(minMax[1].begin(), { 2017, 12, 31, 23, 59, 59 });

	}
	long long convertToint(string timestamp, int gra, bool isMin) {
		stringstream ss(timestamp);
		string tmp;
		long long time = 0;
		int i = 0;
		while (getline(ss, tmp, ':')) {
			if (i > gra) {
				time = (time * 100) + (isMin ? minMax[0][i] : minMax[1][i]);
			}
			else
				time = time * 100 + stoi(tmp);
			i++;
		}
		return time;
	}

	void put(int id, string timestamp) {
		stringstream ss(timestamp);
		string tmp;
		TrieNodeLS* node = root;
		list<TrieNodeLS*> stack;
		if (id == 50)
			int brk = 0;
		long long time = convertToint(timestamp, 6, false);
		while (getline(ss, tmp, ':'))
		{
			if (node->next.find(tmp) == node->next.end())
				node->next[tmp] = new TrieNodeLS();
			node->minTime = min(time, node->minTime);
			node->maxTime = max(time, node->maxTime);
			node->ids.push_back(id);
			node = node->next[tmp];
		}
		node->minTime = min(time, node->minTime);
		node->maxTime = max(time, node->maxTime);
		node->ids.push_back(id);
		node->isWord = true;
		return;
	}

	int getOverlap(TrieNodeLS* node, long long& s, long long& e) {
		long long nodeS = node->minTime;
		long long nodeE = node->maxTime;

		if (s <= nodeS && e >= nodeE)
			return 0;
		if (s > nodeE || e < nodeS)
			return -1;
		else return 1;

	}

	vector<int> getIdInRange(TrieNodeLS* node, long long& s, long long& e, string strs, string stre, string gra, int level) {
		if (root == NULL)
			return vector<int>();
		stringstream ss(strs);
		stringstream se(stre);
		string tmps;
		string tmpe;
		getline(ss, tmps, ':');
		getline(se, tmpe, ':');
		vector<int> res;
		if (level == levels[gra]) {
			res.insert(res.end(), node->ids.begin(), node->ids.end());
			return res;
		}
		switch (getOverlap(node, s, e))
		{
		case 0:
			res.insert(res.end(), node->ids.begin(), node->ids.end());
			break;
		case -1:
			break;
		case 1: {
			auto it = node->next.begin();
			while (it != node->next.end()) {
				string ps = strs.substr(tmps.length() + 1);
				string pe = stre.substr(tmpe.length() + 1);
				if (e >= it->second->minTime && s <= it->second->maxTime) {
					vector<int> ret = getIdInRange(it->second, s, e, ps, pe, gra, level + 1);
					res.insert(res.end(), ret.begin(), ret.end());
				}
				it++;
			}
		}
			break;
		default:
			break;
		}
		return res;
	}

	vector<int> retrieve(string s, string e, string gra) {
		TrieNodeLS* node = root;
		s.push_back(':');
		e.push_back(':');
		long long sTime = convertToint(s, levels[gra], true);
		long long eTime = convertToint(e, levels[gra], false);
		vector<int> res = getIdInRange(root, sTime, eTime, s, e, gra, -1);
		return res;
	}
};

void LogStorageSystem::solve()
{
	fillInput();
	LogSystem obj;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "put") {
			cout << "put : " << qData[i - 1][0] << ", " << qData[i - 1][0] << endl;
			obj.put(stoi(qData[i - 1][0]), qData[i - 1][1]);
		}	
		if (queries[i] == "retrieve") {
			vector<int> res = obj.retrieve(qData[i - 1][0], qData[i - 1][1], qData[i - 1][2]);
			for (auto r : res)
				cout << r << ", ";
			cout << endl;
		}

	}
	return;
}

void LogStorageSystem::fillInput()
{
	getStrings(queries);
	get2DStrings(qData);
}

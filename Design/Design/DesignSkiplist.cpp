#include "DesignSkiplist.h"

DesignSkiplist::DesignSkiplist()
{
	file.open("DesignSkiplistInput.txt");
}

class SkipNode
{
public:
	int val;
	SkipNode* next;
	SkipNode* down;
	SkipNode(int value = -1):val(value), next(NULL), down(NULL){}
};

class Skiplist {
	list<SkipNode*> level;
public:
	Skiplist() {
		level.push_back(new SkipNode());
	}

	int getLevel()
	{
		return rand() % level.size();
	}

	bool search(int target) {
		SkipNode* node = level.back();
		while (node != NULL)
		{	
			while (node->next != NULL && node->next->val <= target) {
				node = node->next;
			}
			if (node->val == target)
				return true;
			node = node->down;
		}
		return false;
	}

	SkipNode* addNode(int num, SkipNode* node, int clevel, int level)
	{
		if (level >= clevel) {
			while (node->next != NULL && node->next->val < num) {
				node = node->next;
			}
			SkipNode* tmp = new SkipNode(num);
			tmp->next = node->next;
			node->next = tmp;
			if(node->down != NULL)
				node->next->down = addNode(num, node->down, clevel - 1, level);
			return node->next;
		} 
		else {
			while (node->next != NULL && node->next->val < num) {
				node = node->next;
			}
			addNode(num, node->down, clevel - 1, level);
		}
	}

	void add(int num) {
		int l = getLevel();
		if (level.size() - l == 1) {
			SkipNode* node = new SkipNode();
			node->down = level.back();
			level.push_back(node);
		}
		SkipNode* head = level.back();
		addNode(num, head, level.size() - 1, l);
	}

	bool erase(int num) {
		SkipNode* node = level.back();
		bool found = false;
		while (node != NULL)
		{
			while (node->next != NULL && node->next->val < num) {
				node = node->next;
			}
			if (node->next != NULL && node->next->val == num)
			{	
				found = true;
				SkipNode* tmp = node->next;
				node->next = node->next->next;
				delete tmp;
			}
			node = node->down;
		}
		return found;
	}
};
void DesignSkiplist::solve()
{
	fillInput();
	Skiplist obj;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "add") {
			cout << "add :" << qData[i-1] << endl;
			obj.add(qData[i-1]);
		}
		else if (queries[i] == "search")
			cout << "search :" << obj.search(qData[i-1]) << endl;
		else if (queries[i] == "erase")
			cout << "erase :" << obj.erase(qData[i-1]) << endl;

		//cout << endl;
	}
	return;
}

void DesignSkiplist::fillInput()
{
	getStrings(queries);
	getIntArray(qData);
}

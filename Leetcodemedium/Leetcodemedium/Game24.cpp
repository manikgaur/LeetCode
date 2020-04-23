#include "Game24.h"

Game24::Game24()
{
	file.open("game24Input.txt");
}

void Game24::solve()
{
	fillInput();
	judgePoint24(nums);
}

void Game24::fillInput()
{
	string line = getNextLine();
	if (line.length()) {
		std::stringstream s(line);
		string tmp;
		while (getline(s, tmp, ','))
		{
			nums.push_back(stoi(tmp));
		}
	}
}

void getPermutation(vector<int>& nums, vector<vector<int>> &permutations, map<int, int> &countMap, vector<int> &permStr)
{
	map<int, int>::iterator it = countMap.begin();
	while (it != countMap.end()) {
		if (it->second)
			break;
		it++;
	}
	if (it == countMap.end()) {
		permutations.push_back(permStr);
		return;
	}
	while (it != countMap.end()) {
		if (it->second) {
			permStr.push_back(it->first);
			it->second--;
			getPermutation(nums, permutations, countMap, permStr);
			it->second++;
			permStr.pop_back();
		}
		it++;
	}
}

void createPermutation(vector<int>& nums, vector<vector<int>> &permutations) {
	map<int, int> countMap;
	vector<int> permStr;
	for (int i = 0; i < nums.size(); i++)
		countMap[nums[i]] += 1;
	getPermutation(nums, permutations, countMap, permStr);
	return;

}

void getOpPermutation(vector<char>& operators, vector<string> &opPermutations, string &permStr)
{
	if (permStr.length() == 3) {
		opPermutations.push_back(permStr);
		return;
	}

	for (int i = 0; i < operators.size(); i++) {
		permStr += operators[i];
		getOpPermutation(operators, opPermutations, permStr);
		permStr.pop_back();
	}
}

void createOperatorsPermutations(vector<char>& operators, vector<string> &opPermutations) {
	string permStr;
	getOpPermutation(operators, opPermutations, permStr);
	return;
}
int calculateAllPossibilities(vector<int> nums, string operators) {
	return 0;
}

void createExpresstions(vector<vector<int>>& permutations, vector<string> &opPermutations, vector<string> &expressions)
{
	for (int i = 0; i < permutations.size(); i++) {
		for (int j = 0; j < opPermutations.size(); j++) {
			string exp = to_string(permutations[i][0]) + opPermutations[j][0] +
						to_string(permutations[i][1]) + opPermutations[j][1] +
						to_string(permutations[i][2]) + opPermutations[j][2] +
						to_string(permutations[i][3]);
			expressions.push_back(exp);
			int diff = 0;
			if (opPermutations[i][0] == '+' || opPermutations[i][0] == '-') {
				diff = 0;
			}
			else {
				diff = 1;
			}
			bool make = 0;
			for (int k = 1; k < opPermutations[j].length(); k++) {
				if (diff && (opPermutations[j][k] == '+' || opPermutations[j][k] == '-'))
					make = 1;
				if (!diff && (opPermutations[j][k] == '*' || opPermutations[j][k] == '/'))
					make = 1;
			}
			if (make) {
				exp = "(" + to_string(permutations[i][0]) + opPermutations[j][0] +
					to_string(permutations[i][1]) + ")" + opPermutations[j][1] +
					to_string(permutations[i][2]) + opPermutations[j][2] +
					to_string(permutations[i][3]);
				expressions.push_back(exp);
				exp = to_string(permutations[i][0]) + opPermutations[j][0] +
					"(" + to_string(permutations[i][1]) + opPermutations[j][1] +
					to_string(permutations[i][2]) + ")" + opPermutations[j][2] +
					to_string(permutations[i][3]);
				expressions.push_back(exp);
				exp = to_string(permutations[i][0]) + opPermutations[j][0] +
					to_string(permutations[i][1]) + opPermutations[j][1] +
					"(" + to_string(permutations[i][2]) + opPermutations[j][2] +
					to_string(permutations[i][3]) + ")";
				expressions.push_back(exp);
				exp = "((" + to_string(permutations[i][0]) + opPermutations[j][0] +
					to_string(permutations[i][1]) + ")" + opPermutations[j][1] +
					to_string(permutations[i][2]) + ")" + opPermutations[j][2] +
					to_string(permutations[i][3]);
				expressions.push_back(exp);
				exp = "(" + to_string(permutations[i][0]) + opPermutations[j][0] +
					"(" + to_string(permutations[i][1]) + opPermutations[j][1] +
					to_string(permutations[i][2]) + "))" + opPermutations[j][2] +
					to_string(permutations[i][3]);
				expressions.push_back(exp);
				exp = to_string(permutations[i][0]) + opPermutations[j][0] +
					"((" + to_string(permutations[i][1]) +  opPermutations[j][1] +
					to_string(permutations[i][2]) + ")" + opPermutations[j][2] +
					to_string(permutations[i][3])+ ")";
				expressions.push_back(exp);
				exp =to_string(permutations[i][0]) + opPermutations[j][0] +
					"(" + to_string(permutations[i][1]) + opPermutations[j][1] +
					"(" + to_string(permutations[i][2]) + opPermutations[j][2] +
					to_string(permutations[i][3]) + "))";
				expressions.push_back(exp);
			}
		}
	}
}

double calcExpression(string &expressions, int &index)
{
	list<double> nums;
	list<char> ops;
	for (int i = index; i < expressions.length(); i++) {
		if (expressions[i] > '0' && expressions[i] <= '9')
			nums.push_back(expressions[i] - '0');
		else if (expressions[i] == '(') {
			int j = i+1;
			nums.push_back(calcExpression(expressions, j));
			i = j;
		}
		else if (expressions[i] == ')') {
			index = i;
			break;
		}
		else {
			ops.push_back(expressions[i]);
		}
	}
	while (nums.size() != 1) {
		double num1 = nums.front();
		nums.pop_front();
		double num2 = nums.front();
		nums.pop_front();
		char op = ops.front();
		ops.pop_front();
		double result = 0;
		switch (op)
		{
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num1 / num2;
			break;
		default:
			break;
		}
		nums.push_front(result);
	}

	return nums.back();
}

bool Game24::judgePoint24(vector<int>& nums)
{
	vector<vector<int>> permutations;
	vector<string> opPermutations;
	vector<string> expressions;
	vector<char> operators{ '+','-','*','/' };
	createPermutation(nums, permutations);
	createOperatorsPermutations(operators, opPermutations);
	createExpresstions(permutations, opPermutations, expressions);
	list<string> result;
	for (int j = 0; j < expressions.size(); j++) {
		int index = 0;
		float res = calcExpression(expressions[j], index);
		if (res == 24) {
			return true;
		}
	}

	return false;
}
/*
bool Game24::judgePoint24(vector<int>& nums)
{
	vector<vector<int>> permutations;
	vector<string> opPermutations;
	vector<char> operators{ '+','-','*','/' };
	createPermutation(nums, permutations);
	createOperatorsPermutations(operators, opPermutations);
	list<string> result;
	for (int i = 0; i < permutations.size(); i++) {
		for (int j = 0; j < opPermutations.size(); j++) {
			if (calcExpression(permutations[i], opPermutations[j])) {
				string res;
				res += to_string(permutations[i][3]);
				res += opPermutations[j].at(2);
				res += to_string(permutations[i][2]);
				res += opPermutations[j].at(1);
				res += to_string(permutations[i][1]);
				res += opPermutations[j].at(0);
				res += to_string(permutations[i][0]);
				result.push_back(res);
				//				return true;
			}
		}
	}

	return false;
}*/

#include "AllInOneMedium.h"

AllInOneMedium::AllInOneMedium()
{
	file.open("AllInOneMediumInput.txt");
}
// 29. Divide Two Integers
int AllInOneMedium::divide(int divisor, int dividend )
{
	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	dividend = abs(dividend);
	divisor = abs(divisor);
	unsigned divid = abs(dividend);
	unsigned divis = abs(divisor);
	unsigned int quotient = 0;
	int	temp = 0;

	if (divid == divis)
		return sign * 1;
	if (divis > divid)
		return 0;
	int last = 31;
	int q = 0;
	int i = 0;
	for (i = 0; i <= last && divid >= divis; ++i) {
		if ((divis << i) > temp && (divis << i) <= (unsigned)divid && i != 31) {
			temp = divis << i;
			q = 1LL << i;
		}
		else {
			last = i;
			i = -1;
			divid -= temp;
			quotient += q;
			if (sign == 1 && quotient > INT_MAX)
				return INT_MAX;
			if (sign == -1 && sign * quotient < INT_MIN)
				return INT_MIN;
			temp = 0;
		}
	}
	
	return sign * quotient;
}

string AllInOneMedium::reverseWords(string s)
{
	if (s.length() == 0)
		return string();
	string result;
	vector<string> data;
	string tmpStr;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			if (tmpStr.length()) {
				data.push_back(tmpStr);
				tmpStr.clear();
			}
			continue;
		}
		else {
			tmpStr.push_back(s[i]);
		}
	}
	if (tmpStr.length())
		data.push_back(tmpStr);

	for (int i = data.size()-1; i >= 0; i--) {
		result.append(data[i]);
		result.append(" ");
	}
	if(result.length())
		result.pop_back();	

	return result;

}

string AllInOneMedium::fractionToDecimal(int denominator, int numerator)
{
	string retStr;
	if (denominator == 0)
		return retStr;
	if (numerator == 0)
		return to_string(0);
	int sign = ((denominator < 0) ^ (numerator < 0)) ? -1 : 1;
	if (sign == -1)
		retStr.push_back('-');

	long long divisor = abs(denominator);
	long long dividend = abs(numerator);
	divisor = abs(divisor);
	dividend = abs(dividend);

	long long q = dividend / divisor;
	retStr.append(to_string(q));
	long long r = dividend % divisor;
	unordered_map<int, int> remPos;
	if (r)
		retStr.append(".");
	while (r != 0) {
		unordered_map<int, int>::iterator it;
		if ((it = remPos.find(r)) != remPos.end()) {
			retStr.insert(it->second, "(");
			retStr.append(")");
			break;
		}
		remPos[r] = retStr.length();
		r *= 10;
		retStr.append(to_string((long long)r / divisor));

		r = r % divisor;
	}
	return retStr;
}

//468	Validate IP Address
string AllInOneMedium::validIPAddress(string IP)
{
	vector<string> returnVal{ "Neither", "IPv4", "IPv6" };
	if (!IP.length())
		return returnVal[0];

	// IPv4 Validation

	if (IP.find('.') != IP.npos) {
		int count = 0;
		stringstream s(IP);
		string tmp;
		if (std::count(IP.begin(), IP.end(), '.') > 3)
			return returnVal[0];

		while (getline(s, tmp, '.'))
		{
			count++;
			if (tmp.length() > 3 || !tmp.length()) {
				return returnVal[0];
			}
			for (int i = 0; i < tmp.length(); i++) {
				if (tmp[i] < '0' || tmp[i] > '9')
					return returnVal[0];
			}
			int num = stoi(tmp);
			if (num < 0 || num > 255)
				return returnVal[0];
			if (num && tmp[0] == '0' || !num && tmp.length() > 1)
				return returnVal[0];
		}
		if (count != 4)
			return returnVal[0];
		return returnVal[1];
	}

	//IPv6 Validation
	else if (IP.find(':') != IP.npos) {
		int count = 0;
		stringstream s(IP);
		string tmp;
		if (std::count(IP.begin(), IP.end(), ':') > 7)
			return returnVal[0];
		while (getline(s, tmp, ':'))
		{
			count++;
			if (tmp.length() > 4 || !tmp.length()) {
				return returnVal[0];
			}
			for (int i = 0; i < tmp.length(); i++) {
				if ((tmp[i] < '0' || tmp[i] > '9') && (tmp[i] < 'a' || tmp[i] > 'f') && (tmp[i] < 'A' || tmp[i] > 'F'))
					return returnVal[0];
			}
		}
		if (count != 8)
			return returnVal[0];
		return returnVal[2];
	}

	return returnVal[0];
}

int AllInOneMedium::numDecodings(string s) {
	if (!s.length())
		return 0;
	int n = s.length() + 1;
	vector<int> dp(n);
	dp[0] = 1;
	dp[1] = s[0] - '0' > 0 ? 1 : 0;
	for (int i = 2; i <= s.length(); i++) {
		int num1 = stoi(s.substr(i - 1, 1));
		int num2 = stoi(s.substr(i - 2, 2));

		if (num1 > 0)
			dp[i] += dp[i - 1];
		if (num2 > 9 && num2 < 27)
			dp[i] += dp[i - 2];
	}
	return dp[n-1];
}

bool AllInOneMedium::checkSubarraySum(vector<int>& nums, int k) {
	unordered_map<int, int> cache;
	cache[0] = -1;
	unordered_map<int, int>::iterator it;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];

		if (k != 0)
			sum = sum % k;
		if ((it = cache.find(sum)) != cache.end()) {
			if (i - it->second >= 2) return true;
		}
		else
			cache[sum] = i;
	}
	return false;
}

string AllInOneMedium::minRemoveToMakeValid(string s) {
	int p = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			p++;
		if (s[i] == ')')
			p--;

		if (p < 0) {
			s.erase(i, 1);
			p = 0;
			i--;
		}
	}
	p = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == ')')
			p++;
		if (s[i] == '(')
			p--;

		if (p < 0) {
			s.erase(i, 1);
			p = 0;
			//i++;
		}
	}

	return s;
}
//238. Product of Array Except Self
vector<int> AllInOneMedium::productExceptSelf(vector<int>& nums) {
	vector<int> result(nums.size());
	int temp = 1;
	for (int i = 0; i < nums.size(); i++) {
		result[i] = temp;
		temp *= nums[i];
	}

	temp = 1;
	for (int i = nums.size() - 1; i >= 0; i--) {
		result[i] = temp * result[i];
		temp *= nums[i];
	}
	return result;
}
//438. Find All Anagrams in a String
bool AllInOneMedium::isAnagram(vector<int> &s1, vector<int> &s2)
{
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}
vector<int> AllInOneMedium::findAnagrams(string s, string p) {
	if (p.length() > s.length())
		return vector<int>();
	if (!p.length() || !s.length())
		return vector<int>();

	vector<int> result;
	vector<int> pCount(26);
	vector<int> sCount(26);
	int plen = p.length();
	for (int i = 0; i < plen; i++) {
		pCount[p[i] - 'a']++;
	}
	for (int i = 0; i < plen - 1; i++) {
		sCount[s[i] - 'a']++;
	}
	int i = 0;
	do {
		sCount[s[i + plen - 1] - 'a']++;
		if (isAnagram(sCount, pCount))
			result.push_back(i);
		sCount[s[i] - 'a']--;
	} while (++i <= s.length() - plen);

	return result;
}
//199. Binary Tree Right Side View
void AllInOneMedium::dfs(TreeNode* root, vector<int>& result, int pos)
{
	if (root == NULL)
		return;
	if (result.size() <= pos)
		result.push_back(root->val);
	else {
		result[pos] = root->val;
	}

	dfs(root->left, result, pos + 1);
	dfs(root->right, result, pos + 1);
}

vector<int> AllInOneMedium::rightSideView(TreeNode* root) {
	vector<int> result;
	if (root == NULL)
		return result;
	dfs(root, result, 0);
	return result;
}
//986. Interval List Intersections
vector<int> AllInOneMedium::mergeIntervals(vector<int> A, vector<int> B)
{
	vector<int> res;
	vector<int> ret;
	if ((A[0] >= B[0] && A[0] <= B[1]) || (B[0] >= A[0] && B[0] <= A[1])) {
		res.insert(res.begin(), A.begin(), A.end());
		res.insert(res.end(), B.begin(), B.end());
		sort(res.begin(), res.end());
		ret.push_back(res[1]);
		ret.push_back(res[2]);
	}
	return ret;
}
vector<vector<int>> AllInOneMedium::intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
	vector<vector<int>> result;

	int i = 0;
	int j = 0;
	while (i < A.size() && j < B.size()) {
		vector<int> val = mergeIntervals(A[i], B[j]);
		if (val.size())
			result.push_back(val);
		if (A[i][1] < B[j][1])
			i++;
		else if (B[j][1] < A[i][1])
			j++;
		else {
			i++; j++;
		}
	}
	return result;
}

//139	Word Break
TrieNode* AllInOneMedium::createDictionary(vector<string>& wordDict) {
	TrieNode* root = new TrieNode();
	for (int i = 0; i < wordDict.size(); i++) {
		string s = wordDict[i];
		TrieNode* node = root;
		for (int j = 0; j < s.length(); j++) {
			if (!node->node[s[j] - 'a']) {
				node->node[s[j] - 'a'] = new TrieNode();
			}
			node = node->node[s[j] - 'a'];
		}
		node->isWord = true;
	}
	return root;
}

bool backTracking(string s, TrieNode *root, vector<int>& cache)
{
	if (root == nullptr)
		return false;
	if (s.length() == 0)
		return true;
	TrieNode *node = root;
	for (int i = 0; i < s.length(); i++)
	{
		if (node->node[s[i] - 'a'])
			node = node->node[s[i] - 'a'];
		else
			return false;
		if (node->isWord) {
			if (cache[i+1] == -1 && backTracking(string(s, i + 1), root, cache)) {
				cache[i + 1] = 1;
				return true;
			}
			else
				cache[i + 1] = false;
		}		
	}
	return false;
}

bool AllInOneMedium::wordBreak(string s, vector<string>& wordDict) {
	TrieNode *p = createDictionary(wordDict);
	vector<int> cache(s.length() + 1, -1);
	bool ret = backTracking(s, p, cache);
	cout << ret;
	return ret;
}

//621	Task Scheduler
int leastInterval(vector<char>& tasks, int n) {
	int intervals = 0;
	map<char, int> countmap;
	for (int i = 0; i < tasks.size(); i++) {
		countmap[tasks[i]]++;
	}
	priority_queue<int> queue;
	auto it = countmap.begin();
	while (it != countmap.end()) {
		queue.push(it->second);
		it++;
	}	
	vector<bool> res;
	while (!queue.empty()) {
		vector<int> currTasks;
		for (int i = 0; i <= n; i++) {
			if (!queue.empty()) {
				res.push_back(true);
				currTasks.push_back(queue.top());
				queue.pop();
			}
			else
				res.push_back(false);
		}
		for (int i = 0; i < currTasks.size(); i++) {
			if (--currTasks[i] != 0)
				queue.push(currTasks[i]);
		}
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		if (res[i] == false)
			res.pop_back();
		else
			break;
	}

	return res.size();
}

class logData
{
public:
	int fId;
	string startEnd;
	int time;
};

//636	Exclusive Time of Functions	
vector<int> exclusiveTime(int n, vector<string>& logs) {
	vector<int> results(n, 0);
	vector<logData> data(logs.size());
	for (int i = 0; i < logs.size(); i++) {
		stringstream s(logs[i]);
		string tmp;
		getline(s, tmp, ':');
		data[i].fId = stoi(tmp);
		getline(s, tmp, ':');
		data[i].startEnd = tmp;
		getline(s, tmp, ':');
		data[i].time = stoi(tmp);	
		if (data[i].startEnd == "end")
			data[i].time++;
	}
	vector<int> stack;
	stack.push_back(data[0].fId);
	for (int i = 1; i < logs.size(); i++) {
		if (data[i].startEnd == "start") {
			if (stack.size())
				results[stack[stack.size() - 1]] += data[i].time - data[i - 1].time;
			stack.push_back(data[i].fId);
		}
		else if (data[i].startEnd == "end") {
			results[stack[stack.size() - 1]] += data[i].time - data[i - 1].time;
			stack.pop_back();
		}
	}

	return results;
}

//721. Accounts Merge
/*set<string> merge(set<string>&a, set<string>&b) {
	set<string> ret;
	ret.insert(a.begin(), a.end());
	ret.insert(b.begin(), b.end());

	if (ret.size() == a.size() + b.size())
		return set<string>();

	return ret;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	multimap<string, set<string>> data;
	for (int i = 0; i < accounts.size(); i++) {
		set<string> tmp1;
		for (int j = 1; j < accounts[i].size(); j++) {
			tmp1.insert(accounts[i][j]);
		}
		map<string, set<string>>::iterator it;
		if ((it = data.find(accounts[i][0])) != data.end()) {
			while (it != data.end() && it->first == accounts[i][0]) {
				set<string> tmp = merge(it->second, tmp1);
				if (tmp.size()) {
					tmp1 = tmp;
					data.erase(it);
					it = data.find(accounts[i][0]);
				}
				else
					it++;
			}
		}
		data.insert({ accounts[i][0], tmp1 });
	}
	vector<vector<string>> results;
	multimap<string, set<string>>::iterator it = data.begin();
	while (it != data.end()) {
		vector<string> ele;
		ele.push_back(it->first);
		ele.insert(ele.end(), it->second.begin(), it->second.end());
		results.push_back(ele);
		it++;
	}
	return results;
}
*/

void createGraph(unordered_map<string, set<string>>& graph, unordered_map<string, string>& parents, vector<vector<string>>& accounts)
{
	for (int i = 0; i < accounts.size(); i++) {
		string p = accounts[i][0];
		string m1 = accounts[i][1];
		parents[m1] = p;
		if (graph.find(m1) == graph.end()) {
			graph.insert({ m1, set<string>() });
		}
		for (int j = 2; j < accounts[i].size(); j++) {
			string m2 = accounts[i][j];
			parents[m2] = p;
			graph[m2].insert(m1);
			graph[m1].insert(m2);
			m1 = m2;
		}
	}
}
void dfs(unordered_map<string, set<string>>& graph, string m, unordered_map<string, bool>& visited, set<string>& mails) {
	visited[m] = true;
	mails.insert(m);
	set<string>::iterator it = graph[m].begin();
	while (it != graph[m].end()) {
		if (visited.find(*it) == visited.end()) {
			dfs(graph, *it, visited, mails);
		}
		it++;
	}
}
void createList(string p, vector<vector<string>>& results, set<string>& mails)
{
	vector<string> res;
	res.push_back(p);
	set<string>::iterator it = mails.begin();
	while (it != mails.end()) {
		res.push_back(*it);
		it++;
	}
	results.push_back(res);
}
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	unordered_map<string, set<string>> graph;
	unordered_map<string, string> parents;
	unordered_map<string, bool> visited;
	createGraph(graph, parents, accounts);
	set<string> mails;
	unordered_map<string, set<string>>::iterator it = graph.begin();
	vector<vector<string>> results;
	while (it != graph.end()) {
		if (visited.find(it->first) == visited.end()) {
			dfs(graph, it->first, visited, mails);
			createList(parents[it->first], results, mails);
			mails.clear();
		}
		it++;
	}

	return results;
}

// 133. Clone Graph
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

void dfs(Node* node, vector<bool>& visited, bool toClone) {
	cout << node->val << endl;
	visited[node->val] = true;
	vector<Node*>& n = node->neighbors;
	if (toClone) {
		n.push_back(new Node(node->val));
	}
	else {
		n.pop_back();
	}

	Node* cn = n.back();
	int end = toClone ? n.size() - 1 : n.size();
	for (int i = 0; i < end; i++) {
		if (!visited[n[i]->val]) {
			dfs(n[i], visited, toClone);
		}
		if(toClone)
			cn->neighbors.push_back(n[i]->neighbors.back());
	}

	cout << endl;
	return;
}

Node* cloneGraph(Node* node) {
	vector<bool> visited(101);
	dfs(node, visited, true);
	Node *ret = node->neighbors.back();
	for (int i = 0; i < visited.size(); i++)
		visited[i] = false;
	dfs(node, visited, false);
	return ret;
}

// 34	Find First and Last Position of Element in Sorted Array
vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> res(2, -1);
	if (nums.size() == 0)
		return res;

	int start = 0;
	int end = nums.size() - 1;
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] >= target)
			end = mid;
		else
			start = mid + 1;
	}
	if (nums[start] != target)
		return res;
	res[0] = start;

	end = nums.size() - 1;
	while (start < end) {
		int mid = end - (end - start) / 2;
		if (nums[mid] <= target)
			start = mid;
		else
			end = mid - 1;
	}
	res[1] = start;
	return res;
}

bool dfs(vector<vector<int>>& graph, int node, vector<int>& visited, int value)
{
	visited[node] = value;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]] == -1) {
			if (!dfs(graph, graph[node][i], visited, !value))
				return false;
		}
		else {
			if (visited[graph[node][i]] == value)
				return false;
		}
	}
	return true;
}

bool isBipartite(vector<vector<int>>& graph) {
	vector<int> visited(graph.size(), -1);
	for (int i = 0; i < graph.size(); i++) {
		if (visited[i] == -1)
			if (!dfs(graph, i, visited, 0))
				return false;
	}
	return true;
}
void AllInOneMedium::solve()
{

	set<int> data({1, 3, 5, 7, 9});
	auto it = data.lower_bound(3);
	cout << *it;

/*	vector<vector<int>> data;
	get2Darray(data);
	cout << isBipartite(data);*/
/*	vector<int> array;
	getIntArray(array);
	searchRange(array, getInt());
*/
/*	vector<vector<int>> data;
	get2Darray(data);
	vector<Node *> graph(data.size());
	for (int i = 0; i < data.size(); i++) {
		graph[i] = new Node(i+1);
	}
	for (int i = 0; i < data.size(); i++) {
		for(int j = 0; j < data[i].size(); j++)
		{
			graph[i]->neighbors.push_back(graph[data[i][j] - 1]);
		}
	}
	cloneGraph(graph[0]);
*/

/*	vector<vector<string>> accounts;
	get2DStrings(accounts);
	accountsMerge(accounts); */
/*	vector<string> logs;
	int n = getInt();
	getStrings(logs);
	exclusiveTime(n, logs);
*/
/*	vector<char> tasks;
	getCharArray(tasks);
	leastInterval(tasks, getInt());
*/
/*	vector<string> dictionary;
	string phrase = getString();
	getStrings(dictionary);
	wordBreak(phrase, dictionary);
*/
	//cout << divide(getInt(), getInt());
	//cout << reverseWords(getNextLine());
	//cout << fractionToDecimal(getInt(), getInt());
	//cout << validIPAddress(getNextLine());
	//cout << numDecodings(getNextLine());
	/*vector<int> array;
	getIntArray(array);
	cout << checkSubarraySum(array, getInt());*/
	// 1249. Minimum Remove to Make Valid Parentheses
	//cout << minRemoveToMakeValid(getNextLine());
/*	TreeNode *node;
	getBinaryTree(&node);
	rightSideView(node);*/

/*	vector<vector<int>> A, B;
	get2Darray(A);
	get2Darray(B);
	intervalIntersection(A, B);*/


	return;
}

void AllInOneMedium::fillInput()
{
}

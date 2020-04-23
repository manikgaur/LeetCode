#pragma once
#include "Solution.h"

class TrieNode
{
public:
	bool isWord;
	TrieNode* node[26];
	TrieNode() :isWord(false), node(){}
};

class AllInOneMedium :
	public Solution
{
public:
	AllInOneMedium();
	int divide(int dividend, int divisor);
	string reverseWords(string s);
	string fractionToDecimal(int numerator, int denominator);
	string validIPAddress(string IP);
	int numDecodings(string s);
	bool checkSubarraySum(vector<int>& nums, int k);
	string minRemoveToMakeValid(string s);
	vector<int> productExceptSelf(vector<int>& nums);
	bool isAnagram(vector<int>& s1, vector<int>& s2);
	vector<int> findAnagrams(string s, string p);
	void dfs(TreeNode * root, vector<int>& result, int pos);
	vector<int> rightSideView(TreeNode * root);
	vector<int> mergeIntervals(vector<int> A, vector<int> B);
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B);
	TrieNode * createDictionary(vector<string>& wordDict);
	bool wordBreak(string s, vector<string>& wordDict);
	void solve();
	void fillInput();
};


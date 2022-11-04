
#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

#include <utility>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    int price;
    set<pair<int,int>> tried;
    set<int> jumpset;
    set<pair<int,int>> jump_pos_dist;
    vector<int> inorderRes;
    vector<int> ans;
    vector<string> strs;
    bool canJump(vector<int>& nums);
    bool Jump(vector<int>& nums,int pos);
    int jump(vector<int>& nums);
    bool isMatch(string s, string p);
    vector<int> inorderTraversalRecursion(TreeNode* root);
    int visit_inorder(TreeNode *root);
    vector<int> inorderTraversal(TreeNode* root);
    bool regex(string s,string p,int poss,int posp);
    int maxProfit(vector<int>& prices);
    void optionPrice(vector<int> & prices ,int day,int money);
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
    int gonextgas(vector<int> & gas,vector<int> & cost,int now,int oil,int end);
    int getlength(int num);
    int compare(int a,int b);
    void mysort(vector<int>& nums);
    string largestNumber(vector<int>& nums);
    string removeDuplicateLetters(string s);
    string removeDuplicateLetters_force(string s);
    void deleteLetter(string s,int *letters);
    bool compareString(string s1,string s2);
};


#endif

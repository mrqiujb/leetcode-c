
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
};


#endif

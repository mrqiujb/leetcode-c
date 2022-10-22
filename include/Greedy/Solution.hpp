
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
    set<pair<int,int>> tried;
    set<int> jumpset;
    vector<int> inorderRes;
    bool canJump(vector<int>& nums);
    bool Jump(vector<int>& nums,int pos);
    bool isMatch(string s, string p);
    vector<int> inorderTraversalRecursion(TreeNode* root);
    int visit_inorder(TreeNode *root);
    vector<int> inorderTraversal(TreeNode* root);
    bool regex(string s,string p,int poss,int posp);
};


#endif

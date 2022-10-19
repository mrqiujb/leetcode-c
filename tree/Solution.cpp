/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <Solution.hpp>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> inorderRes;
    vector<int> inorderTraversalRecursion(TreeNode* root) {
            if(root==NULL) return inorderRes;
            //访问左子树
            if(root->left!=NULL) this->inorderTraversalRecursion(root->left);
            //访问根节点
            inorderRes.push_back(visit_inorder(root));
            //访问右子树
            if(root->right!=NULL) this->inorderTraversalRecursion(root->right);
            return inorderRes;
    }
    int visit_inorder(TreeNode *root)
    {
        return root->val;
    }
    vector<int> inorderTraversal(TreeNode* root) {
            if(root==NULL) return inorderRes;
            stack<TreeNode *> nodes;
            TreeNode *now=root;
            while(!nodes.empty() || now !=NULL)
            {
                if(now!=NULL)
                {   
                    nodes.push(now);
                    now=now->left;
                }
                else
                {
                    now=nodes.top();
                    nodes.pop();
                    inorderRes.push_back(visit_inorder(now));
                    now=now->right;
                }
            }
            return inorderRes;
    }
};
#include "Solution.hpp"

//贪心
bool Solution::isMatch(string s, string p)
{
    if (s == "")
    {
        if (p == "" || p == "*")
            return true;
        else
            return false;
    }
    int i = 0, j = 0;
    while (i < s.length() && j < p.length())
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
            continue;
        }
        else
        {
            if (p[j] == '*')
            {
                while (p[++j] == s[i])
                {
                    i++;
                }
            }
            else if (p[j] == '?')
            {
                j++;
                i++;
            }
        }
    }
    if (i == s.length() - 1 && j == p.length() - 1)
        return true;
    return false;
}
vector<int> Solution::inorderTraversalRecursion(TreeNode *root)
{
    if (root == NULL)
        return inorderRes;
    //访问左子树
    if (root->left != NULL)
        this->inorderTraversalRecursion(root->left);
    //访问根节点
    inorderRes.push_back(visit_inorder(root));
    //访问右子树
    if (root->right != NULL)
        this->inorderTraversalRecursion(root->right);
    return inorderRes;
}
int Solution::visit_inorder(TreeNode *root)
{
    return root->val;
}
vector<int> Solution::inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return inorderRes;
    stack<TreeNode *> nodes;
    TreeNode *now = root;
    while (!nodes.empty() || now != NULL)
    {
        if (now != NULL)
        {
            nodes.push(now);
            now = now->left;
        }
        else
        {
            now = nodes.top();
            nodes.pop();
            inorderRes.push_back(visit_inorder(now));
            now = now->right;
        }
    }
    return inorderRes;
}
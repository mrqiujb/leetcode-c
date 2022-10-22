#include "../../include/Greedy/Solution.hpp"
//贪心
bool Solution::regex (string s,string p,int poss,int posp)
{
    if(tried.find(pair<int,int>{poss,posp})!=tried.end())//找过了
            return false;
    
    tried.insert({poss,posp});
    while (poss < s.length() && posp < p.length())
    {
        if (s[poss] == p[posp] || p[posp] == '?')
        {
            poss++;
            posp++;
            continue;
        }
        else if (p[posp] == '*')
        {
            while (p[posp] == '*')
            {
                posp++;
            }
            if (p[posp] == '\0')
                return true;
            for (size_t k = poss; k < s.length(); k++)
            {
                if (p[posp] == s[k]||p[posp]=='?')
                    if (regex(s,p,k,posp) == true)
                        return true;
            }
            return false;
            continue;
        }
        return false;
    }
    while (p[posp] == '*')
    {
        posp++;
    }
    if (poss == s.length() && posp == p.length())
        return true;
    return false;
};
bool Solution::isMatch(string s, string p)
{
    
    int m=0;
    while(p[m]!='\0')
    {
        if(p[m]=='*')
        {
            int k=m;
            while(p[++k]=='*');
            p.erase(m,k-m-1);
        }
        m++;
    }
    return regex(s,p,0,0);
};
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
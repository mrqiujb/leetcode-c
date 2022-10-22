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
bool Solution::canJump(vector<int>& nums)
{
    if(nums.size()==0) return true;
    int x=nums.size();x--;
    while (x>=0 && nums[x]==0)
    {
        x--;
    }
    int flag=x;
    for (;x>=0; x--)
    {
        if(x+nums[x]>flag&&x+nums[x]<nums.size()-1)
        {
            if(jumpset.size()==flag-x)
            {
                jumpset.insert(x);
                continue;
            }
            int i=x;
            for(;i<flag;i++)
            {
                if(jumpset.find(x+i)==jumpset.end()) break;
            }
            if(i==flag-1) jumpset.insert(x);
        }
    }
    return Jump(nums,0);
}
bool Solution::Jump(vector<int>& nums,int pos)
{
    if(pos==nums.size()-1) return true;
    if(nums[pos]==0) return false;  
    for (size_t i = 1; i <= nums[pos]; i++)
    {
        if(jumpset.find(pos+i)!=jumpset.end()) continue;
        if(Jump(nums,pos+i)==true) return true;
        jumpset.insert(pos+i);
    }
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
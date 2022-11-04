#include "../../include/Greedy/Solution.hpp"
//贪心
bool Solution::regex(string s, string p, int poss, int posp)
{
    if (tried.find(pair<int, int>{poss, posp}) != tried.end()) //找过了
        return false;

    tried.insert({poss, posp});
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
                if (p[posp] == s[k] || p[posp] == '?')
                    if (regex(s, p, k, posp) == true)
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
//正则匹配
bool Solution::isMatch(string s, string p)
{

    int m = 0;
    while (p[m] != '\0')
    {
        if (p[m] == '*')
        {
            int k = m;
            while (p[++k] == '*')
                ;
            p.erase(m, k - m - 1);
        }
        m++;
    }
    return regex(s, p, 0, 0);
};
bool Solution::canJump(vector<int> &nums)
{
    if (nums.size() == 0)
        return true;
    int x = nums.size();
    x--;
    while (x >= 0 && nums[x] == 0)
    {
        x--;
    }
    int flag = x;
    for (; x >= 0; x--)
    {
        if (x + nums[x] > flag && x + nums[x] < nums.size() - 1)
        {
            if (jumpset.size() == flag - x)
            {
                jumpset.insert(x);
                continue;
            }
            int i = x;
            for (; i < flag; i++)
            {
                if (jumpset.find(x + i) == jumpset.end())
                    break;
            }
            if (i == flag - 1)
                jumpset.insert(x);
        }
    }
    return Jump(nums, 0);
}
//跳跃游戏
bool Solution::Jump(vector<int> &nums, int pos)
{
    if (pos == nums.size() - 1)
        return true;
    if (nums[pos] == 0)
        return false;
    for (size_t i = 1; i <= nums[pos]; i++)
    {
        if (jumpset.find(pos + i) != jumpset.end())
            continue;
        if (Jump(nums, pos + i) == true)
            return true;
        jumpset.insert(pos + i);
    }
    return false;
}
//跳跃游戏二
int Solution::jump(vector<int> &nums)
{
    //每次都尽力跳，即跳到最远的距离
    //应该从倒数第二个元素开始跳
    //每次都找到能跳到范围内最短的距离 记为该位置最短距离
    if (nums.size() <= 1)
    {
        return 0;
    }
    else if (nums.size() == 2)
    {
        return 1;
    }
    // nums must above && equal 3
    // store distance
    vector<int> distance(nums.size(), 0);
    // init position
    int pos = nums.size() - 2;
    while (pos >= 0)
    {
        // if can dircet jump last ele ,then
        if (nums[pos] + pos >= nums.size() - 1)
        {
            distance[pos] = 1;
            pos--;
            continue;
        }
        int min = distance[pos + 1];
        // jump range pos+1 pos+nums[pos]
        // to find min distance elemnet pos
        for (size_t i = pos + 1; i <= pos + nums[pos]; i++)
        {
            if (distance[i] < min)
            {
                min = distance[i];
            }
        }
        // min distance add one step to insert set
        distance[pos] = min + 1;
        pos--;
    }
    return distance[0];
}

int jump(vector<int> &nums)
{
    int step = 0, start = 0, end = 1;
    while (end < nums.size())
    {
        int maxdis = 0;
        for (int i = start; i < end; i++)
        {
            maxdis = max(i + nums[i], maxdis);
        }
        start = end;
        end = maxdis;
        step++;
    }
    return step;
}

int Solution::maxProfit(vector<int> &prices)
{
    if (prices.size() <= 1)
        return 0;
    int profit = 0;
    for (size_t i = 1; i < prices.size(); i++)
    {
        if (prices[i] - prices[i - 1] > 0)
            profit += prices[i] - prices[i - 1];
    }
    return profit;
}
int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    //先写暴力解
    //假定从i号加油站出发
    //超时需要降复杂度--怎么降？
    //
    int ans = -1;
    int oil = 0;
    int count = 0;
    for (size_t i = 0; i < gas.size(); i++)
    {
        // gas 一堆1 cost 一堆0
        // if(cost[i]==gas[i]&& gas[i]==0) continue;
        //减少递归层数
        if (cost[i] == 0)
        {
            int j = i;
            while (cost[j] == 0 && j < cost.size() - 1)
            {
                count++;
                oil += gas[j];
                j++;
            }
            i = j;
        }
        oil += gas[i];
        if (oil >= cost[i])
        {
            // while()
            int temans = gonextgas(gas, cost, i + 1, oil - cost[i], i - count);
            if (temans > ans)
                ans = temans;
        }
        oil = 0;
        count = 0;
    }
    return ans;
}
int Solution::gonextgas(vector<int> &gas, vector<int> &cost, int now, int oil, int end)
{
    if (now == gas.size())
        now = 0;
    if (now == end)
        return now;
    while (cost[now] == 0 && now < gas.size())
    {
        oil += gas[now];
        now++;
    }
    oil += gas[now];
    if (oil >= cost[now])
    {
        return gonextgas(gas, cost, now + 1, oil - cost[now], end);
    }
    return -1;
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
int Solution::getlength(int num)
{
    int count = 0;
    while (num >= 1)
    {
        num = num / 10;
        count++;
    }
    return count;
}
int Solution::compare(int a, int b)
{
    // 23 24
    if (a * pow(10, getlength(b)) + b >= b * pow(10, getlength(a)) + a)
        return 1;
    else
        return 0;
}
void Solution::mysort(vector<int> &nums)
{
    for (size_t i = nums.size()-1; i >0 ; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            if(compare(nums[j],nums[j+1])==1)
            continue;
            else swap(nums[j],nums[j+1]);
        }
    }
    
}

string Solution::largestNumber(vector<int> &nums)
{
    int count=0;
    for (vector<int>::iterator it=nums.begin(); it !=(nums.end()-count); it++)
    {
        if(*it==0)
        {
            nums.erase(it);
            nums.push_back(0);
            it--;
            count++;
            continue;
        }
    }
    mysort(nums);
    //去除前导零
    int i=0;
    while(nums[i]==0 && i<nums.size()-1)
    {
        i++;
    }

    string str;
    for (; i < nums.size(); i++)
    {
        str.append(to_string(nums[i]));
    }
    return str;
    for (size_t i = 0; i < nums.size(); i++)
    {
        str.append(to_string(nums[i]));
    }
    return str;
}

string Solution::removeDuplicateLetters_force(string s) {
    int letters[26]={0};
    //扫一遍找到重复
    for (size_t i = 0; i < s.length(); i++)
    {
        letters[s[i]-97]++;
    }
    //想办法删除重复元素 暴力解
    deleteLetter(s,letters);
    int count=0;
    for (size_t i = 0; i < 26; i++)
    {
        if(letters[i]>0) count++;
    }
    for (vector<string>::iterator  i = strs.begin(); i !=strs.end(); i++)
    {
        if((*i).length()!=count)
        {
            strs.erase(i);
            i--;
        }
    }
    //所有可能的情况均已找到
    //找到最小的输出
    string a=strs[0];
    for (vector<string>::iterator  i = strs.begin()+1; i !=strs.end(); i++)
    {
        if(compareString(a,*i))//a>i
        {
            a=*i;
        }
    }
    return a;
}
bool Solution::compareString(string s1,string s2)
{
    int i=0;
    while (i<s1.length() && i<s2.length())
    {
        if(s1[i]>s2[i]) return true;
        else if(s1[i]<s2[i]) return false;
        else
        {
            i++;
        }
    }
    if(s1.length()>s2.length()) return true;
    return false;
}
void Solution::deleteLetter(string s,int *letters)
{
    int flag=0;
    for (size_t i = 0; i < 26; i++)
    {
        if(letters[i]==0 || letters[i]==1)
        {
            continue;
        }
        else
        {
            flag=1;
            letters[i]--;
            for (size_t j = s.length(); j>=0; j--)
            {
                if(s[j]==(i+97))
                { 
                    s.erase(j,1);
                    int cpyleeter[26];
                    memcpy(cpyleeter,letters,sizeof(int)*26);
                    string cpys=s;
                    deleteLetter(cpys,cpyleeter);
                    string tem(1,char(i+97));
                    s.insert(j,tem);
                }
            }
            
        }
    }
    if(flag==0) strs.push_back(s);
}

string Solution::removeDuplicateLetters(string s)
{
    //保存已排序元素
    stack<int> stack_letter;
    //标记元素是否在stack中存在
    bool flags[26];
    //标记每个字符最后出现的位置
    int letters[26];
    for (size_t i = 0; i < 26; i++)
    {
        flags[i]=false;
        letters[i]=-1;
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        if(letters[s[i]-97]<i)  letters[s[i]-97]=i;
    }
    int i=0;
    while (i<s.length())
    {
        if(flags[s[i]-97]==true)
        {
            i++;
            continue;
        }
        while (!stack_letter.empty())
        {
            int tem=stack_letter.top();
            if(letters[(s[tem]-97)]>i && s[tem]>s[i] )//后面还有这个元素，放弃当前元素选择后边的
            {
                stack_letter.pop();
                flags[s[tem]-97]=false;
            }
            else
            {
                break;
            }
        }
        if(flags[s[i]-97]==false)
        {
            stack_letter.push(i);
            flags[s[i]-97]=true;
        }
        i++;
    }
    string res;
    res.resize(stack_letter.size()+1);
    int count=stack_letter.size();
    for (size_t j = 0; j <count ; j++)
    {
        res[count-j-1]=s[stack_letter.top()];
        stack_letter.pop();
    }
    return res;
}
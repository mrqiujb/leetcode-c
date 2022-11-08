#include "/Users/qiujingbao/Documents/leetcode-c/include/DP/DP.hpp"

int DP::climbStairs(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    int a = 0, b = 0;
    if (int_maps.find(n - 1) != int_maps.end())
    {
        a = (*int_maps.find(n - 1)).second;
    }
    else
    {
        a = climbStairs(n - 1);
        int_maps.emplace(n - 1, a);
    }
    if (int_maps.find(n - 2) != int_maps.end())
    {
        b = (*int_maps.find(n - 2)).second;
    }
    else
    {
        b = climbStairs(n - 2);
        int_maps.emplace(n - 2, b);
    }
    return a + b;
}
int DP::lengthOfLIS(vector<int> &nums)
{
    int dp[nums.size()];
    for (size_t i = 0; i < nums.size(); i++)
    {
        dp[i] = 1;
        for (size_t j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    int max = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (dp[i] > max)
            max = dp[i];
    }
    return max;
}
int DP::fib(int n)
{
    if (n == 1)
        return 1;
    else if (n == 0)
        return 0;
    int a = 0, b = 0;
    if (int_maps.find(n - 1) != int_maps.end())
    {
        a = (*int_maps.find(n - 1)).second;
    }
    else
    {
        a = fib(n - 1);
        int_maps.emplace(n - 1, a);
    }
    if (int_maps.find(n - 2) != int_maps.end())
    {
        b = (*int_maps.find(n - 2)).second;
    }
    else
    {
        b = fib(n - 2);
        int_maps.emplace(n - 2, b);
    }
    return a + b;
}
int DP::tribonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 1;

    int a = 0, b = 0, c = 0;
    if (int_maps.find(n - 1) != int_maps.end())
    {
        a = (*int_maps.find(n - 1)).second;
    }
    else
    {
        a = tribonacci(n - 1);
        int_maps.emplace(n - 1, a);
    }
    if (int_maps.find(n - 2) != int_maps.end())
    {
        b = (*int_maps.find(n - 2)).second;
    }
    else
    {
        b = tribonacci(n - 2);
        int_maps.emplace(n - 2, b);
    }
    if (int_maps.find(n - 3) != int_maps.end())
    {
        c = (*int_maps.find(n - 3)).second;
    }
    else
    {
        c = tribonacci(n - 3);
        int_maps.emplace(n - 3, c);
    }
    return a + b + c;
}
int DP::maxProfit(vector<int> &prices)
{
    int dp[prices.size()][2];
    int hand_index = 0;
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    hand_index = 1;
    for (size_t i = 1; i < prices.size(); i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
        {
            //对于无票
            // 1.无票-》无票 2.有票-》无票
            dp[i][0] = (dp[i - 1][0] > (dp[i - 1][1] + prices[i])) ? dp[i - 1][0] : (dp[i - 1][1] + prices[i]);
            //对于有票
            // 1.无票-》有票 2.有票-》有票
            dp[i][1] = (dp[i - 1][0] - prices[i] > dp[i - 1][1]) ? dp[i - 1][0] - prices[i] : dp[i - 1][1];
        }
    }
    return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
}

int DP::minCostClimbingStairs(vector<int> &cost)
{
    int a = minCostClimbingStairsRecursive(cost.size(), cost);
}

int DP::minCostClimbingStairsRecursive(int n, vector<int> &cost)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 0;
    unordered_map<int, int>::iterator a_cost = int_maps.find(n - 1);
    unordered_map<int, int>::iterator b_cost = int_maps.find(n - 2);
    int a = 0, b = 0;
    if (a_cost == int_maps.end())
    {
        a = minCostClimbingStairsRecursive(n - 1, cost);
    }
    else
    {
        a = (*a_cost).second;
    }
    if (b_cost == int_maps.end())
    {
        b = minCostClimbingStairsRecursive(n - 2, cost);
    }
    else
    {
        b = (*b_cost).second;
    }
    int min_res = (a + cost[n - 1]) > (b + cost[n - 2]) ? (b + cost[n - 2]) : (a + cost[n - 1]);

    int_maps.emplace(n, min_res);
    return min_res;
}
int DP::rob(vector<int> &nums)
{
    return robRecursive(nums.size(), nums);
}
int DP::robRecursive(int n, vector<int> &nums)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return nums[0];
    unordered_map<int, int>::iterator a_cost = int_maps.find(n - 2);
    unordered_map<int, int>::iterator b_cost = int_maps.find(n - 3);
    int a = 0, b = 0;
    if (a_cost == int_maps.end())
    {
        a = robRecursive(n - 2, nums);
    }
    else
    {
        a = (*a_cost).second;
    }
    if (b_cost == int_maps.end())
    {
        b = robRecursive(n - 3, nums);
    }
    else
    {
        b = (*b_cost).second;
    }
    int max_res = (a + nums[n - 1]) > (b + nums[n - 2]) ? (a + nums[n - 1]) : (b + nums[n - 2]);

    int_maps.emplace(n, max_res);
    return max_res;
}

int DP::rob2(vector<int> &nums)
{
    if(nums.size()<=0) return 0;
    else if (nums.size()==1) return nums[0];
    else if(nums.size()==2) return max(nums[0],nums[1]);
    return max(rob2Range(nums,0,nums.size()-2),rob2Range(nums,1,nums.size()-1));
    
}
int DP::rob2Range(vector<int> &nums,int start,int end)
{
    vector<int> dp(end-start+1,0);
    dp[0]=nums[start];dp[1]=max(nums[start],nums[start+1]);
    for (size_t i = start+2; i <= end; i++)
    {
        dp[i-start]=max(nums[i]+dp[i-2],dp[i-1]);
    }
    return dp[end];
}
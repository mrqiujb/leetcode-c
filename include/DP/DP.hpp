#pragma once
#ifndef DP_H
#define DP_H

#include <utility>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <math.h>
#include <map>
#include <unordered_map>
using namespace std;


class DP {
    public:
        unordered_map<int,int> int_maps;
        int fib(int n);
        int climbStairs(int n);
        int lengthOfLIS(vector<int>& nums);
        int maxProfit(vector<int>& prices);
        int tribonacci(int n);
        int minCostClimbingStairs(vector<int>& cost);
        int minCostClimbingStairsRecursive(int n,vector<int>&cost);
        int rob(vector<int>& nums);
        int robRecursive(int n,vector<int>& nums);
        int rob2(vector<int>& nums);
        int rob2Range(vector<int> &nums,int start,int end);


};


#endif

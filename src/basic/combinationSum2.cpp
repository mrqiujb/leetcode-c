#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        //删除比target大的元素，因为没有负数所以不可能存在比target大的元素相加等于target的情况
        for (auto i = candidates.begin(); i !=candidates.end(); i++)
        {
            if(*i>target)
            {
                candidates.erase(i,candidates.end());
                break;
            }
        }
        int num_len=1;
        //最多所有元素相加等到target
        while (num_len<=candidates.size())
        {
            vector<int> index;
            index.resize(num_len);
            for (size_t i = 0; i < num_len; i++)
            {
                index[i]=i;
            }
            
            

        }
        
        
    }
};
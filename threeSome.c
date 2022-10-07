/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。


来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "common.c"
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 255
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}
//
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(numsSize<3) return NULL;
    //先排序
    qsort(nums,numsSize,sizeof(int),compare_ints);
    //分配空间
    int **res=(int**)malloc(sizeof(int *)*MAX_SIZE);
    *returnColumnSizes=(int*)malloc(sizeof(int)*MAX_SIZE);
    //指明当前结果个数
    int count=0;
    for (size_t i = 0; i < numsSize; i++)
    {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;int k=numsSize-1;
        while (j!=k&&j<k)
        {
            //???
            if(j>i+1 &&nums[j]==nums[j-1])
            {
                j++;continue;
            }
            if(k<numsSize-2&&nums[k]==nums[k+1])
            {
                k--;continue;
            }
            if(nums[i]+nums[j]+nums[k]==0)
            {
                //目标元素找到，先存起来
                res[count]=(int *)malloc(sizeof(int)*3);
                res[count][0]=nums[i];res[count][1]=nums[j];res[count][2]=nums[k];
                (*returnColumnSizes)[count]=3;
                j++;k--;count++;
            }
            else if(nums[i]+nums[j]+nums[k]>0)
            {
                k--;
            }
            else if(nums[i]+nums[j]+nums[k]<0)
            {
                j++;
            }
        }
        
    }
    *returnSize=count;
    return res;
}
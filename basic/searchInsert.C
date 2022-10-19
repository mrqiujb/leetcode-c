#include "common.c"

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/search-insert-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int searchInsert(int* nums, int numsSize, int target){
    //数组有序
    int i=0;
    while (i<numsSize)
    {
        if(nums[i]<target) i++;
        else
        {
            break;
        }
    }
    return i;
}
int searchInsertx(int* nums, int numsSize, int target){
    //数组有序
    int left=0,right=numsSize-1;
    int mid=0;
    while (left<right)
    {
        mid=(left+right)/2;
        if(target==nums[mid]) break;
        else if(target>nums[mid])
        {
            left=mid+1;
        }
        else if(target<nums[mid])
        {
            right=mid-1;
        }
    }
    
    
    return left;
}
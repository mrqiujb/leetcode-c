/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ans=(int *)malloc(sizeof(int)*2);
    //暴力解 双重for
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                ans[0]=i;
                ans[1]=j;
                *returnSize=2;
                return ans;
            }
        }
    }
    *returnSize=2;
    return ans;
}

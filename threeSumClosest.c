#include "common.c"
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

int threeSumClosest(int* nums, int numsSize, int target){
    if(numsSize<3) return -1;
    qsort(nums,numsSize,sizeof(int),compare_ints);
    int close=nums[0]+nums[1]+nums[2];
    for (size_t i = 0; i < numsSize; i++)
    {
        int j=i+1;
        int k=numsSize-1;
        while (k!=j && k>j)
        {
            if(nums[i]+nums[j]+nums[k]>target)
            {
                if(abs(close-target)>abs(nums[i]+nums[j]+nums[k]-target))
                {
                    close=nums[i]+nums[j]+nums[k];
                }
                k--;
            }
            else if(nums[i]+nums[j]+nums[k]<target)
            {
                if(abs(close-target)>abs(nums[i]+nums[j]+nums[k]-target))
                {
                    close=nums[i]+nums[j]+nums[k];
                }
                j++;
            }
            //直接相等，不用寻找了
            else
            {
                return target;
            }
        }
        
    }
    return close;
    



}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "common.c"
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

int* findDuplicates(int* nums, int numsSize, int* returnSize){
    qsort(nums,numsSize,sizeof(int),compare_ints);
    int count=0;
    for (size_t i = 0; i < numsSize; i++)
    {
        if(i+1<numsSize&&nums[i]==nums[i+1])
        {
            count++;
        }
    }
    int *res=(int*)malloc(sizeof(int)*count);
    for (size_t i = 0; i < numsSize; i++)
    {
        if(i+1<numsSize&&nums[i]==nums[i+1])
        {
            res[count]=nums[i];
        }
    }
    *returnSize=count;
    return res;
    
    
}
#define MAX_SIZE 255
int* findDuplicatesx(int* nums, int numsSize, int* returnSize){
    if(numsSize==0 && numsSize==1){ *returnSize=0; return NULL;}
    int count=0;
    int *res=(int*)malloc(sizeof(int)*MAX_SIZE);
    int i=0;
    
    while (i<numsSize)
    {
        if(nums[i]==-1)
        {
            i++;
            continue;
        }
        if(nums[i]==i+1)
        {
            i++;
            continue;
        }
        if(nums[i]==nums[nums[i]-1])
        {
            res[count++]=nums[i];
            nums[i]=-1;
            i++;
            count++;
            continue;
        }
        if (nums[i]!=nums[nums[i]-1])
        {
            int tem=0;
            tem=nums[i];
            nums[i]=nums[tem-1];
            nums[tem-1]=tem;
        }
    }
    
    *returnSize=count;
    return res;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include "common.c"
#define MAX_SIZE 255
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int count=0;
    int **res=(int**)malloc(sizeof(int *)*MAX_SIZE);
    *returnColumnSizes=(int*)malloc(sizeof(int)*MAX_SIZE);
    if(numsSize<4) {
        *returnSize=count;
        return res;
        
    } ;
    qsort(nums,numsSize,sizeof(int),compare_ints);
    if(target>=0 && nums[0]>target)
    {
        *returnSize=count;
        return res;
        
    }
    //分配空间
    
 // -5 -4 -3 -2 1 3 3 5   
    for (size_t i = 0; i < numsSize-3; i++)
    {
        if(i>0&&nums[i]==nums[i-1])
        {
            continue;
        }
        for (size_t j = i+1; j < numsSize-2; j++)
        {
            if(j>i+1&&nums[j]==nums[j-1])
            {
                continue;
            }
            int k=j+1;int x=numsSize-1;
            while (k!=x && k<x)
            {
                if((k>j+1)&&nums[k]==nums[k-1])
                {
                    k++;
                    continue;
                }
                if((x<numsSize-1 && nums[x]==nums[x+1]))
                {
                    
                    x--;
                    continue;
                }
                long long int tem=(long)nums[i]+(long)nums[j]+(long)nums[k]+(long)nums[x];
                if(tem==target)
                {
                    //目标元素找到，先存起来
                    res[count]=(int *)malloc(sizeof(int)*4);
                    res[count][0]=nums[i];res[count][1]=nums[j];res[count][2]=nums[k];res[count][3]=nums[x];
                    (*returnColumnSizes)[count]=4;
                    count++;
                    k++;x--;
                    
                }
                else if(tem>target)
                {
                    x--;
                }
                else if(tem<target)
                {
                    k++;
                }
            }
        }
        
    }
    *returnSize=count;
    return res;
}
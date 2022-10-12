/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include "common.c"
#define MAX_SIZE 255
int num_size;
int resSize;
int combineSize;
int *ansColumnSize;


void dfs(int *candidates,int target,int **res,int *combine,int idx)
{
   if(idx==num_size) return;
   if(target==0)
   {
        int *tem=malloc(sizeof(int)*combineSize);
        memcpy(tem,combine,sizeof(int)*combineSize);
        res[resSize]=tem;
        ansColumnSize[resSize++]=combineSize;
        return;
   }
   dfs(candidates,target,res,combine,idx+1);
   if(target-candidates[idx]>=0)
   {
        combine[combineSize++]=candidates[idx];
        dfs(candidates,target-candidates[idx],res,combine,idx);
        combineSize--;
   }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    num_size=candidatesSize;
    int end=candidatesSize-1;
    for (size_t i = 0; i < candidatesSize; i++)
    {
        if(candidates[i]>=target)
        {
            end=i;
        }
    }
    num_size=end;
    int **res=(int **)malloc(sizeof(int *)*MAX_SIZE);
    *ansColumnSize = (int*)malloc(MAX_SIZE * sizeof(int));
    int combine[MAX_SIZE];
    dfs(candidates,target,res,combine,0);
    *returnSize=resSize;
    *returnColumnSizes=ansColumnSize;
    return res;
}
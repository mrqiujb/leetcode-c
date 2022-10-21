/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int i=0,j=0;
    for(;i<numsSize;i++)
    {
        if(nums[i]==target)
        {
            j=i;
            while(++j<numsSize &&nums[j]==target);
            break;
        }
    }
    int *res=(int *)malloc(sizeof(int)*2);
    res[0]=-1;res[1]=-1;
    *returnSize=2;
    if(i<numsSize)
    {
        res[0]=i;res[1]=j-1;
        return res;
    }
    return res;
}
#include <stdio.h>
#include <string.h>
//#include "isPalindrome.c"
#include "topKFrequent.c"
int main()
{
    int *nums=(int *)malloc(sizeof(int)*6);
    nums[0]=1;nums[1]=1;nums[2]=1;nums[3]=2;nums[4]=2;nums[5]=3;
    int *res=(int *)malloc(sizeof(int));
    int *b= topKFrequent(nums,6,2,res);
    for (size_t i = 0; i < res[0]; i++)
    {
        printf("%d ",b[i]);
    }
    
}
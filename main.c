#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "threeSome.c"
int main()
{
    int nums[]={-1,0,1,2,-1,-4};
    int **a=malloc(sizeof(int **));
    int *returnsize=(int *)malloc(sizeof(int));
    threeSum(nums,6,returnsize,a);
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "findDuplicates.c"
int main()
{
    int nums[]={4,3,2,7,8,2,3,1};
    int **a=malloc(sizeof(int **));
    int *returnsize=(int *)malloc(sizeof(int));
    findDuplicatesx(nums,8,returnsize);
}
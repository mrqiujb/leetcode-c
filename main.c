#include <stdio.h>
#include <string.h>
//#include "isPalindrome.c"
#include "merge_56.c"
int main()
{
    
    int p[][2]={1,3,2,6,8,10,15,18};
    int *a[4];
    a[0]=p[0];
    a[1]=p[1];
    a[2]=p[2];
    a[3]=p[3];

    int *returnsize=(int *)malloc(sizeof(int));
    int **b=(int **)malloc(sizeof(int*));
    int *c=(int *)malloc(sizeof(int));
    *c=2;
    merge(a,4,c,returnsize,b);

}
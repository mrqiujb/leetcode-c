#include <stdio.h>
#include <string.h>
#include "myAtoi.c"

int main()
{
    //char *s="-2147483648";
    //int b= myAtoi(s);
    //printf("%d",b);
    int a=147483699;
    a+=2*pow(10,9);
    printf("%d",a);
}
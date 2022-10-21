#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
int char2int(char a)
{
    int res=-1;
    switch (a)
    {
    case '0':
        res=0;
        break;
    case '1':
        res=1;
        break;
    case '2':
        res=2;
        break;
    case '3':
        res=3;
        break;
    case '4':
        res=4;
        break;
    case '5':
        res=5;
        break;
    case '6':
        res=6;
        break;
    case '7':
        res=7;
        break;
    case '8':
        res=8;
        break;
    case '9':
        res=9;
        break;   
    default:
        break;
    }
    return res;
}
char int2char(int x)
{
    char res='a';
    switch (x)
    {
    case 0:
        res='0';
        break;
    case 1:
        res='1';
        break;
    case 2:
        res='2';
        break;
    case 3:
        res='3';
        break;
    case 4:
        res='4';
        break;
    case 5:
        res='5';
        break;
    case 6:
        res='6';
        break;
    case 7:
        res='7';
        break;
    case 8:
        res='8';
        break;
    case 9:
        res='9';
        break;
    default:
        break;
    }
    return res;
}
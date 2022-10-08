/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/roman-to-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "common.c"
int romanToInt(char * s){
    char *a=s;
    int res=0;
    int count=0;
    while (*a!='\0')
    {
        switch (*a)
        {
            case 'I':
                res+=1;
                break;
            case 'V':
                res+=5;
                /* code */
                break;
            case 'X':
                res+=10;
                /* code */
                break;
            case 'L':
                res+=50;
                /* code */
                break;
            case 'C':
                res+=100;
                /* code */
                break;
            case 'D':
                res+=500;
                /* code */
                break;
            case 'M':
                res+=1000;
                /* code */
                break;
        default:
            return -1;
            break;
        }
        a=(a+1);
        count++;
    }
    a=s;
    for (size_t i = 0; i < count; i++)
    {
        if(*(a+i)=='I'&&i+1<count && *(a+i+1)=='V')
        {
            res-=2;
        }
        else if(*(a+i)=='I'&&i+1<count && *(a+i+1)=='X')
        {
            res-=2;
        }
        else if(*(a+i)=='X'&&i+1<count && *(a+i+1)=='L')
        {
            res-=20;
        }
        else if(*(a+i)=='X'&&i+1<count && *(a+i+1)=='C')
        {
            res-=20;
        }
        else if(*(a+i)=='C'&&i+1<count && *(a+i+1)=='D')
        {
            res-=200;
        }
        else if(*(a+i)=='C'&&i+1<count && *(a+i+1)=='M')
        {
            res-=200;
        }
    }
    return res;
    
}
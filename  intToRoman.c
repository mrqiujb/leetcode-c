/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给你一个整数，将其转为罗马数字。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/integer-to-roman
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//1 <= num <= 3999
#include "common.c"
char * intToRoman(int num){
    if(num<1 || num>3999) return NULL;
    char *res=(char *)malloc(sizeof(char)*20);
    for (size_t i = 0; i < 20; i++)
    {
        res[i]='\0';
    }
    int tem=0; int count=0;
    //千位处理
    if(num/1000>0)
    {
        tem=num/1000;
        num=num-tem*1000;
        for (;tem>0; tem--,count++)
        {
            res[count]='M';
        }
    }
    //百位处理
    if(num/100>0)
    {
        tem=num/100;
        num=num-tem*100;
        if(tem==4)
        {
            res[count++]='C';
            res[count++]='D';
        }
        else if(tem==9)
        {
            res[count++]='C';
            res[count++]='M';
        }
        else
        {
            if(tem>=5)
            {
                res[count++]='D';
                tem=tem-5;
            }
            for (; tem>0;tem--,count++)
            {
                res[count]='C';
            }
        }
    }
    //十位处理
    if(num/10>0)
    {
        tem=num/10;
        num=num-tem*10;
        if(tem==4)
        {
            res[count++]='X';
            res[count++]='L';
        }
        else if(tem==9)
        {
            res[count++]='X';
            res[count++]='C';
        }
        else
        {
            if(tem>=5)
            {
                res[count++]='L';
                tem=tem-5;
            }
            for (; tem>0;tem--,count++)
            {
                res[count]='X';
            }
        }
        
    }
    //个位处理
    if(num>0)
    {
        tem=num;
        num=num-tem;
        if(tem==4)
        {
            res[count++]='I';
            res[count++]='V';
        }
        else if(tem==9)
        {
            res[count++]='I';
            res[count++]='X';
        }
        else
        {
            if(tem>=5)
            {
                res[count++]='V';
                tem=tem-5;
            }
            for (; tem>0;tem--,count++)
            {
                res[count]='I';
            }
        }
    }
    return res;
}
#include "common.c"
/*

给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
//解法一
bool isPalindrome(int x){
    if(x<0) return 0;
    //int最大的值是2147483647再加上一个负号，所以字符串最大长度为11位
    //1234567899
    char *str=(char *)malloc(sizeof(char)*10);
    int num=x;
    int i=0;
    while (num/=10!=0)
    {
        int tem=num%10;
        *(str+i)=int2char(tem);
        i++;
        num=num/10;
    }
    for(int j=0;j<i/2;j++)
    {
        if(*(str+j)!=*(str+i-j-1)) return 0;
    }
    return 1;
}
//解法二
bool isPalindrome2(int x){
    if(x<0) return 0;
    int *num=(int *)malloc(sizeof(int)*1);
    size_t i=0;
    while(*num)
    {
        *num=*num/10;
        i++;
    }
    free(num);
    for (size_t j = 0; j <= i/2; j++)
    {
        if((int)(x/pow(10,j))%10!=(int)(x/pow(10,i-j-1))%10) return 0;
    }
    return 1;
}
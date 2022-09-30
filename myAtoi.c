/*

请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/string-to-integer-atoi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include "common.c"
int myAtoi(char * s){
    int num_sign=0;    
    char *t=s;
    //去除前导空格
    while (*(t)==' ')
    {
        t=t+1;
    }
    //当前t指向第一个字符
    char sign=*(t);
    if (sign=='-')
    {
        num_sign=-1;
        t++;
    }
    else if(sign=='+')
    {
        num_sign=1;
        t++;
    }
    else
    {
        num_sign=1;
    }
    
    //去除前导0
    while (*(t)=='0')
    {
        t=t+1;
    }
    char *begin=t;
    while (('0'-1)<(*t)&&(*t)<('9'+1)&&*t!='\0')
    {
        t=t+1;
    }
    char *end=t-1;
    //找到了数字部分的起始位置和结束位置，开始进行求和
    int res=0,weight=0;
    while (end-begin!=-1)
    {
        int num=char2int(*end);
        if(num<0||num>9) return -1;
        res+=(num*pow(10,weight));
        if(res<0)
        {
            //-2147483648这个数会转换错误，因为统一按照正数转换的
            if(num_sign==1) {return INT_MAX;}
            else if (num_sign==-1) {
                
                
                return INT_MIN;}
            
        }
        end--;
        weight++;
    }
    if (num_sign==-1)
    {
        res=-res;
    }
    return res;
}

/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/*
leetcode 里面这种二位数组的返回值的问题。
一般有两个需要返回的参数，int* returnSize, int** returnColumnSizes
先来看一下这两个是如何在函数外部定义的，也就是如何传进来的
int **returnColumnSizes=(int **)malloc(sizeof(int*));
int *returnSize=(int *)malloc(sizeof(int));
foo(a,b,c,returnSize,returnColumnSizes);
上述表示，两个变量空间已经分配，而不是光一个空指针，所以直接赋值就可以。
returnSize---》|   地址p    | --》p｜   内容   ｜
从含义来讲
对于returnSize来说，是二维数组的行数。返回格式如下
*returnSize=count; 直接找到指针所指向的内存地址的内容，然后直接覆盖即可。
对于returnColumnSizes来讲，是二位数组每一行的列数。首先已经分配了int*首地址的空间
returnColumnSizes --》｜ 地址x ｜--》x｜   内容a   ｜ --》b｜  一维数组   ｜
先创建一维数组
int *b= (int*)malloc(count * sizeof(int));//一维数组长度为count
因为二维数组为指针的指针，所以先解引用*returnColumnSizes获得这个指针指向的内存单元，此单元存储一维数组首地址
然后直接赋值。
*returnColumnSizes=b;


二维数组的创建
int** pRes = (int**)malloc(len * sizeof(int*));
for (int i = 0; i < len; i++)
{
    pRes[i] = (int*)malloc(2 * sizeof(int)); // 为每个结点分配一个数组空间，元素个数为列数
} 
假设需要创建n行*m列的二维数组
首先先创建n行，采用二级指针的形式
int** pRes = (int**)malloc(len * sizeof(int*));
此时二维指针每加一都会是一行
然后创建列，对于每一行创建列
每一列存储m个元素，所以先malloc sizeof(int)*m个元素转化为一级指针，放到二级指针指向的一级指针的内存空间中。
此时二维数组在内存的堆里面不是连续的。

二位数组内容的copy
memcpy(目的地址,原地址,2*sizeof(int));//2个int 

*/



#include "common.c"
int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
                                         int* returnSize, int** returnColumnSizes){    
    bool *flags=(bool *)malloc(sizeof(bool)*intervalsSize);
    for(size_t i=0;i<intervalsSize;i++)
    {
        flags[i]=false;
    }
    int count=0;
    for (size_t i = 0; i < intervalsSize-1; i++)
    {
        //[1,8] [1,9] [1,10]
        if(intervals[i][0]==intervals[i+1][0])
        {
            flags[i]=1;
            count++;
        }
        //[2,4] [3,9]
        else if(intervals[i][1]>intervals[i+1][0])
        {
            flags[i]=1;
            intervals[i+1][0]=intervals[i][0];
            count++;
        }
    }
    int len=intervalsSize-count;
    int** pRes = (int**)malloc(len * sizeof(int*));
    for (int i = 0; i < len; i++)
    {
        pRes[i] = (int*)malloc(2 * sizeof(int)); // 为每个结点分配一个数组空间，元素个数为列数
    } // 此时返回的二维数组创建完毕
    count=0;
    for (size_t i = 0; i < intervalsSize; i++)
    {
        if(flags[i]==false)
        {
            memcpy(pRes[count],intervals[i],2*sizeof(int));//2个int 
            count++;
        }
    }
    
    *returnSize=count;
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    for(size_t i=0;i<count;i++)
    {
        (*returnColumnSizes)[i]=2;
    }
    return pRes;
}
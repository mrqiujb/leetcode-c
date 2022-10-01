/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include "common.c"
int maxArea(int* height, int heightSize){
    int maxarea=0;
    for (size_t i = 0; i < heightSize; i++)
    {
        for (size_t j = i+1; j < heightSize; j++)
        {
            int temmax=(j-i)*min(*(height+i),*(height+j));
            if(temmax>maxarea) maxarea=temmax;
        }
        
    }
    
}
int maxArea2(int* height, int heightSize){
    int i=0,j=heightSize-1;
    int maxarea=0;
    while (i!=j)
    {
        if(*(height+i)>*(height+j))
        {
            if((j-i)*(*(height+j))>maxArea) maxarea=(j-i)*(*(height+j));
            j--;
        }
        else
        {
            if((j-i)*(*(height+i))>maxArea) maxarea=(j-i)*(*(height+i));
            i++;
        }
    }
    return maxarea;
    
}
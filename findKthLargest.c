/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int quick_Sort(int *num,int low,int high,int k,int size)
{
    int pre=num[low];
    int i=low+1;
    int j=high;
    while (j-i!=-1)
    {
        if(num[i]<pre)
        {
            i++;
            continue;
        }
        if(pre<=num[j])
        {
            j--;
            continue;
        }
        int tem=num[i];
        num[i]=num[j];
        num[j]=tem;
    }
    num[low]=num[j];
    num[j]=pre;
    if(j==size-k) return num[j];
    if(j<size-k) return quick_Sort(num,j+1,high,k,size);
    if(size-k<j) return quick_Sort(num,low,j-1,k,size);
}


int findKthLargest(int* nums, int numsSize, int k){
    //方法一
    //qsort(nums,numsSize,sizeof(int),cmp);
    //return nums[numsSize-k];
    int res= quick_Sort(nums,0,numsSize-1,k,numsSize);
    return res;
}
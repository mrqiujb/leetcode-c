/*
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

将最终结果插入 nums 的前 k 个位置后返回 k 。

不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

判题标准:

系统会用下面的代码来测试你的题解:

int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
如果所有断言都通过，那么您的题解将被 通过。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "common.c"
int removeDuplicates(int* nums, int numsSize){
    int k=numsSize;
    for (size_t i = numsSize-1; i>0; i--)
    {
        if(nums[i]==nums[i-1])
        {
            k--;
            for (size_t j = i;j<numsSize-1; j++)        
            {
                nums[j]=nums[j+1];
            }
        }
    }
    return k;
    
}
int removeDuplicatesx(int* nums, int numsSize){
    if(numsSize<2) return numsSize;
    int p=0,q=1;

    while (p!=q&&q<numsSize-1)
    {
        if(nums[p]!=nums[q])
        {
            p++;q++;
            continue;
        }


       if(nums[q]==nums[q+1])
       {
           q++;
            continue;
        }
        p++;q++;
       nums[p]=nums[q];
    }
    if(nums[p]!=nums[q])
    {
        nums[++p]=nums[q];
    }
    return p+1;
}
 
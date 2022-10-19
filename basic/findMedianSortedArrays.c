double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
    //先合并再找中位数 这两步的时间复杂度都是o(m+n)
    if (nums1Size == 0 && nums2Size == 0)
        return 0;
    int* count = (int*)malloc(sizeof(int) * (nums2Size + nums1Size));
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] > nums2[j]) {
            count[k] = nums2[j];
            j++;
        } else {
            count[k] = nums1[i];
            i++;
        }
        k++;
    }
    if (i != nums1Size) {
        for (; i < nums1Size; i++) {
            count[k] = nums1[i];
            k++;
        }
    } else if (j != nums2Size) {
        for (; j < nums2Size; j++) {
            count[k] = nums2[j];
            k++;
        }
    }
    double res = 0.0;
    if ((nums1Size + nums2Size) % 2 == 1) {
        res = count[k / 2];
    } else {
        res = (count[k / 2] + count[k / 2 - 1]) / 2.0;
    }
    return res;
}

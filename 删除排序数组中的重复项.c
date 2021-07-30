#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    int i, j, k = 1;
    if (numsSize == 0) return 0;
    for (i = 1; i < numsSize; i++) {
        // 外循环需要设置停止标志，否则会因内循环重复遍历更小元素导致新数组出现重复情况
        if (nums[i - 1] == nums[numsSize - 1]) break;
        for (j = i; j < numsSize; j++) {
            if (nums[j] > nums[i - 1]) {
                nums[i] = nums[j];
                k++;
                break;
            }
        }
    }
    return k;
}
	//int n = sizeof(nums) / sizeof(nums[0]);
	//return n;
int main()
{
    int arr[10] = { 0,0,1,1,1,2,2,3,3,4 };
	int numsSize = 10;
	printf("%d\n", removeDuplicates(arr, numsSize));
	for (int t = 0; t < removeDuplicates(arr, numsSize) ; t++)
	{
		printf("%d ", arr[t]);
	}
	return 0;
}
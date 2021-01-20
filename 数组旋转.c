#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void reserve(int* nums, int i, int j)
{
	while (i < j)
	{
		nums[i] ^= nums[j];
		nums[j] ^= nums[i];
		nums[i] ^= nums[j];
		i++;
		j--;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	if (numsSize <= 1)
		return;
	k %= numsSize;
	if (k == 0)
		return;
	reserve(nums, 0, numsSize - k - 1);
	reserve(nums, numsSize - k, numsSize - 1);
	reserve(nums, 0, numsSize-1);
}
//int main()
//{
//	int arr[7] = { 1,2,3,4,5,6,7 };
//	//int n = sizeof(arr) / sizeof(arr[0]);
//	int n = 7;
//	int k = 3;
//	rotate(arr, n, k);
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

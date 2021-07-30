#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	for (int i = m; i < m + n; i++)
	{
		*(nums1 + i) = *(nums2 + i - m);
	}
	for (int k = 0; k < m + n; k++) {
		for (int g = k+1; g < m + n; g++) {
			if (nums1[k] > nums1[g]) {
				nums1[k] ^= nums1[g];
				nums1[g] ^= nums1[k];
				nums1[k] ^= nums1[g];

			}
		}
	}
}
//int main()
//{
//	int arr1[6] = { 1,2,3,0,0,0};
//	int arr2[3] = { 2,5,6 };
//	int num1Size = 6;
//	int m = 3;
//	int num2Size = 3;
//	int n = 3;
//   merge(arr1, num1Size, m, arr2, num2Size, n);
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
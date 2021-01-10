//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void Change(int arr[], int n)
//{
//	int i = 0;
//	int* start = arr;
//	int* end = arr + n - 1;
//	while (start < end)
//	{
//		*start ^= *end;
//		*end ^= *start;
//		*start ^= *end;
//		while((*start) & 1)
//		{
//			start++;
//		}
//		while (!((*end) & 1))
//		{
//			end--;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int num = sizeof(arr1) / sizeof(arr1[0]);
//	Change(arr1, num);
//	return 0;
//}
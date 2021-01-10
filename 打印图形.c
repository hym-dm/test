//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[] = "***************";
//	char arr2[] = "               ";
//	char arr3[] = "               ";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	int mid = (left + right) / 2;
//	int left1 = mid - 1;
//	int right1 = mid + 1;
//	int left2 = left + 1;
//	int right2 = right - 1;
//	arr2[mid] = arr1[mid];
//	printf("%s\n", arr2);
//	while (left1 > left && right1 < right)
//	{
//		arr2[left1] = arr1[left1];
//		arr2[right1] = arr1[right1];
//		left1--;
//		right1++;
//		printf("%s\n", arr2);
//	}
//	//arr2[left] = arr3[left];
//	//arr2[right] = arr3[right];
//	//printf("%s\n", arr2);
//	while (left2 < right2)
//	{
//		arr2[left2] = arr3[left2];
//		arr2[right2] = arr3[right2];
//		left2++;
//		right2--;
//		printf("%s\n", arr2);
//	}
//	return 0;
//}
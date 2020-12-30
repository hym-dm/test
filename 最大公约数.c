#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int a = 0;
//	int b = 0;
//	int ret = 0;
//	printf("请输入两个数:>");
//	scanf("%d,%d", &x, &y);
//	if (x > y)
//	{
//		for (a = 1; a <= x; a++)
//		{
//			if (x % a == 0 && y % a == 0)
//				ret = a;
//		}
//
//	}
//	else
//	{
//		for (b = 1; b <= y; a++)
//		{
//			if (x % a == 0 && y % a == 0)
//				ret = a;
//		}
//	}
//		printf("两数的最大公约数为: %d\n", ret);
//	
//	return 0;
//}
//	int leap_year(int year)
//	{
//		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//			return 1;
//		else
//			return 0;
//	}
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (leap_year(year) == 1)
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//
//		for (j = 2; j < i/2; j++)
//		{
//		
//			if (i % j == 0)
//				break;
//		}
//		if (j == i/2)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//    int	num = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			num++;
//		if (i / 10 == 9)
//			num++;
//	}
//	printf("9的个数为:%d\n", num);
//  return 0;
//}
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//			sum = sum + (double)1 / i;
//		else
//			sum = sum - (double)1 / i;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
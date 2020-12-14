//#define  _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	printf("请输入三个数\n");
//	scanf("%d %d %d", &a, &b, &c);
//	if (a >= b && a >= c)
//	{
//		if (b >= c)
//			printf("%d >= %d >= %d\n", a, b, c);
//		else
//			printf("%d >= %d > %d\n", a, c, b);
//	}
//	else if (a >= b && a < c)
//		printf("%d > %d >= %d\n", c, a, b);
//	else if (a >= c && a < b)
//		printf("%d > %d >= %d\n", b, a, c);
//	else
//	{
//		if (b > c)
//			printf("%d > %d > %d\n", b, c, a);
//		else
//			printf("%d >= %d > %d\n", c, b, a);
//	}
//	return 0;
//}
#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	//for (i = 1; i <= 100; i++ )
	while (i <= 100)
	{
		i++;
		if (i % 3 == 0)
			printf("%d ", i);
	}
	return 0;
}
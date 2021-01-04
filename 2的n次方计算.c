#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	scanf("%d", &a);
//	scanf("%d", &b);
//	if (a >= 0 && a < 31 && b >= 0 && b < 31)
//	{
//		c = 1;
//		c = c << a;
//		d = 1;
//		d = d << b;
//	}
//	printf("%d\n", c);
//	printf("%d", d);
//	return 0;
//}
int main()
{
	int a = 0;
	printf("%d", sizeof a);
	while (scanf("%d", &a) != EOF)
	/*while(1)*/
	{
	/*	scanf("%d", &a);*/
		if(a>= 0 && a<32)
		printf("%d\n", 1 << a);
	/*	if (scanf("%d", &a) == EOF);*/
		break;
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	int a[100][100] = {0,1};
	while (n < 1 || n > 100)
	{
		printf("请输入杨辉三角的行数\n");//可写博客
		scanf("%d", &n);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i;j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
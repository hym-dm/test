#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	int a[100][100] = { 1 };
	while (n < 1 || n > 100)
	{
		printf("������Ҫ��ӡ��������ǵ�����\n");
		scanf("%d", &n);
	}
	for (i = 1; i <= n; i++)
	{
		a[i][0] = 1;
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
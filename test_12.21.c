#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//		{
//			printf("hehe\n");
//		}
//	}
//	else
//		printf("haha\n");
//	return 0;
//}
//int main()
//{
//	int day = 0;
//	switch (day)
//	{
//	case 1:
//		printf("����һ\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	}
//	return 0;
//}
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;
//	case 2:
//		n++;
//	case 3:
//		switch (n)
//		{
//		case 1:
//			n++;
//		case 2:
//			m++;
//			n++;
//			break;
//		}
//	case 4:
//		m++;
//		break;
//	default:
//		break;
//	}
//	printf("%d,%d\n", m, n);
//	return 0;
//}
	//int main()
	//{
	//	int i = 0;
	//	while (i < 10)
	//	{
	//		i = i + 1;
	//		if (i == 5)
	//			continue;
	//		printf("%d\n", i);
	//		//i = i + 1;
	//	}
	//	return 0;
	//}
	int main()
	{
		int ch = 0;
		while ((ch = getchar()) != EOF)
		{
			if (ch < '0' || ch>'9')
				continue;
			putchar(ch);
		}
			
		return 0;
	}
	
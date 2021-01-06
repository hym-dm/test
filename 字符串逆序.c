//#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//void Hehe(const char* str, int n)
//{
//	int i = 0;
//	char str2[100];
//	char* str3 = str2;
//	for (i = 0; i < n; i++)
//	{
//		*(str3 + i) = *(str + n - i - 1);//可以直接用字符数组下标进行赋值，那样更加简洁，此处尝试用数组指针完成以练习语法
//		printf("%c",*(str3+i));
//	}
//}
//int main()
//{
//	char str1[100];
//	int x = 0;
//	gets(str1);
//	x = strlen(str1);
//	Hehe(str1,x);
//	return 0;
//}
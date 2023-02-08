#include<stdio.h>
//test
void func1()
{
  char* lp = NULL;
  *lp = 'a';
}

void func()
{
  int aa = 10;
  int bb = 20;
  int cc= aa+bb;
  printf("cc=%d\n",cc);
//  func1();
}

int main()
{
int a=10;
int b=20;
int c = a+b;
char buf[1024] = "abcdef";
printf("c=%d\n",c);
func();
  return 0;
}

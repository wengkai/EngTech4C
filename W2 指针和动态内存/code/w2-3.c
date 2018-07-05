#include <stdio.h>

int a = 0;

void f()
{
	static int b=0;
	int c = 0;
	printf("&a=%p\n", &a);
	printf("&b=%p\n", &b);
	printf("&c=%p\n", &c);
}

int main()
{
	f();
}
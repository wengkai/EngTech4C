#include <stdio.h>

int *f()
{
	int b = 0xcafebabe;
	int *p1 = &b;
	return p1;
}

void g()
{
	int b = 0xdeadbeef;
}

int main()
{
	int *p = f();
	printf("%X\n", *p);
	g();
	printf("%X\n", *p);
}
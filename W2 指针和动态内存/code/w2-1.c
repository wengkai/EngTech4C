#include <stdio.h>
#include <stdlib.h>

int c = 0;

int *f(int a, int *p)
{
	int b = 0;
	int *p1 = &b;
	int *p2 = &a;
	int *p3 = &c;
	int *p4 = (int*)malloc(sizeof(int));
	int *p5 = p;
	return p5;
}

int main()
{
	int k =0;
	f(5, &k);
}
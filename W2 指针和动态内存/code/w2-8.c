#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int * restrict p;
	int * restrict q;
	p = malloc(4);
	*p = 1;
	q = p;
	*q = 3;
	printf("x:%d\n", *p);
}
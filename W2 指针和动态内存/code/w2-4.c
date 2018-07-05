#include <stdio.h>
#include <stdlib.h>

int *f(int *p)
{
	*p = *p + *p;
	return p;
}

int main()
{
	int *p = (int*)malloc(sizeof(int));
	*p = 10;
	printf("%d\n", *f(f(f(p))));
	free(p);
}
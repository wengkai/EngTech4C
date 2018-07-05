#include <stdio.h>

typedef struct {
	int x;
	int y;
} point;

void f(int a[], point pt)
{
	printf("In f()\n");
	printf("sizeof(a) =%2lu,  &a=%p\n", sizeof(a), a);
	printf("sizeof(pt)=%2lu, &pt=%p\n", sizeof(pt), &pt);
}

int main()
{
	int a[] = {1,2,3,4,5};
	point pt = {6,7};
	printf("sizeof(a) =%2lu,  &a=%p\n", sizeof(a), a);
	printf("sizeof(pt)=%2lu, &pt=%p\n", sizeof(pt), &pt);
	f(a, pt);
}
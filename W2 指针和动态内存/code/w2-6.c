#include <stdio.h>

typedef struct {
	int x;
	int y;
} point;

point g()
{
	point pt = {6,7};
	printf("in g():&pt=%p\n", &pt);
	return pt;
}

// int[] f() // 这里会编译错误
// {
// 	int a[] = {1,2,3,4,5};
// 	printf("in f():&a= %p\n", a);
// 	return a;
// }

int main()
{
	point pt = g();
	printf("in main():&pt=%p\n", &pt);
}




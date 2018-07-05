#include <stdio.h>

typedef struct {
	int x;
	int y;
} point;

const point *f(const point* p)
{
	//	do something to *p
	return p;
}

point *g(point* p)
{
	//	do something to *p
	return p;
}

int main()
{
	point pt = {1,2};
	pt = *f(&pt);	//	fine as right-value
	// f(&pt)->x = 6;	//	error
	g(&pt)->x = 6;	//	fine as left-value
}




#include <stdio.h>

inline int dd(int i)
{
	return i+i;
}

int main()
{
	printf("%d\n", dd(32));
}
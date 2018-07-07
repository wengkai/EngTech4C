#include <stdio.h>

int main()
{
	unsigned int x = 0xcafebabe;
	unsigned int mask = 1ul<<31;
	while ( mask ) {
		if ( x & mask ) {
			printf("1");
		} else {
			printf("0");
		}
		mask >>= 1;
	}
	printf("\n");
}
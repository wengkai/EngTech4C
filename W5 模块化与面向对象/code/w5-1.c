#include <stdio.h>
#include <stdlib.h>

typedef struct _List {
	int value;
	struct _List *next;
} List;

List *head = NULL;
List *tail = NULL;

int main()
{
	int x;
	scanf("%d", &x);
	while ( x!= -1 ) {
		List *p = (List*)malloc(sizeof(List));
		p->value = x;
		p->next = NULL;
		if ( tail ) {
			tail->next = p;
		} else {
			head = p;
		}
		tail = p;
		scanf("%d", &x);
	}
	for ( List *p = head; p; p=p->next ) {
		if ( p->value %2 == 0 ) {
			p->value /= 2;
		}
	}
	for ( List *p = head; p; p=p->next ) {
		printf("%d ", p->value);
	}
	printf("\n");
	for ( List *p = head; p; ) {
		List *q = p->next;
		free(p);
		p = q;
	}
}
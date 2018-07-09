#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

int main()
{
	int x;
	scanf("%d", &x);
	while ( x!= -1 ) {
		Node *p = (Node*)malloc(sizeof(Node));
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
	for ( Node *p = head; p; p=p->next ) {
		if ( p->value %2 == 0 ) {
			p->value /= 2;
		}
	}
	for ( Node *p = head; p; p=p->next ) {
		printf("%d ", p->value);
	}
	printf("\n");
	for ( Node *p = head; p; ) {
		Node *q = p->next;
		free(p);
		p = q;
	}
}
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
	//	读入数据，构成链表
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
	//	遍历链表，将偶数/2
	for ( Node *p = head; p; p=p->next ) {
		if ( p->value %2 == 0 ) {
			p->value /= 2;
		}
	}
	//	遍历链表输出
	for ( Node *p = head; p; p=p->next ) {
		printf("%d ", p->value);
	}
	printf("\n");
	//	删除链表中的每个结点
	for ( Node *p = head; p; ) {
		Node *q = p->next;
		free(p);
		p = q;
	}
}
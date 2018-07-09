#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

typedef struct {
	Node* head;
	Node* tail;
} List;

void add_tail(List* list, int value);
void read(List* list);
void div2(const List* list);
void prt(const List* list);
void clean(List* list);

int main()
{
	List list = {NULL, NULL};
	//	读入数据，构成链表
	read(&list);
	//	遍历链表，将偶数/2
	div2(&list);
	//	遍历链表输出
	prt(&list);
	//	删除链表中的每个结点
	clean(&list);
}

void add_tail(List* list, int value)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = value;
	p->next = NULL;
	if ( list->tail ) {
		list->tail->next = p;
	} else {
		list->head = p;
	}
	list->tail = p;
}

void read(List* list)
{
	int x;
	scanf("%d", &x);
	while ( x!= -1 ) {
		add_tail(list, x);
		scanf("%d", &x);
	}
}

void div2(const List* list)
{
	for ( Node *p = list->head; p; p=p->next ) {
		if ( p->value %2 == 0 ) {
			p->value /= 2;
		}
	}
}

void prt(const List* list)
{
	for ( Node *p = list->head; p; p=p->next ) {
		printf("%d ", p->value);
	}
	printf("\n");
}

void clean(List* list)
{
	for ( Node *p = list->head; p; ) {
		Node *q = p->next;
		free(p);
		p = q;
	}
	list->head = list->tail = NULL;
}
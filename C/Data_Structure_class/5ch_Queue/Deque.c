#include <stdio.h>
#include "2.h"

int is_empty(DequeType *dq)
{
	if (dq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void init(DequeType *dq)
{
	dq->head = dq->tail = NULL;
}

void error(char *message)
{
	printf("%s\n", message);
}

DlistNode *create_node(DlistNode *llink, element item, DlistNode *rlink)
{
	DlistNode *node = (DlistNode*)malloc(sizeof(DlistNode));
	if (node == NULL)
		error("메모리 할당 오류");
	node->llink = llink;
	node->data = item;
	node->rlink = rlink;
	return node;
}

void add_rear(DequeType *dq, element item)
{
	DlistNode *new_node = create_node(dq->tail, item, NULL);
	if (is_empty(dq))
		dq->head = new_node;
	else
		dq->tail->rlink = new_node;
	dq->tail = new_node;
}

void add_front(DequeType *dq, element item)
{
	DlistNode *new_node = create_node(NULL, item, dq->head);
	
	if (is_empty(dq))
		dq->tail = new_node;
	else
		dq->head->llink = new_node;
	dq->head = new_node;
}

element delete_front(DequeType *dq)
{
	element item=NULL;
	DlistNode *removed_node;

	if (is_empty(dq))
		error("공백 덱에서 삭제");
	else {
		removed_node = dq->head;
		item = removed_node->data;
		dq->head = dq->head->rlink;
		free(removed_node);
		if (dq->head == NULL)
			dq->tail = NULL;
		else
			dq->head->llink = NULL;
	}
	return item;
}

element delete_rear(DequeType *dq)
{
	element item=NULL;
	DlistNode *removed_node;

	if (is_empty(dq))
		error("공백 덱에서의 삭제");
	else {
		removed_node = dq->tail;
		item = removed_node->data;
		dq->tail = dq->tail->llink;
		free(removed_node);

		if (dq->tail == NULL)
			dq->head = NULL;
		else
			dq->tail->rlink = NULL;
	}
	return item;
}


void display(DequeType *dq)
{
	DlistNode *p;
	printf("(");
	for (p = dq->head; p != NULL; p = p->rlink) {
		printf("%d ", p->data);
	}
	printf(")\n");
}
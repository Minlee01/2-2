//#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;
//llink is next, rlink is prev

typedef struct {
	DlistNode *top;
} LinkedStackType;

void init(LinkedStackType *s)
{
	s->top == NULL; //equlity comparison result unused
}

int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}

void push(LinkedStackType* s, element item)
{
	DlistNode* temp = (DlistNode*)malloc(sizeof(DlistNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return;
	}

	else {
		temp->data = item;
		temp->rlink = s->top; //temp ÀÇ rlink is c
		s->top->llink = s->top; //cÀÇ llink is new s->top
		s->top = temp; 
	}
}

element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		DlistNode* temp = s->top;
		int item = temp->data;
		s->top = s->top->rlink;
		DlistNode *top = temp->rlink;
		free(temp);
		return item;
	}
}

element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}


int main()
{
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;
}

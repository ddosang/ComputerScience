#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;
typedef struct StackNode {
	element data;
	struct StackNode *link;
}StackNode;
typedef struct {
	StackNode *top;
}LinkedStackType;

void initA(StackType *s) {
	s->top = -1;
}
int is_emptyA(StackType *s) {
	return (s->top == -1);
}
int is_fullA(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
void pushA(StackType *s, element e) {
	if (is_fullA(s)) {
		printf("스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = e;
}
void popA(StackType *s) {
	if (is_emptyA(s)) {
		printf("\"stack empty\" ");
	}
	else printf("%c ", s->stack[(s->top)--]);
}
void peekA(StackType *s) {
	if (is_emptyA(s)) {
		printf("\"stack empty\" ");
	}
	else {
		printf("%c ", s->stack[s->top]);
	}
}

void initL (LinkedStackType *s) {
	s->top = NULL;
}
int is_emptyL(LinkedStackType *s) {
	return (s->top == NULL);
}
void pushL(LinkedStackType *s, element e) {
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	if (temp == NULL) {
		printf("메모리 할당에러\n");
		return;
	}
	else {
		temp->data = e;
		temp->link = s->top;
		s->top = temp;
	}
}
void popL(LinkedStackType *s) {
	if (is_emptyL(s)) {
		printf("\"stack empty\" ");
	}
	else {
		StackNode *temp = s->top;
		int e = temp->data;
		s->top = s->top->link;
		free(temp);
		printf("%c ", e);
	}
}
void peekL(LinkedStackType *s) {
	if (is_emptyL(s)) {
		printf("\"stack empty\" ");
	}
	else {
		printf("%c ", *(s->top));
	}
}

int main(void) {
	StackType *s = (StackType *)malloc(sizeof(StackType));
	LinkedStackType *ss = (LinkedStackType *)malloc(sizeof(LinkedStackType));

	printf("배열 : ");
	initA(s);
	pushA(s, '1'); 
	popA(s);
	pushA(s, '2');
	popA(s);
	pushA(s, '3');
	popA(s);
	printf("\n");
	
	printf("연결리스트 : ");
	initL(ss);
	pushL(ss, '1'); 
	popL(ss); 
	pushL(ss, '2');
	popL(ss); 
	pushL(ss, '3'); 
	popL(ss);
	printf("\n");
}


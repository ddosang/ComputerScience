#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

/* 1) 최대 크기가 MAX_STACK_SIZE(예 : 100)인 배열을 이용하여 스택을 구현한다. 즉, 배열 스택에 삽입하는 연산
pushA(), 삭제하여 출력하는 연산 popA(), 스택 top의 원소를 출력하는 연산 peekA()을 C 언어로 구현한다.
2) 단순 연결리스트를 이용하여 스택을 구현한다. 즉, 연결 스택에 삽입하는 연산 pushL(), 삭제하여 출력하는 연산
popL(), 스택 top의 원소를 출력하는 연산 peekL()을 C 언어로 구현한다.
3) Main 함수에서 아래의 예 1과 예 2의 push(), pop(), peek() 연산을 각각 차례대로 수행하여 그 결과가 맞는지 출력
하여 확인한다 */

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

void initL(LinkedStackType *s) {
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
	pushA(s, 'A');
	peekA(s);
	pushA(s, 'B');
	peekA(s);
	pushA(s, 'C');
	peekA(s);
	popA(s);
	popA(s);
	pushA(s, 'D');
	peekA(s);
	pushA(s, 'E');
	peekA(s);
	popA(s);
	popA(s);
	popA(s);
	popA(s);
	printf("\n");
	
	printf("연결리스트 : ");
	initL(ss);
	pushL(ss, 'A');
	peekL(ss);
	pushL(ss, 'B');
	peekL(ss);
	pushL(ss, 'C');
	peekL(ss);
	popL(ss);
	popL(ss);
	pushL(ss, 'D');
	peekL(ss);
	pushL(ss, 'E');
	peekL(ss);
	popL(ss);
	popL(ss);
	popL(ss);
	popL(ss);
	printf("\n");
}


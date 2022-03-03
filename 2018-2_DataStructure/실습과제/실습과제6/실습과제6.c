#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

/* 1) 최대 크기가 MAX_QUEUE_SIZE(= 10)인 배열을 이용하여 환형큐(circular queue)를 구현한다. 즉, 환형 큐에 삽입
하는 연산 enqueue(), 제거하여 출력하는 연산 dequeue(), 큐에서 다음에 제거할 원소를 출력하는 연산 peek()을
구현하여 테스트한다.
2) Main 함수에서 아래의 예 1과 예 2의 enqueue(), dequeue(), peek() 연산을 차례대로 수행하여 그 결과가 맞는지
출력하여 확인한다. */

typedef int element;

typedef struct QueueType {
	element queue[MAX_QUEUE_SIZE];
	int front;
	int rear;
}QueueType;

void init(QueueType *q) {
	q->front = 0;
	q->rear = 0;
}
int is_empty(QueueType *q) {
	return (q->front == q->rear);
}
int is_full(QueueType *q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType *q, element item) {
	if (is_full(q)) {
		printf("\"queue overflow\" ");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
}
void dequeue(QueueType *q) {
	if (is_empty(q)) {
		printf("\"queue empty\" ");
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		printf("%c ", q->queue[q->front]);
	}
}
void peek(QueueType *q) {
	if (is_empty(q)) {
		printf("\"queue empty\" ");
	}
	else {
		printf("%c ", q->queue[(q->front + 1) % MAX_QUEUE_SIZE]);
	}
}

int main(void) {
	QueueType *q = (QueueType *)malloc(sizeof(QueueType));

	init(q);
	enqueue(q, 'A');
	peek(q);
	enqueue(q, 'B');
	peek(q);
	enqueue(q, 'C');
	peek(q);
	dequeue(q);
	dequeue(q);
	enqueue(q, 'D');
	peek(q);
	enqueue(q, 'E');
	peek(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	printf("\n");
	

	init(q);
	enqueue(q, 'A');
	dequeue(q);
	enqueue(q, 'B');
	dequeue(q);
	enqueue(q, 'C');
	dequeue(q);
	dequeue(q);
	printf("\n");

	init(q);
	enqueue(q, 'A');
	enqueue(q, 'B');
	enqueue(q, 'C');
	enqueue(q, 'D');
	enqueue(q, 'E');
	enqueue(q, 'F');
	enqueue(q, 'G');
	enqueue(q, 'H');
	enqueue(q, 'I');
	dequeue(q);
	peek(q);
	enqueue(q, 'J');
	enqueue(q, 'K');
	printf("\n");
}

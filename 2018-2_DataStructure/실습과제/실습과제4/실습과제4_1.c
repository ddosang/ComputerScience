#include <stdio.h>
#include <stdlib.h>

/* n개의 정수 데이터가 임의의 순서로 주어질 때, 이를 단순 연결리스트 뒷쪽에 차례로 삽입한 후 다시 이 리스트를 처음 노드
부터 다시 방문하여 모든 노드의 데이터를 차례로 출력한다.
□ 또한 주어지는 키(key)값이 있는 노드를 순차탐색에 의해 찾아 연결리스트에서 제거한 후 다시 이를 처음 노드부터 다시 방
문하여 각 노드의 데이터를 차례로 출력한다. (키가 없는 경우는 “키가 없음”도 출력함) */

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed) {
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

void visit(ListNode *head) {
	ListNode *p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

ListNode *search(ListNode *head, int x) {
	ListNode *p, *q;
	p = head;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		q = p;
		p = p->link;
	}
	return p;
}
ListNode *search1(ListNode *head, int x) {
	ListNode *p, *q;
	p = head; q = NULL;
	while (p != NULL) {
		if (p->data == x) {
			return q;
		}
		q = p;
		p = p->link;
	}
	return q;
}


int main(void) {
	int n, key1, key2, key3, j;
	ListNode *p[100], **h = NULL, *p1 = NULL;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		p[i] = (ListNode *)malloc(sizeof(ListNode));
		
		scanf_s("%d", &(p[i]->data));

		p[i]->link = NULL;

		if (i == 0)
			h = &p[0];

		if (i > 0)
			p[i - 1]->link = p[i];
	}

	scanf_s("%d", &key1);
	scanf_s("%d", &key2);
	scanf_s("%d", &key3);

	printf("n = %d\n", n);
	printf("Original data = ");
	visit(p[0]);
	printf("\n\n");


	printf("Key = %d\n", key1);
	remove_node(h, search1(p[0], key1), search(p[0], key1));

	printf("Data = ");
	visit(p[0]);
	printf("\n\n");


	printf("Key = %d\n", key2);
	remove_node(h, search1(p[0], key2), search(p[0], key2));

	printf("Data = ");
	visit(p[0]);
	printf("\n\n");


	printf("Key = %d\n", key3);
	remove_node(h, search1(p[0], key3), search(p[0], key3));

	printf("Data = ");
	visit(p[0]);
	printf("\n\n");
}

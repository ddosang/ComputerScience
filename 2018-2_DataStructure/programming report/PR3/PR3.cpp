#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES 100

//���ÿ� ���� ����ü, �Լ���
typedef int element;
typedef struct StackType {
	int top;
	int stack[MAX_VERTICES]; //���� - �迭�� ����
}StackType;
void init(StackType *s) {
	s->top = -1;
}
int is_empty(StackType *s) {
	return (s->top == -1);
}
int is_full(StackType *s) {
	return (s->top == MAX_VERTICES - 1);
}
void push(StackType *s, element item) {
	if (s->top >= MAX_VERTICES || is_full(s)) {
		printf("push ����\n");
		return;
	}
	s->stack[++(s->top)] = item;
}
element pop(StackType *s) {
	if (is_empty(s)) {
		printf("pop ���� - ���� ����\n");
	}
	else return s->stack[(s->top)--];
}


//�׷����� ���� ����ü�� �Լ���
typedef struct GraphNode {
	int vertex;
	struct GraphNode *link;
}GraphNode;
typedef struct GraphType {
	int n;
	GraphNode *adj_list[MAX_VERTICES]; //�׷��� - ���� ����Ʈ�� �̿���
}GraphType;

void init_graph(GraphType *g) {
	int v;
	g->n = 0;
	for (v = 0; v<MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}//�׷��� �ʱ�ȭ
void insert_vertex(GraphType *g, int v) {
	if (g->n >= MAX_VERTICES) {
		printf("�׷��� ���� ���� �ʰ�\n");
		return;
	}

	g->adj_list[g->n] = (GraphNode*)malloc(sizeof(GraphNode));
	g->adj_list[g->n]->vertex = v;
	g->adj_list[g->n]->link = NULL;

	g->n++;
}//vertex ����
void insert_edge(GraphType *g, int va, int vb) {
	GraphNode *node, *node1;
	if (va >= g->n || vb >= g->n) {
		printf("�׷��� ���� ��ȣ ����\n");
		return;
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node1 = (GraphNode*)malloc(sizeof(GraphNode));
	node1->vertex = vb;
	node1->link = NULL;

	node = g->adj_list[va];
	while (node->link != NULL) {
		node = node->link;
	}
	node->link = node1;
}//edge ����
void top_sort(GraphType *g) {
	int i, er[MAX_VERTICES];
	StackType s, s1, err;
	GraphNode *node, *node1;

	int *in_degree = (int*)malloc((g->n) * sizeof(int));
	int *in_degree1 = (int*)malloc((g->n) * sizeof(int));

	for (i = 0; i < g->n; i++) {
		in_degree[i] = 0;
		er[i] = g->adj_list[i]->vertex;
		//���������� �Ұ����� ��츦 Ž���ϱ� ���� �迭�� vertex�� ä��.
	}

	for (i = 0; i < g->n; i++) {
		GraphNode *node = g->adj_list[i];
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}//��������Ʈ�� ����� ��� ����ŭ in_degree �ϳ��� �ø�
	 //n���϶� n���� ����ǹǷ�
	for (i = 0; i < g->n; i++)
		in_degree[i] -= 1; //�ϳ��� ������ �Ѵ�.

	init(&s); init(&err); init(&s1); //���� �ʱ�ȭ

	for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) {
			push(&s, i);
			push(&s1, i); 
		}
	}// ���� �ΰ��� in_degree�� 0�� vertex�� �ִ´�.

	memcpy(in_degree1, in_degree, g->n * sizeof(int)); // in_degree1�� in_degree ����.

	while (!is_empty(&s1)) {
		int a = pop(&s1);
		push(&err, a);

		node = g->adj_list[a];

		while (node != NULL) {
			int u = node->vertex;
			in_degree1[u]--;
			if (in_degree1[u] == 0)
				push(&s1, u);
			node = node->link;
		}
	} //���������� �Ұ����� ��츦 Ž���ϱ� ���� ����.
	  //���������� �ϱ� ���� ������ ������
	  //err ������ ���� ����� s1 ���ÿ��� pop�� ������ �־���.

	while (!is_empty(&err)) {
		int e = pop(&err);
		for (i = 0; i < g->n; i++) {
			if (er[i] == e) {
				er[i] = -1;
				break;
			}
		}
	}//err ���ÿ��� pop�� ���� ������ index�� er���� -1�� ä���
	 //���� ���� ���� er�� -1�� ä���.

	for (i = 0; i < g->n; i++) {
		if (er[i] != -1) {
			printf("�Ұ��� 'impossible'\n");
			return;
		}
	}//���� er�迭���� -1�� �ƴ� ���� �ִٸ�, ���� ���ÿ��� ������ ���� ���� �ִٴ� �ǹ��̴�.
	 //���� �������� �Ұ���.


	while (!is_empty(&s)) {
		int w = pop(&s);

		printf("%d ", w);
		node = g->adj_list[w];

		while (node != NULL) {
			int u = node->vertex;
			in_degree[u]--;
			if (in_degree[u] == 0)
				push(&s, u);
			node = node->link;
		}
	} //���������� �����Ѵ�.

	printf("\n");
	free(in_degree);
	return;
}//�������� �Լ�


int main() {
	//1771076 ���̹����� ������
	GraphType *g = (GraphType *)malloc(sizeof(GraphType));
	int n, m, a, b, i = 0;


	FILE *fp = fopen("dag1.txt", "r");

	init_graph(g);

	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++)
		insert_vertex(g, i);

	fscanf(fp, "%d", &m);

	while (!feof(fp)) {
		for (i = 0; i < m; i++) {
			fscanf(fp, "%d", &a);
			fscanf(fp, "%d", &b);

			insert_edge(g, a, b);
		}
	}
	fclose(fp);

	printf("���� ���� ��� = ");
	top_sort(g);
}
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
}//vertex ���� v�� ������ vertex ����
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
}//edge ���� - ����׷����̹Ƿ� ���ʸ� �̾��ش�.

void top_sort(GraphType *g) {
	int i, er[MAX_VERTICES];
	StackType s, test, err;
	GraphNode *node, *node1;

	int *in_degree = (int*)malloc((g->n) * sizeof(int));
	int *in_degree1 = (int*)malloc((g->n) * sizeof(int));

	for (i = 0; i < g->n; i++) {
		in_degree[i] = 0;
		er[i] = g->adj_list[i]->vertex;
		//���������� �Ұ����� ��츦 Ž���ϱ� ���� � �迭�� vertex�� ä��.
	}

	for (i = 0; i < g->n; i++) {
		GraphNode *node = g->adj_list[i];
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}//��������Ʈ�� ����

	 //������ ȭ��ǥ�� ���� n-1���϶� ���������� n���� ����ǹǷ�
	for (i = 0; i < g->n; i++)
		in_degree[i] -= 1; //�ϳ��� ������ �Ѵ�.

	init(&s); init(&err); init(&test); //���� �ʱ�ȭ

	for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) {
			push(&s, i);
			push(&test, i); 
		}
	}// ���ÿ� in_degree�� 0�� vertex�� �ִ´�.

	memcpy(in_degree1, in_degree, g->n * sizeof(int)); // in_degree1�� in_degree ����.

	while (!is_empty(&test)) {
		int a = pop(&test); // test ���ÿ��� pop�� ����
		push(&err, a); //err ���ÿ� ����

		node = g->adj_list[a]; //���ÿ��� ������ a index�� ���� �׷����� �迭�� ����

		while (node != NULL) {
			int u = node->vertex;
			in_degree1[u]--; // ���ÿ��� a�� �����Ǿ����Ƿ� a�� ����� ������ in_degree�� �ϳ��� ����
			if (in_degree1[u] == 0)
				push(&test, u); //�� ���������� 0�� �� ���Ҹ� ���ÿ� ����
			node = node->link;
		}
	} //���������� �Ұ����� ��츦 Ž���ϱ� ���� ����.
	  //���������� �ϱ� ���� ������ ������ ���ÿ��� pop��(��������) ���Ҹ� ������� �ʰ�
	  //err ������ ���� ����� test ���ÿ��� pop�� ������ �־���.

	while (!is_empty(&err)) {
		int e = pop(&err);
		for (i = 0; i < g->n; i++) {
			if (er[i] == e) {
				er[i] = -1;
				break;
			}
		}
	}//err ���ÿ��� pop�� ���� index�� �ϴ� �迭 er���� -1�� ä���.
	 //��, er[��µ� ����] = -1 

	for (i = 0; i < g->n; i++) {
		if (er[i] != -1) {
			printf("�Ұ��� 'impossible'\n");
			return;
		}
	}//���� er�迭���� -1�� �ƴ� ���� �ִٸ�, ��µ��� ���� ���� �ִٴ� �ǹ�
	 //���� �������� �Ұ���.

	printf("���� ���� ��� = ");
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
	int n, m, a, b, i = 0; //n = vertex ����, m = edge ����

	printf("1. �Է� ���� : dag1.txt\n ");
	FILE *fp = fopen("dag1.txt", "r");

	init_graph(g);

	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++)
		insert_vertex(g, i); // �׷����� vertex n�� ����

	fscanf(fp, "%d", &m);

	while (!feof(fp)) {
		for (i = 0; i < m; i++) {
			fscanf(fp, "%d", &a);
			fscanf(fp, "%d", &b);

			insert_edge(g, a, b);
		}//edge ����
	}
	fclose(fp);

	top_sort(g);
	printf("\n");
	free(g);


	printf("2. �Է� ���� : dag2.txt\n ");
	g = (GraphType *)malloc(sizeof(GraphType));
	fp = fopen("dag2.txt", "r");

	init_graph(g);

	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++)
		insert_vertex(g, i); // �׷����� vertex n�� ����

	fscanf(fp, "%d", &m);

	while (!feof(fp)) {
		for (i = 0; i < m; i++) {
			fscanf(fp, "%d", &a);
			fscanf(fp, "%d", &b);

			insert_edge(g, a, b);
		}//edge ����
	}
	fclose(fp);

	top_sort(g);
	printf("\n");
	free(g);


	printf("3. �Է� ���� : dag3.txt\n ");
	g = (GraphType *)malloc(sizeof(GraphType));
	fp = fopen("dag3.txt", "r");

	init_graph(g);

	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++)
		insert_vertex(g, i); // �׷����� vertex n�� ����

	fscanf(fp, "%d", &m);

	while (!feof(fp)) {
		for (i = 0; i < m; i++) {
			fscanf(fp, "%d", &a);
			fscanf(fp, "%d", &b);

			insert_edge(g, a, b);
		}//edge ����
	}
	fclose(fp);

	top_sort(g);
	printf("\n");
	free(g);


	printf("4. �Է� ���� : dag4.txt\n ");
	g = (GraphType *)malloc(sizeof(GraphType));
	fp = fopen("dag4.txt", "r");

	init_graph(g);

	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++)
		insert_vertex(g, i); // �׷����� vertex n�� ����

	fscanf(fp, "%d", &m);

	while (!feof(fp)) {
		for (i = 0; i < m; i++) {
			fscanf(fp, "%d", &a);
			fscanf(fp, "%d", &b);

			insert_edge(g, a, b);
		}//edge ����
	}
	fclose(fp);

	top_sort(g);
	printf("\n");
	free(g);


	printf("5. �Է� ���� : dag5.txt\n ");
	g = (GraphType *)malloc(sizeof(GraphType));
	fp = fopen("dag5.txt", "r");

	init_graph(g);

	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++)
		insert_vertex(g, i); // �׷����� vertex n�� ����

	fscanf(fp, "%d", &m);

	while (!feof(fp)) {
		for (i = 0; i < m; i++) {
			fscanf(fp, "%d", &a);
			fscanf(fp, "%d", &b);

			insert_edge(g, a, b);
		}//edge ����
	}
	fclose(fp);

	top_sort(g);
	printf("\n");
	free(g);
}
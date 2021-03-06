#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define _CRT_NO_SECURE_WARNINGS

bool visited[MAX_VERTICES];

typedef struct GraphNode {
	int vertex;
	struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

void init_graph(GraphType *g) {
	int v;
	g->n = 0;
	for (v = 0; v<MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_nvertex(GraphType *g, int n) {
	if (g->n > MAX_VERTICES) {
		printf("\n그래프 : 정점 개수 초과");
		return;
	}
	g->n = n;

	for (int i = 0; i < n; i++) {
		g->adj_list[i] = (GraphNode*)malloc(sizeof(GraphNode));
		g->adj_list[i]->vertex = i;
		g->adj_list[i]->link = NULL;
	}
}

void insert_edge(GraphType *g, int a, int b) {
	GraphNode *node, *node1, *node2;
	if (a >= g->n || b >= g->n) {
		printf("\n그래프 : 정점번호 오류");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));

	node1 = (GraphNode *)malloc(sizeof(GraphNode));
	node1->vertex = b;
	node1->link = NULL;

	node = g->adj_list[a];
	while (node->link != NULL) {
		node = node->link;
	}
	node->link = node1;

	node2 = (GraphNode*)malloc(sizeof(GraphNode));
	node2->vertex = a;
	node2->link = NULL;
	node = g->adj_list[b];
	while (node->link != NULL) {
		node = node->link;
	}
	node->link = node2;
}

void dfs_list(GraphType *g, int v) {
	GraphNode *w;
	visited[v] = true;
	printf("%d ", v);

	for (w = g->adj_list[v]; w; w = w->link) {
		if (!visited[w->vertex]) 
			dfs_list(g, w->vertex);
	}
}

void dfsAll(GraphType *g) {
	int l = 1;
	for (int i = 0; i < g->n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < g->n; i++) {
		if (!visited[i]) {
			printf("연결성분 %d : ", l++);
			dfs_list(g, i);
			printf("\n");
		}
	}
}


int main() {
	GraphType *g = (GraphType *)malloc(sizeof(GraphType));
	int a, b, n, m, i = 0; //n : 정점의 개수 m: 에지의 개수


	//첫번째 파일 graph1.txt
	printf("1. 입력파일 : graph1.txt\n");
	FILE *fp1 = fopen("graph1.txt", "r");

	init_graph(g);

	fscanf(fp1, "%d", &n);
	fscanf(fp1, "%d", &m);

	insert_nvertex(g, n);

	while (!feof(fp1)) {
		fscanf(fp1, "%d", &a);
		fscanf(fp1, "%d", &b);

		insert_edge(g, a, b);
	}
	fclose(fp1);


	
	dfsAll(g);
	printf("\n");
	



	//두번째 파일 graph2.txt
	printf("2. 입력파일 : graph2.txt\n");
	FILE *fp2 = fopen("graph2.txt", "r");

	init_graph(g);

	fscanf(fp2, "%d", &n);
	fscanf(fp2, "%d", &m);

	insert_nvertex(g, n);

	while (!feof(fp2)) {
		fscanf(fp2, "%d", &a);
		fscanf(fp2, "%d", &b);

		insert_edge(g, a, b);
	}
	fclose(fp2);


	dfsAll(g);
	printf("\n");
	



	//세번째 파일 graph3.txt
	printf("3. 입력파일 : graph3.txt\n");
	FILE *fp3 = fopen("graph3.txt", "r");

	init_graph(g);

	fscanf(fp3, "%d", &n);
	fscanf(fp3, "%d", &m);

	insert_nvertex(g, n);

	while (!feof(fp3)) {
		fscanf(fp3, "%d", &a);
		fscanf(fp3, "%d", &b);

		insert_edge(g, a, b);
	}

	fclose(fp3);


	dfsAll(g);
	printf("\n");
	
	

}

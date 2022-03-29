#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define _CRT_NO_SECURE_WARNINGS

//그래프의 인접성분 구하기

bool visited[MAX_VERTICES];

typedef struct GraphType {
	int n;
	int **adj_mat;
} GraphType;

GraphType *NewGraph(int n) {
	if (n > MAX_VERTICES) {
		printf("행렬 생성 범위 오류\n");
	}
	else {
		int i = 0;
		GraphType *g = (GraphType*)malloc(sizeof(GraphType));
		g->n = n;
		g->adj_mat = (int **)malloc(sizeof(int*)*n);
		for (i = 0; i < n; i++) {
			g->adj_mat[i] = (int*)malloc(sizeof(int)*n);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g->adj_mat[i][j] = 0;

		return g;
	}
}



void insert_edge(GraphType *g, int a, int b) {
	g->adj_mat[a][b] = 1;
	g->adj_mat[b][a] = 1;
}

void dfs_mat(GraphType *g, int v) {
	int w;
	visited[v] = true;
	printf("%d ", v);
	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w]) {
			dfs_mat(g, w);
		}
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
			dfs_mat(g, i);
			printf("\n");
		}
	}
}

int main() {
	int a, b, n, m, i = 0; //n : 정점의 개수 m: 에지의 개수

   	//첫번째 파일 graph1.txt
	printf("1. 입력 파일 : graph1.txt\n");
	FILE *fp1 = fopen("graph1.txt", "r");

	fscanf(fp1, "%d", &n);
	fscanf(fp1, "%d", &m);
	GraphType *g = NewGraph(n);

	while (!feof(fp1)) {
		fscanf(fp1, "%d", &a);
		fscanf(fp1, "%d", &b);

		insert_edge(g, a, b);
	}
	fclose(fp1);

	dfsAll(g);
	printf("\n");

	//두번째 파일 graph2.txt
	printf("2. 입력 파일 : graph2.txt\n");
	FILE *fp2 = fopen("graph2.txt", "r");

	fscanf(fp2, "%d", &n);
	fscanf(fp2, "%d", &m);
	g = NewGraph(n);

	while (!feof(fp2)) {
		fscanf(fp2, "%d", &a);
		fscanf(fp2, "%d", &b);

		insert_edge(g, a, b);
	}
	fclose(fp2);

	dfsAll(g);
	printf("\n");


	//세번째 파일 graph3.txt
	printf("3. 입력 파일 : graph3.txt\n");
	FILE *fp3 = fopen("graph3.txt", "r");

	fscanf(fp3, "%d", &n);
	fscanf(fp3, "%d", &m);
	g = NewGraph(n);

	while (!feof(fp3)) {
		fscanf(fp3, "%d", &a);
		fscanf(fp3, "%d", &b);

		insert_edge(g, a, b);
	}

	fclose(fp3);


	dfsAll(g);
	printf("\n");

}

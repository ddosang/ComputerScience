#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES 100

//스택에 대한 구조체, 함수들
typedef int element;
typedef struct StackType {
	int top;
	int stack[MAX_VERTICES]; //스택 - 배열로 구현
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
		printf("push 실패\n");
		return;
	}
	s->stack[++(s->top)] = item;
}
element pop(StackType *s) {
	if (is_empty(s)) {
		printf("pop 실패 - 원소 없음\n");
	}
	else return s->stack[(s->top)--];
}


//그래프에 대한 구조체와 함수들
typedef struct GraphNode {
	int vertex;
	struct GraphNode *link;
}GraphNode;
typedef struct GraphType {
	int n;
	GraphNode *adj_list[MAX_VERTICES]; //그래프 - 인접 리스트를 이용함
}GraphType;

void init_graph(GraphType *g) {
	int v;
	g->n = 0;
	for (v = 0; v<MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}//그래프 초기화
void insert_vertex(GraphType *g, int v) {
	if (g->n >= MAX_VERTICES) {
		printf("그래프 정점 개수 초과\n");
		return;
	}

	g->adj_list[g->n] = (GraphNode*)malloc(sizeof(GraphNode));
	g->adj_list[g->n]->vertex = v;
	g->adj_list[g->n]->link = NULL;

	g->n++;
}//vertex 삽입
void insert_edge(GraphType *g, int va, int vb) {
	GraphNode *node, *node1;
	if (va >= g->n || vb >= g->n) {
		printf("그래프 정점 번호 오류\n");
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
}//edge 삽입
void top_sort(GraphType *g) {
	int i, er[MAX_VERTICES];
	StackType s, s1, err;
	GraphNode *node, *node1;

	int *in_degree = (int*)malloc((g->n) * sizeof(int));
	int *in_degree1 = (int*)malloc((g->n) * sizeof(int));

	for (i = 0; i < g->n; i++) {
		in_degree[i] = 0;
		er[i] = g->adj_list[i]->vertex;
		//위상정렬이 불가능한 경우를 탐지하기 위해 배열에 vertex를 채움.
	}

	for (i = 0; i < g->n; i++) {
		GraphNode *node = g->adj_list[i];
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}//인접리스트에 연결된 노드 수만큼 in_degree 하나씩 올림
	 //n개일때 n으로 저장되므로
	for (i = 0; i < g->n; i++)
		in_degree[i] -= 1; //하나씩 내려야 한다.

	init(&s); init(&err); init(&s1); //스택 초기화

	for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) {
			push(&s, i);
			push(&s1, i); 
		}
	}// 스택 두개에 in_degree가 0인 vertex를 넣는다.

	memcpy(in_degree1, in_degree, g->n * sizeof(int)); // in_degree1에 in_degree 복사.

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
	} //위상정렬이 불가능한 경우를 탐지하기 위해 수행.
	  //위상정렬을 하기 위한 과정과 같으나
	  //err 스택을 새로 만들어 s1 스택에서 pop한 값들을 넣었다.

	while (!is_empty(&err)) {
		int e = pop(&err);
		for (i = 0; i < g->n; i++) {
			if (er[i] == e) {
				er[i] = -1;
				break;
			}
		}
	}//err 스택에서 pop한 값을 가지는 index의 er값을 -1로 채운다
	 //들어갔다 나온 값의 er을 -1로 채운다.

	for (i = 0; i < g->n; i++) {
		if (er[i] != -1) {
			printf("불가능 'impossible'\n");
			return;
		}
	}//만약 er배열에서 -1이 아닌 값이 있다면, 아직 스택에서 나오지 못한 값이 있다는 의미이다.
	 //따라서 위상정렬 불가능.


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
	} //위상정렬을 수행한다.

	printf("\n");
	free(in_degree);
	return;
}//위상정렬 함수


int main() {
	//1771076 사이버보안 임은지
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

	printf("위상 정렬 결과 = ");
	top_sort(g);
}
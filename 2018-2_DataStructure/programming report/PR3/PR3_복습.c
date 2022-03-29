//
//  main.c
//  C
//
//  Created by 임은지 on 2022/03/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_VERTICIES 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int top;
    int stack[MAX_VERTICIES];
} StackType;

void init(StackType *s) {
    s->top = 0;
}

int is_empty(StackType *s) {
    return (s->top == 0);
}

void push(StackType *s, int item) {
    s->stack[++s->top] = item;
}

int pop(StackType *s) {
    return s->stack[s->top--];
}


typedef struct {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct {
    int n;
    GraphNode *adj_list[MAX_VERTICIES];
} GraphType;

typedef struct {
    int n;
    int **adj_mat;
} GraphType_m;


GraphType *init_graph(GraphType *g, int n) {
    if (n > MAX_VERTICIES) {
        printf("행렬 범위 오류");
        return NULL;
    }
    g->n = n;
    for(int i = 0; i < g->n; i++) {
        g->adj_list[i] = (GraphNode*)malloc(sizeof(GraphNode));
        g->adj_list[i]->vertex = i;
        g->adj_list[i]->link = NULL;
    }
    return g;
}

GraphType_m *NewGraph_m(int n) {
    if (n > MAX_VERTICIES) {
        printf("행렬 범위 오류");
        return NULL;
    }
    GraphType_m *g = (GraphType_m *)malloc(sizeof(GraphType_m));
    g->n = n;
    g->adj_mat = (int **)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++) {
        g->adj_mat[i] = (int*)malloc(sizeof(int)*n);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            g->adj_mat[i][j] = 0;
        }
    }
    return g;
}

void insert_list(GraphNode **phead, GraphNode *p, int item) {
    GraphNode *new_node = (GraphNode *)malloc(sizeof(GraphNode));
    new_node->vertex = item;
    new_node->link = NULL;
    
    if (*phead == NULL) {
        *phead = new_node;
    } else if (p == NULL) {
        new_node->link = (*phead)->link;
        *phead = new_node;
    } else {
        new_node->link = p->link;
        p->link = new_node;
    }
}

// 유향 그래프이므로!
void insert_edge(GraphType* g, int u, int v) {
    GraphNode *node_u = g->adj_list[u];
    
    while(node_u->link != NULL) {
        node_u = node_u->link;
    }
    insert_list(&g->adj_list[u], node_u, v);
}

void insert_edge_m(GraphType_m *g, int u, int v) {
    g->adj_mat[u][v] = 1;
}

void top_sort(GraphType *g) {
    StackType s;
    init(&s);
    
    // 초기화
    int* in_degree = (int*)malloc(sizeof(int) * g->n);
    
    for(int i = 0; i < g->n; i++) {
        in_degree[i] = -1;
    }
    
    // 진입차수 계산
    for(int i = 0; i < g->n; i++) {
        GraphNode *node = g->adj_list[i];
        while(node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }
    
    for(int i = 0; i < g->n; i++) {
        if(in_degree[i] == 0) {
            push(&s, i);
        }
    }
    
    while(!is_empty(&s)) {
        int u = pop(&s);
        printf("%d ", u);
        
        GraphNode* node = g->adj_list[u]->link;
        while(node != NULL) {
            in_degree[node->vertex]--;
            if (in_degree[node->vertex] == 0)
                push(&s, node->vertex);
            node = node->link;
        }
    }
    free(in_degree);
}

int main(int argc, const char * argv[]) {
    FILE *fp = fopen("graph4.txt", "r");
    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    int n, m, u, v;
    
    
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);
    
    init_graph(g, n);
    
    for (int i = 0; i < m; i++) {
        fscanf(fp, "%d", &u);
        fscanf(fp, "%d", &v);
        
        insert_edge(g, u, v);
    }
    
    
    fclose(fp);
    
    printf("위상 정렬\n");
    top_sort(g);
}

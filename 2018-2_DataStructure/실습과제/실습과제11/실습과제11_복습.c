#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_VERTICIES 100
#define TRUE 1
#define FALSE 0

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


int visited[MAX_VERTICIES];


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

void insert_edge(GraphType* g, int u, int v) {
    GraphNode *node_u = g->adj_list[u];
    GraphNode *node_v = g->adj_list[v];
    
    while(node_u->link != NULL) {
        node_u = node_u->link;
    }
    insert_list(&g->adj_list[u], node_u, v);
    
    while(node_v->link != NULL) {
        node_v = node_v->link;
    }
    insert_list(&g->adj_list[v], node_v, u);
}

void insert_edge_m(GraphType_m *g, int u, int v) {
    g->adj_mat[u][v] = 1;
    g->adj_mat[v][u] = 1;
}


void dfs_mat(GraphType_m *g, int v) {
    visited[v] = TRUE;
    printf("%d ", v);
    for(int i = 0; i < g->n; i++) {
        if (g->adj_mat[v][i] && !visited[i]) {
            dfs_mat(g, i);
        }
    }
}

void dfs_list(GraphType *g, int v) {
    visited[v] = TRUE;
    printf("%d ", v);
    for(GraphNode *w = g->adj_list[v]; w; w=w->link) {
        if (!visited[w->vertex]) {
            dfs_list(g, w->vertex);
        }
    }
}

int connected_subgraph(GraphType *g) {
    int count = 0;
    for(int i = 0; i < g->n; i++) {
        if(!visited[i]) {
            printf("연결성분 %d : ", count + 1);
            count++;
            dfs_list(g, i);
            printf("\n");
        }
    }
    return count;
}

int connected_subgraph_m(GraphType *g) {
    int count = 0;
    for(int i = 0; i < g->n; i++) {
        if(!visited[i]) {
            printf("연결성분 %d : ", count + 1);
            count++;
            dfs_mat(g, i);
            printf("\n");
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    FILE *fp;
    GraphType *g;
    int n, m;
    int u, v;
    char titles[3][11] = {
        {'g', 'r', 'a', 'p', 'h', '1', '.', 't', 'x', 't', '\0'},
        {'g', 'r', 'a', 'p', 'h', '2', '.', 't', 'x', 't', '\0'},
        {'g', 'r', 'a', 'p', 'h', '3', '.', 't', 'x', 't', '\0'},
    };
    
    
    printf("인접행렬로 구현\n");
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < MAX_VERTICIES; j++) {
            visited[j] = FALSE;
        }
        
        printf("%d. 입력 파일 : graph%d.txt\n", i + 1, i + 1);
        fp = fopen(titles[i], "r");

        fscanf(fp, "%d", &n);
        fscanf(fp, "%d", &m);
        g = NewGraph_m(n);

        while (!feof(fp)) {
            fscanf(fp, "%d", &u);
            fscanf(fp, "%d", &v);

            insert_edge_m(g, u, v);
        }
        fclose(fp);

        connected_subgraph_m(g);
        printf("\n");
    }
    
    printf("\n\n");
    
    
    printf("인접리스트로 구현\n");
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < MAX_VERTICIES; j++) {
            visited[j] = FALSE;
        }
        
        printf("%d. 입력 파일 : graph%d.txt\n", i + 1, i + 1);
        fp = fopen(titles[i], "r");

        fscanf(fp, "%d", &n);
        fscanf(fp, "%d", &m);
        init_graph(g, n);

        while (!feof(fp)) {
            fscanf(fp, "%d", &u);
            fscanf(fp, "%d", &v);

            insert_edge(g, u, v);
        }
        fclose(fp);

        connected_subgraph(g);
        printf("\n");
    }
}

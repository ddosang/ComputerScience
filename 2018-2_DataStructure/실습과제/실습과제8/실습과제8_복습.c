//
//  main.c
//  C
//
//  Created by qara_macbookpro on 2022/03/03.
//

#include <stdio.h>
#include <stdlib.h>
#define max(a, b)((a > b)? a : b)

typedef int element;

typedef struct {
    element data;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct {
    TreeNode *root;
} TreeType;

void init(TreeType *t) {
    t->root = NULL;
}

void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    return;
}

void insert_node(TreeNode **root, element key) {
    TreeNode *p, *t, *new;
    p = NULL; t = *root;
    
    while(t != NULL) {
        if (t->data == key) return; // 같은게 이미 있으면 삽입 할 수 없음.
        p = t;
        t = (t->data > key)? t->left : t->right;
    }
    
    new = (TreeNode*)malloc(sizeof(TreeNode));
    if (new == NULL) return;
    new->data = key; new->left = NULL; new->right = NULL;
    
    if (p != NULL) {
        if (p->data > key) p->left = new;
        else p->right = new;
    } else {
        *root = new;
    }
    return;
}

int get_node_count(TreeNode *root) {
    if (root) {
        int left_count = get_node_count(root->left);
        int right_count = get_node_count(root->right);
        return left_count + right_count + 1;
    }
    return 0;
}

int get_height(TreeNode *root) {
    if (root) {
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        return max(left_height, right_height) + 1;
    }
    return 0;
}


int main() {
    TreeType *t = (TreeType *)malloc(sizeof(TreeType));
    init(t);
    
    int n;
    for(int i = 0; i<7; i++) {
        scanf("%d", &n);
        insert_node(&(t->root), n);
        printf("노드 개수 = %d\n", get_node_count(t->root));
        printf("높이 = %d\n", get_height(t->root));
        printf("중순위 운행 = ");
        inorder(t->root);
        printf("\n\n");
    }
    
    return 0;
}

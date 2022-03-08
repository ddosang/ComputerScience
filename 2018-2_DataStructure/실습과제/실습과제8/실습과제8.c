#include <stdio.h>
#include <stdlib.h>

/* 1) 노드의 삽입에 의해서 이진탐색트리를 구성한다(연결리스트를 사용).
2) 새로운 노드를 삽입할 때마다 구성된 이진탐색트리의 노드 개수와 높이를 각각 구하고 중순위 운행을 하
여 그 결과를 확인한다. */

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
}TreeNode;



int max(int n1, int n2) {
	if (n1 <= n2) return n2;
	else return n1;
}

void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

int get_node_count(TreeNode *node) {
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

int get_height(TreeNode *node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

void insert_node(TreeNode **root, int key) {
	TreeNode *p, *t;
	TreeNode *n;
	t = *root;
	p = NULL;

	while (t != NULL) {
		if (key == t->key) return;
		p = t;
		if (key < t->key)
			t = t->left;
		else
			t = t->right;
	}

	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	n->key = key;
	n->left = n->right = NULL;

	if (p != NULL) {
		if (key < p->key)
			p->left = n;
		else
			p->right = n;
	}
	else *root = n;
}

int main(void) {
	TreeNode *root = NULL;

	int a;

	for (int i = 0; i < 6; i++) {
		scanf("%d", &a);

		insert_node(&root, a);

		printf("노드 개수 = %d\n", get_node_count(root));
		printf("높이 = %d\n", get_height(root) - 1);
		printf("중순위 운행 = ");
		inorder(root);
		printf("\n\n");

	}


}

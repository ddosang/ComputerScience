#include <stdio.h>

/* 1) Main() 함수에서 아래와 같은 간단한 수식표현트리를 연결리스트로 만들고,
2) 이 수식표현트리에 대해 각각 중순위(inorder), 후순위(postorder), 전순위(preorder) 운행을 재귀적으로
수행하여 중순위(infix) 표기 및 전순위(prefix) 표기와 후순위(postfix) 표기 결과가 맞는지 확인한다. */

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;
//트리노드 struct

TreeNode n1 = { 'a', NULL, NULL };
TreeNode n2 = { 'b', NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 'c', NULL, NULL };
TreeNode n5 = { 'd', NULL, NULL };
TreeNode n6 = { '/', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode *exp = &n7;
//수식표현 트리 구성

void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}
void postorder(TreeNode *root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
}
void preorder(TreeNode *root) {
	if (root) {
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int evaluate(TreeNode *root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		switch (root->data) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
		return 0;
	}
}

int main(void) {
	printf("중순위 운행 = ");
	inorder(exp);
	printf("\n");
	printf("후순위 운행 = ");
	postorder(exp);
	printf("\n");
	printf("전순위 운행 = ");
	preorder(exp);
	printf("\n");
}

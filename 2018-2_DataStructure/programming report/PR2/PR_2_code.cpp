#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 81 //MAX_STACK_SIZE�� 81�� ����

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;
typedef struct StackNode {
	element data;
	struct StackNode *link;
}StackNode;
typedef struct {
	StackNode *top;
}LinkedStackType;
//stack, ���Ḯ��Ʈ ����ü ����

void initA(StackType *s) {
	s->top = -1;
}
int is_emptyA(StackType *s) {
	return (s->top == -1);
}
int is_fullA(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
void pushA(StackType *s, element item) {
	if (is_fullA(s)) {
		printf("���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
element popA(StackType *s) {
	if (is_emptyA(s)) {
		printf("\"stack empty\" ");
		return -1;
	}
	else return (s->stack[(s->top)--]);
}
element peekA(StackType *s) {
	if (is_emptyA(s)) {
		printf("\"stack empty\" ");
		return -1;
	}
	else return (s->stack[s->top]);
}
/* �迭�� �̿��� stack ���� �Լ�
   �迭�� ����ϹǷ� �Լ��� �� �ڿ� array�� A�� �ٿ��� */

void initL(LinkedStackType *s) {
	s->top = NULL;
}
int is_emptyL(LinkedStackType *s) {
	return (s->top == NULL);
}
void pushL(LinkedStackType *s, element item) {
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	if (temp == NULL) {
		printf("�޸� �Ҵ翡��\n");
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}
element popL(LinkedStackType *s) {
	if (is_emptyL(s)) {
		printf("\"stack empty\" ");
		return -1;
	}
	else {
		StackNode *temp = s->top;
		int item = temp->data;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}
element peekL(LinkedStackType *s) {
	if (is_emptyL(s)) {
		printf("\"stack empty\" ");
		return -1;
	}
	else {
		return s->top->data;
	}
}
/* ���Ḯ��Ʈ ���� �Լ� 
   ���Ḯ��Ʈ�� ����ϹǷ� �Լ��� �� �ڿ� LinkedList�� L�� �ٿ��� */

int eval(char exp[], int *a) 
//���� ǥ�� ���� ��� �Լ� 
/* �Լ��� ���ڷ� ���޵Ǵ� ���ڹ迭�� strlen ���� ��Ȯ�ϰ� ������ �ʾ�
   �� ���̰��� �޾Ƽ� �̿��ϱ� ���� ���� a�� �߰��� �޾Ҵ�. */
{ 
	int op1, op2, value, i = 0;
	char ch;
	StackType s; //�迭�� �̿��� ���� �̿�

	initA(&s);
	for (i = 0; i < *a; i++) { 
		ch = exp[i]; // �Լ��� ���ڷ� ���޹��� ���ڸ� ch�� ����
		if (ch != '+' && ch != '-' && ch != '/'&&ch != '*' && ch != '%' && ch != '^') {
			value = ch - '0';
			pushA(&s, value);
		} // �ǿ������� ��� ���ڰ����� '0'�� �ش��ϴ� ���� �� ���ڷ� ��ȯ�� ���ÿ� �ִ´�.
		else {
			op2 = popA(&s);
			op1 = popA(&s);
			switch (ch) {
			case '+': pushA(&s, op1 + op2); break;
			case '-': pushA(&s, op1 - op2); break;
			case '*': pushA(&s, op1 * op2); break;
			case '/': pushA(&s, op1 / op2); break;
			case '%': pushA(&s, op1 % op2); break;
			case '^': pushA(&s, pow(op1 , op2)); break;
			} // �������� ��� ���ÿ��� 2���� �ǿ����ڸ� pop�ؼ� �ش��ϴ� ������ ������ �� �ٽ� ���ÿ� �ִ´�.
		}
	}
	return popA(&s); 
	// ���� ������ �ݺ��ϸ� �������� ���ÿ� ���� ���� ��� ��� ���̹Ƿ� �� ���� ��ȯ�Ѵ�.
}

int prec(char ch) {
// �������� ISP�� �����ϴ� �Լ��̴�.
// ^�� ������ ��� �������� ISP�� ICP�� ���� ������ ^�� ���� �Ͽ���.
	switch (ch) {

	case '^': return 2;
	case'*': case '/': case '%': return 1;
	case '+': case'-': return 0;
	}
	return -1;
}


char* infix_to_postfix(char exp[], int *a) {
	// ���� ǥ����� ���� ǥ������� �ٲٴ� �Լ�
	int len = strlen(exp), compare;
	char ch;
	char* result = (char*)malloc(MAX_STACK_SIZE * sizeof(char));
	int value;
	element e;
	int j = 0, k = 0, m = 0;
	StackType *s = (StackType*)malloc(sizeof(StackType)); //�ǿ����� ����
	LinkedStackType *l = (LinkedStackType*)malloc(sizeof(LinkedStackType)); // ������ ����

	initA(s);
	initL(l); // ���� �ʱ�ȭ
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		if (ch >= '0' && ch <= '9') {
		// �ǿ������� ���
			value = ch - '0';
			pushA(s, value);
		// ���ڷ� ��ȯ�Ͽ� �ǿ����� ���ÿ� �ְ�,
			j++;
		// j�� 1 �ø���. - j�� ���ݱ��� ��� ���ڰ� ���Դ����� �˱� ���� �����̴�.
		}
		else { //�������� ���
			switch (ch) {
			case '^':
			case '*': case '/': case '%': case '+': case '-':
				compare = prec(ch); 
				if (ch == '^') {
					compare = 3;
				} // compare�� ���� ������ �������� ICP�� �����ϰ�,
				 // ���ϱ� �� ^������ ICP�� �ϳ� ���̰� ����.
				while (!is_emptyL(l) && (compare <= prec(peekL(l)))) {
					// ���ÿ� �ִ� �������� ISP�� ���ο� �������� ICP���� ũ�ų� ������
					for (int i = k; i < j; i++) {
						result[m] = s->stack[i] + '0';
						m++; k++;
						//m : ��� �迭�� ��� ���Ұ� �������� �˱� ���� ���.
						//k : ���ÿ� ���ִ� ���ڸ� ����ϱ� ���� ����Ѵ�.
						//��� �迭�� ���ڰ��� �ְ�, m���� k���� �ø���.
					}
					e = popL(l);
					result[m] = e;
					m++;
					// ���ÿ� �ִ� �����ڸ� pop�ؼ� ��� �迭�� �ִ´�.
				}
				pushL(l, ch);
				break;

			case '(': pushL(l, ch); break;
			case ')':
				while (true) {
					e = peekL(l);
					if (e == '(') {
						popL(l);
						break;
					}
					else {
						for (int i = k; i < j; i++) {
							result[m] = s->stack[i] + '0';
							m++; k++;
						}
						e = popL(l);
						result[m] = e;
						m++;
					}
				} break;
				// ( �� ���� ������ �ְ�, )�� ������ �� pop�ϸ� �ǹǷ� icp���� ������ �ʾҴ�.
				// ����, )�� ������ ( �� ������ �������� ���ڵ��� ��� �迭�� �ְ�,
				// �����ڵ鵵 pop�Ͽ� ��� �迭�� ���� �� (�� ������ pop�ϰ� �ݺ����� ���� ���Դ�.
			default: break;
			}
		}
	}
	for (int i = k; i < j; i++) {
		result[m] = s->stack[i] + '0';
		m++; k++;
	} 
	while (is_emptyL(l) != true) {
		e = popL(l);
		result[m] = e;
		m++;
	} //���� ������, �ǿ����ڵ鵵 �迭�� �ִ´�.
	*a = m; // m ���� *a�� ������ main�Լ� ������ a���� �ٲ�� �ߴ�.
	return result;
}


int main(void) {
	// Major : Cyber Security
	// ID : 1771076
	// Name : Eunji Lim
	FILE *fp;
	char exp[20][MAX_STACK_SIZE];
	int i = 0,j = 0, n, a = 0, result;
	char *str; char *str2;
	

	fp = fopen("infix.txt", "r");
	fscanf(fp, "%d", &n);
	while (!feof(fp)) {
		fgets(exp[i], MAX_STACK_SIZE, fp);
		i++;
	}
	fclose(fp);
	//������ ���� ù��° ���ڴ� ���ڷ� �о�� n�� �����ϰ�
	//�� ������ ���پ� �о� �迭�� �����ߴ�.

	for (int i = 1; i <= n; i++) {
		printf("infix notation = "); 
		for (int j = 0; j < strlen(exp[i]); j++) {
			while (exp[i][j] != '\n') {
				printf("%c", exp[i][j]);
				break;
			}
		}
		printf("\n");

		str = infix_to_postfix(exp[i], &a); // ���� ǥ������� �ٲپ� str�� ����.
		str2 = (char*)malloc(a); // aĭ��ŭ �Ҵ��� �迭�� ����.
		printf("postfix notation = ");
		for (int j = 0; j < a; j++) {
			printf("%c", str[j]);
			str2[j] = str[j];
		} // str2�� ���� �� ���
		printf(";\n");
		result = eval(str2, &a); 
		printf("value = %d\n\n", result);
		// ���� ǥ������� ������� ������ ����Ͽ� ���
	}	
}


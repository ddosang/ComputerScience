#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 81 //MAX_STACK_SIZE를 81로 정의

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
//stack, 연결리스트 구조체 정의

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
		printf("스택 포화 에러\n");
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
/* 배열을 이용한 stack 관련 함수
   배열을 사용하므로 함수명 맨 뒤에 array의 A를 붙여줌 */

void initL(LinkedStackType *s) {
	s->top = NULL;
}
int is_emptyL(LinkedStackType *s) {
	return (s->top == NULL);
}
void pushL(LinkedStackType *s, element item) {
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	if (temp == NULL) {
		printf("메모리 할당에러\n");
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
/* 연결리스트 관련 함수 
   연결리스트를 사용하므로 함수명 맨 뒤에 LinkedList의 L를 붙여줌 */

int eval(char exp[], int *a) 
//후위 표기 수식 계산 함수 
/* 함수의 인자로 전달되는 문자배열의 strlen 값이 정확하게 나오지 않아
   그 길이값을 받아서 이용하기 위에 인자 a를 추가로 받았다. */
{ 
	int op1, op2, value, i = 0;
	char ch;
	StackType s; //배열을 이용한 스택 이용

	initA(&s);
	for (i = 0; i < *a; i++) { 
		ch = exp[i]; // 함수의 인자로 전달받은 문자를 ch에 대입
		if (ch != '+' && ch != '-' && ch != '/'&&ch != '*' && ch != '%' && ch != '^') {
			value = ch - '0';
			pushA(&s, value);
		} // 피연산자의 경우 문자값에서 '0'에 해당하는 값을 빼 숫자로 변환해 스택에 넣는다.
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
			} // 연산자의 경우 스택에서 2개의 피연산자를 pop해서 해당하는 연산을 수행한 뒤 다시 스택에 넣는다.
		}
	}
	return popA(&s); 
	// 위의 연산을 반복하면 마지막에 스택에 남는 값이 계산 결과 값이므로 그 값을 반환한다.
}

int prec(char ch) {
// 연산자의 ISP를 설정하는 함수이다.
// ^를 제외한 모든 연산자의 ISP와 ICP가 같기 때문에 ^도 같게 하였다.
	switch (ch) {

	case '^': return 2;
	case'*': case '/': case '%': return 1;
	case '+': case'-': return 0;
	}
	return -1;
}


char* infix_to_postfix(char exp[], int *a) {
	// 중위 표기법을 후위 표기법으로 바꾸는 함수
	int len = strlen(exp), compare;
	char ch;
	char* result = (char*)malloc(MAX_STACK_SIZE * sizeof(char));
	int value;
	element e;
	int j = 0, k = 0, m = 0;
	StackType *s = (StackType*)malloc(sizeof(StackType)); //피연산자 스택
	LinkedStackType *l = (LinkedStackType*)malloc(sizeof(LinkedStackType)); // 연산자 스택

	initA(s);
	initL(l); // 스택 초기화
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		if (ch >= '0' && ch <= '9') {
		// 피연산자의 경우
			value = ch - '0';
			pushA(s, value);
		// 숫자로 변환하여 피연산자 스택에 넣고,
			j++;
		// j를 1 늘린다. - j는 지금까지 몇개의 숫자가 들어왔는지를 알기 위한 변수이다.
		}
		else { //연산자의 경우
			switch (ch) {
			case '^':
			case '*': case '/': case '%': case '+': case '-':
				compare = prec(ch); 
				if (ch == '^') {
					compare = 3;
				} // compare에 새로 들어오는 연산자의 ICP를 대입하고,
				 // 비교하기 전 ^연산의 ICP를 하나 높이고 시작.
				while (!is_emptyL(l) && (compare <= prec(peekL(l)))) {
					// 스택에 있는 연산자의 ISP가 새로운 연산자의 ICP보다 크거나 같으면
					for (int i = k; i < j; i++) {
						result[m] = s->stack[i] + '0';
						m++; k++;
						//m : 결과 배열에 몇개의 원소가 들어갔는지를 알기 위해 사용.
						//k : 스택에 들어가있는 문자를 출력하기 위해 사용한다.
						//결과 배열에 문자값을 넣고, m값과 k값을 올린다.
					}
					e = popL(l);
					result[m] = e;
					m++;
					// 스택에 있는 연산자를 pop해서 결과 배열에 넣는다.
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
				// ( 의 경우는 무조건 넣고, )이 들어왔을 때 pop하면 되므로 icp값은 따지지 않았다.
				// 따라서, )이 들어오면 ( 을 만나기 전까지의 숫자들을 결과 배열에 넣고,
				// 연산자들도 pop하여 결과 배열에 넣은 뒤 (을 만나면 pop하고 반복문을 빠져 나왔다.
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
	} //남은 연산자, 피연산자들도 배열에 넣는다.
	*a = m; // m 값을 *a에 대입해 main함수 에서의 a값도 바뀌도록 했다.
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
	//파일을 열어 첫번째 숫자는 숫자로 읽어와 n에 저장하고
	//그 뒷줄은 한줄씩 읽어 배열에 저장했다.

	for (int i = 1; i <= n; i++) {
		printf("infix notation = "); 
		for (int j = 0; j < strlen(exp[i]); j++) {
			while (exp[i][j] != '\n') {
				printf("%c", exp[i][j]);
				break;
			}
		}
		printf("\n");

		str = infix_to_postfix(exp[i], &a); // 후위 표기법으로 바꾸어 str에 저장.
		str2 = (char*)malloc(a); // a칸만큼 할당해 배열을 만듬.
		printf("postfix notation = ");
		for (int j = 0; j < a; j++) {
			printf("%c", str[j]);
			str2[j] = str[j];
		} // str2에 저장 후 출력
		printf(";\n");
		result = eval(str2, &a); 
		printf("value = %d\n\n", result);
		// 후위 표기법으로 만들어진 수식을 계산하여 출력
	}	
}


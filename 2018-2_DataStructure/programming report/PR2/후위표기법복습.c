//
//  main.c
//  ComputerScience
//
//  Created by 임또상 on 2021/12/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 30

typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

typedef struct {
    element data;
    struct StackNode *link;
} StackNode;
typedef struct {
    StackNode *top;
} StackTypeL;

void init(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

void push(StackType *s, element item) {
    s->stack[++(s->top)] = item;
}

element pop(StackType *s) {
    return s->stack[(s->top)--];
}

element peek(StackType *s) {
    return s->stack[s->top];
}

int is_emptyL(StackTypeL *s) {
    return (s->top == NULL);
}

void pushL (StackTypeL *s, element item) {
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    if (temp==NULL) {
        printf("메모리 할당 에러\n");
        return;
    }
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

element popL (StackTypeL *s) {
    int item;
    if (is_emptyL(s)) {
        printf("스택이 비어 있음");
        exit(1);
    }
    StackNode *temp = s->top;
    item = (s->top)->data;
    s->top = (s->top)->link;
    free(temp);
    return item;
}

element peekL(StackTypeL *s) {
    return (s->top)->data;
}

int icp_of(char ch) {
    switch(ch) {
        case '(':
            return 20;
        case '^':
            return 15;
        case '*': case '/': case '%':
            return 13;
        case '+': case '-':
            return 12;
    }
    return -1;
}

int isp_of(char ch) {
    switch(ch) {
        case '(':
            return 0;
        case '^':
            return 14;
        case '*': case '/': case '%':
            return 13;
        case '+': case '-':
            return 12;
    }
    return -1;
}

char* infix_to_postfix(char exp[]) {
    int len = strlen(exp);
    int index = 0;
    char ch, temp;
    StackTypeL s = (StackTypeL) {.top = NULL};
    char* postfix = (char*)malloc(30 * sizeof(char));

    for(int i = 0; i < len ; i++) {
        ch = exp[i];
        switch(ch) {
            case '+': case '-': case '*': case '/': case '%':
                while(!is_emptyL(&s) && (isp_of(peekL(&s)) >= icp_of(ch))) {
                    postfix[index++] = popL(&s);
                }
                pushL(&s, ch);
                break;
            case '(':
                pushL(&s, ch);
                break;
            case ')':
                temp = popL(&s);
                while(temp != '(') {
                    postfix[index++] = temp;
                    temp = popL(&s);
                }
                break;
            default:
                postfix[index++] = ch;
                break;
        }
    }
    while(!is_emptyL(&s)) {
        postfix[index++] = popL(&s);
    }
    return postfix;
}

int calculate_postfix(char exp[]) {
    char ch;
    int item, first, second;
    StackType operand;
    init(&operand);

    for(int i = 0; i < strlen(exp); i++) {
        ch = exp[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') {
            second = pop(&operand);
            first = pop(&operand);
            switch(ch) {
                case '+': push(&operand, first + second); break;
                case '-': push(&operand, first - second); break;
                case '*': push(&operand, first * second); break;
                case '/': push(&operand, first / second); break;
                case '%': push(&operand, first % second); break;
                case '^': push(&operand, pow(first, second)); break;
            }
            
        } else {
            item = ch - '0';
            push(&operand, item);
        }
    }
    return pop(&operand);
}


int main() {
    printf("infix notation = %s\n", "(2+3)*4+9");
    printf("postfix notation = %s\n", infix_to_postfix("(2+3)*4+9"));
    printf("value = %d\n", calculate_postfix(infix_to_postfix("(2+3)*4+9")));

    return 0;
}

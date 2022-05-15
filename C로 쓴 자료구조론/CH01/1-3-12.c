#include <stdio.h>
#define MAX_COUNT 100

int N;
int check[MAX_COUNT] = { 0 };


void powerset(int n) {
    if (n == 0) {
        printf("{");
        for (int i = 1; i < N + 1; i++) {
            if (check[i] == 1) {
                printf("%d ", i);
            }
        }
        printf("}\n");
        return;
    }
    
    check[n] = 1;
    powerset(n - 1);
    check[n] = 0;
    powerset(n - 1);
}


int main(void) {
    int n;
    
    printf("집합 원소의 개수 : ");
    scanf("%d", &n);
    N = n;

    printf("멱집합\n");
    
    powerset(n);
    
    return 0;
}

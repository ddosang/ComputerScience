#include <stdio.h>

#define MAX_COUNT 100
#define FALSE 0
#define TRUE 1

int N;
int res[MAX_COUNT] = { 0 };
int check[MAX_COUNT] = { 0 };

void printBool(int n) {
    if (n == 0) {
        printf("false ");
        return;
    }
    else if (n == 1) {
        printf("true ");
        return;
    }
}

// DFS 를 이용해서 풀었다.
void makeTuple(int n) {
    if (n == 0) {
        for (int i = 0; i < N; i++) {
            printBool(res[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < 2; i++) {
        res[n - 1] = i;
        makeTuple(n - 1);
    }
}



int main(void) {

    int n;
    printf("양수를 입력하세요 : ");
    scanf("%d", &n);
    N = n;

    if (n < 1) return -1;

    makeTuple(n);
    printf("\n");


    return 0;
}

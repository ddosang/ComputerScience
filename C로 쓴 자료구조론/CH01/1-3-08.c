#include <stdio.h>
#define MAX_COUNT 30

int f[MAX_COUNT] = { 0, 1 };

// 반복
int fibo(int n) {
    int first = 0;
    int second = 1;
    int res = 0;
    
    if (n == 0) return first;
    if (n == 1) return second;
    
    
    for (int i = 0; i < n - 1; i++) {
        res = first + second;
        first = second;
        second = res;
//        printf("%d %d\n", first, second);
    }
    return res;
}

int recursiveFibo(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    return recursiveFibo(n - 1) + recursiveFibo(n - 2);
}

int recursiveCachingFibo(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    if (f[n] != 0) {
        return f[n];
    }
    
    return recursiveFibo(n - 2) + recursiveFibo(n - 1);
}


int main(void) {
    int n;

    printf("양수 하나를 입력하세요 : ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("양수가 아닙니다...\n");
        return - 1;
    }
    
    printf("반복 fibo(%d) = %d\n", n, fibo(n));
    printf("재귀 fibo(%d) = %d\n", n, recursiveFibo(n));
    printf("재귀 캐싱 fibo(%d) = %d\n", n, recursiveCachingFibo(n));
    
    return 0;
}

#include <stdio.h>

// 반복
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// 재귀
int recursiveFactorial(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    
    return n * recursiveFactorial(n - 1);
}



int main(void) {
    int n;

    printf("양수 하나를 입력하세요 : ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("양수가 아닙니다...\n");
        return - 1;
    }
    
    printf("반복 %d! = %d\n", n, factorial(n));
    printf("재귀 %d! = %d\n", n, recursiveFactorial(n));
    
    return 0;
}

#include <stdio.h>
#define MAX_COUNT 30

int f[MAX_COUNT] = { 0 };

// 반복
int binomialCoefficient(int n, int m) {
    f[0] = 1;
    f[n] = 1;
    
    for(int i = 1; i < n; i++) {
        f[i] = f[i - 1] * (n - i + 1) / i;
    }
    return f[m];
}

int recursiveBinomialCoefficient(int n, int m) {
    if (m == 0) return 1;
    if (m == 1) return n;
    if (m == n) return n;
    
    return recursiveBinomialCoefficient(n, m - 1) * (n - m + 1) / m;
}


int main(void) {
    int n;
    int m;

    printf("nCm : ");
    scanf("%d %d", &n, &m);
    
    if (n < 1) {
        printf("양수가 아닙니다...\n");
        return - 1;
    }
    
    if (m < 0 || m > n) {
        printf("가능한 범위가 아닙니다...\n");
        return - 1;
    }
    
    
    printf("이항계수 %dC%d 반복 %d\n", n, m, binomialCoefficient(n, m));
    printf("이항계수 %dC%d 반복 %d\n", n, m, recursiveBinomialCoefficient(n, m));
    
    return 0;
}

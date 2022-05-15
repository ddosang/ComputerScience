#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
    int n;
    int sum = 0;
    
    printf("양수 하나를 입력하세요 : ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("양수가 아닙니다...\n");
        return - 1;
    }
    
    for(int i = 1; i < (int)sqrt(n) + 1; i++) {
        if (n % i == 0) {
            sum += i;
            sum += n / i;
        }
    }
    
    printf("%d 의 모든 제수의 합은 %d 입니다.\n", n, sum);
    if (sum == n) {
        printf("%d 와 모든 제수의 합이 같습니다.\n", n);
    } else {
        printf("%d 와 모든 제수의 합이 다릅니다.\n", n);
    }
    
    return 0;
}

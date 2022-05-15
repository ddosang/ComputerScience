#include <stdio.h>
#define MAX_COUNT 100000


int hanoi(int n) {
    if (n == 1) return 1;
    
    return 2 * hanoi(n - 1) + 1;
}

int main(void) {
    int n;

    printf("하노이의 탑은 몇 층인가요? : ");
    scanf("%d", &n);
    
    printf("%d 층을 옮기려면 %d 번의 작업 필요\n", n, hanoi(n));
    
    return 0;
}

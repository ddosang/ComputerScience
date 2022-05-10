#include <stdio.h>
#define MAX_SIZE 20

int main(void) {
    
    // n에는 최고 차수를 저장.
    // a 에 다항식의 계수를 저장하되, 차수가 작은 것부터 저장한다.
//    int n = 2;
//    int a[MAX_SIZE] = {1, 2, 1, 0}; // x^2 + 2 * x + 1
    int n;
    int a[MAX_SIZE];
    int x;
    
    
    printf("다항식 최고차항의 계수를 입력하세요 (최대 19) : ");
    scanf("%d", &n);
    
    printf("다항식의 계수를 차수가 큰 것부터 순서대로 입력하세요 : ");
    for(int i = n; i >= 0; i--) {
        scanf("%d", &a[i]);
    }
    
    printf("x 값을 입력하세요 : ");
    scanf("%d", &x);
    
    int cal = a[n];
    for (int i = n - 1; i >= 0; i--) {
        cal = cal * x + a[i];
    }
    
    printf("계산 결과 : %d\n", cal);
    
    return 0;
}

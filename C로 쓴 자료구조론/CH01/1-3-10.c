// 효율이 너무 안좋다..

#include <stdio.h>
#define MAX_COUNT 100000


// 반복
int ackermann(int m, int n) {
    int list[MAX_COUNT];
    int esp = 0;
    
    list[esp++] = m;
    list[esp] = n;
    
    while(1) {
        
        if (esp == 0) {
            return list[esp];
        }
        
        // A(0, n) = n + 1
        else if (list[esp - 1] == 0) {
            list[esp - 1] = list[esp] + 1;
            
            esp--;
        }
        
        // A(m, 0) = A(m - 1, 1)
        else if (list[esp] == 0) {
            list[esp - 1]--;
            list[esp] = 1;
        }
        
        else {
            list[esp + 1] = list[esp] - 1;
            list[esp] = list[esp - 1];
            list[esp - 1]--;
            
            esp++;
        }
    }
}


// 재귀
int r_ackermann(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return r_ackermann(m - 1, 1);
    
    return r_ackermann(m-1, r_ackermann(m, n - 1));
}


int main(void) {
    int n;
    int m;

    printf("A(m, n) : ");
    scanf("%d %d", &m, &n);
    
    
    printf("아커만 함수 A(%d, %d) 반복 %d\n", m, n, ackermann(m, n));
    printf("아커만 함수 A(%d, %d) 재귀 %d\n", m, n, r_ackermann(m, n));
    
    
    return 0;
}


// 참고 : https://numgo.tistory.com/8

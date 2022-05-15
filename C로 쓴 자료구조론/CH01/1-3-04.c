#include <stdio.h>

#define MIN -2147483648

int minInThree(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    }
    
    if (y <= x && y <= z) {
        return y;
    }
    
    if (z <= x && z <= y) {
        return z;
    }
    
    return MIN;
}

void printAscending(int x, int y, int z) {
    int m = minInThree(x, y, z);
    if (m == MIN) {
        return;
    }
    
    if (m == x) {
        int second = (y < z) ? y : z;
        int third = (y < z) ? z : y;
        printf("%d %d %d\n", x, second, third);
        return;
    }
    
    if (m == y) {
        int second = (x < z) ? x : z;
        int third = (x < z) ? z : x;
        printf("%d %d %d\n", y, second, third);
        return;
    }
    
    if (m == z) {
        int second = (x < y) ? x : y;
        int third = (x < y) ? y : x;
        printf("%d %d %d\n", z, second, third);
        return;
    }
}


int main(void) {
    int x, y, z;
    
    printf("3 개의 정수를 입력하세요 : ");
    scanf("%d %d %d", &x, &y, &z);
    
    printAscending(x, y, z);
    
    
    return 0;
}

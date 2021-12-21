//
//  main.c
//  ComputerScience
//
//  Created by 임은지 on 2021/12/21.
//

#include <stdio.h>

void poly_add(int p_n, int q_n, int* result_n, int p[10], int q[10], int result[10]) {
    int i = 0;
    int p_index = 0, q_index = 0;
    
    if (p_n > q_n) *result_n = p_n;
    else *result_n = q_n;
    
    while(p_n != -1 && q_n != -1) {
        if (p_n > q_n) {
            result[i] = p[p_index++];
            p_n--;
        } else if (p_n == q_n) {
            result[i] = p[p_index++] + q[q_index++];
            p_n--; q_n--;
        } else {
            result[i] = q[q_index++];
            q_n--;
        }
        i++;
    }
    while(p_n != -1) {
        result[i] = p[p_index++];
        p_n--;
        i++;
    }
    while(q_n != -1) {
        result[i] = q[q_index++];
        q_n--;
        i++;
    }
}

void print_poly(int n, int arr[10]) {
    for(int i = 0; i<=n;i++) {
        printf("%dx^%d", arr[i], n-i);
        if (i != n) {
            printf(" + ");
        }
    }
    printf("\n");
}

int calc_poly(int n, int x, int arr[10]) {
    int result = arr[n];
    int xpower = 1;
    for(int i = n-1; i >= 0; i--) {
        xpower *= x;
        result += arr[i] * xpower;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int p_n, q_n, result_n;
    int p[10], q[10], result[10];
    int x1, x2;
    
    scanf("%d", &p_n);
    for(int i = 0; i <= p_n; i++) {
        scanf("%d", &p[i]);
    }
    scanf("%d", &q_n);
    for(int i = 0; i <= q_n; i++) {
        scanf("%d", &q[i]);
    }
    scanf("%d %d", &x1, &x2);
    
    poly_add(p_n, q_n, &result_n, p, q, result);
    
    printf("p(x) = ");
    print_poly(p_n, p);
    printf("q(x) = ");
    print_poly(q_n, q);
    printf("result(x) = ");
    print_poly(result_n, result);
    
    printf("p(%d) = %d ", x1, calc_poly(p_n, x1, p));
    printf("q(%d) = %d ", x1, calc_poly(q_n, x1, q));
    printf("result(%d) = %d ", x1, calc_poly(result_n, x1, result));
    
    printf("\n");
    printf("p(%d) = %d ", x2, calc_poly(p_n, x2, p));
    printf("q(%d) = %d ", x2, calc_poly(q_n, x2, q));
    printf("result(%d) = %d ", x2, calc_poly(result_n, x2, result));
    
    return 0;
}

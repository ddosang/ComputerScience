//
//  main.c
//  C
//
//  Created by 임은지 on 2022/03/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10000
#define TRUE 1
#define FALSE 0

int* make_arr(int n) {
    int i = 0, m = 1;
    int isPrime = TRUE;
    int* arr = (int*)malloc(sizeof(int) * n);
    
    // i는 배열 인덱스, m은 배열에 들어갈 수 있는지 검사해볼 숫자.
    while (i < n) {
        isPrime = TRUE;
        m++;
        for(int j = 2; j <= sqrt(m); j++) {
            if (m % j == 0) {
                isPrime = FALSE;
                break;
            }
        }
        if (isPrime == TRUE){
            arr[i] = m;
            i++;
        }
    }
    return arr;
}

// 여기서 arr도 선언하려고 했는데 안된다고 컴파일 타임의 상수 머시기 에러가 떠서 
int count;
// 그냥 arr 도 넘겨주는 함수로 바꾸었다...
int binary_search(int *arr, int key, int left, int right) {
    int mid;
    count = 0;
    while (left <= right) {
        count++;
        mid = (left + right) / 2;
        if(key == arr[mid])
            return mid;
        else if(key > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int search_interpolation(int *arr, int key, int left, int right) {
    int mid;
    count = 0;
    while (left <= right) {
        count++;
        mid = (float)(key - arr[left]) / (arr[right] - arr[left]) * (right - left) + left;
        if(key == arr[mid])
            return mid;
        else if(key > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    
    int *arr = make_arr(SIZE);
    int key = 104723;

    printf("Key = %d\n\n", key);

    printf("Binary search\n");
    printf("\tIndex = %d\n", binary_search(arr, key, 0, SIZE - 1));
    printf("\tThe number of comparisons = %d\n\n", count);


    printf("Interpolation search\n");
    printf("\tIndex = %d\n", search_interpolation(arr, key, 0, SIZE - 1));
    printf("\tThe number of comparisons = %d\n\n", count);

    
}

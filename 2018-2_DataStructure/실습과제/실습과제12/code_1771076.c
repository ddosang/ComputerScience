#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 500000
//500000이상도 오류가 나지 않고 돌아가긴 하는데
//프로그램 실행에 너무 오랜 시간이 소요되어 500000으로 하였다.

//이진 탐색과 보간 탐색

int comp;

int* make_input(int n) {
	int i = 0, j = 0, m = 1;
	int isPrime = 0;
	int *list = (int*)malloc(n*sizeof(int));
	while (i < n) {
		isPrime = 0;
		m++;
		for (j = 2; j <= sqrt(m); j++) {
			if (m%j == 0)
				isPrime = 1;
		}
		if (isPrime == 0) {
			list[i] = m;
			i++;
		}
	}

	return list;
}//n개의 소수를 배열에 저장하는 함수

int *list = make_input(MAX);

int search_binary(int key, int low, int high) {
	int middle; comp = 0;
	while (low <= high) {
		comp++;
		middle = (low + high) / 2;
		if (key == list[middle]) return middle;
		else if (key > list[middle]) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
	}
	return -1;
}//이진 탐색 함수

int search_interpolation(int key, int n) {
	comp = 0;
	int low, high, j;
	low = 0;
	high = n - 1;
	while ((list[high] >= key) && (key > list[low])) {
		comp++;
		j = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low;
		if (key > list[j]) {
			low = j + 1;
		}
		else if (key < list[j]) {
			high = j - 1;
		}
		else low = j;
	}
	if (list[low] == key) return low;
	else return -1;
}//보간 탐색 함수

int main() {
	int key = 153120;

	printf("Key = %d\n\n", key);

	printf("Binary search\n");
	printf("\tIndex = %d\n", search_binary(key, 0, MAX - 1));
	printf("\tThe number of comparisons = %d\n\n", comp);


	printf("Interpolation search\n");
	printf("\tIndex = %d\n", search_interpolation(key, MAX));
	printf("\tThe number of comparisons = %d\n\n", comp);

}

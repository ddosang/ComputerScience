#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)= (t))

//퀵정렬, 힙정렬

int count = 0;

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];


	do {
		do {
			low++;
			count++;
		} while (low <= right && list[low] > pivot);
		do {
			high--;
			count++;
		} while (high >= left && list[high] < pivot);
		if (low < high) {
			SWAP(list[low], list[high], temp);
		}
	} while (low < high);

	SWAP(list[left], list[high], temp);
	

	return high;

}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}



int main() {
	int n, i = 0;
	FILE *fp1 = fopen("input1.txt", "r"), *fp2, *fp3;

	fscanf(fp1, "%d", &n);

	int *exp = (int *)malloc(sizeof(int)*n);

	while (!feof(fp1)) {
		fscanf(fp1, "%d", &exp[i]);
		i++;
	}
	fclose(fp1);


	printf("1. 입력 파일 (\"input1.txt\")\n");
	printf("%d\n", n);
	for (int i = 0; i < 10; i++) {
		printf("%d ", exp[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", exp[i]);
	}printf("\n");

	printf("출력\n");
	quick_sort(exp, 0, n-1);
	printf("정렬 결과 = ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", exp[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", exp[i]);
	}
	printf("\n비교 횟수 = %d회\n", count);


	i = 0;
	fp2 = fopen("input2.txt", "r");

	fscanf(fp2, "%d", &n);

	exp = (int *)malloc(sizeof(int)*n);

	while (!feof(fp2)) {
		fscanf(fp2, "%d", &exp[i]);
		i++;
	}
	fclose(fp2);

	printf("2. 입력 파일 (\"input2.txt\")\n");
	printf("%d\n", n);
	for (int i = 0; i < 10; i++) {
		printf("%d ", exp[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", exp[i]);
	}printf("\n");

	printf("출력\n");
	quick_sort(exp, 0, n-1);
	printf("정렬 결과 = ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", exp[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", exp[i]);
	}
	printf("\n비교 횟수 = %d회\n", count);





	i = 0;
	fp3 = fopen("input3.txt", "r");

	fscanf(fp3, "%d", &n);

	exp = (int *)malloc(sizeof(int)*n);

	while (!feof(fp3)) {
		fscanf(fp3, "%d", &exp[i]);
		i++;
	}
	fclose(fp3);


	printf("3. 입력 파일 (\"input3.txt\")\n");
	printf("%d\n", n);
	for (int i = 0; i < 10; i++) {
		printf("%d ", exp[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", exp[i]);
	}printf("\n");

	printf("출력\n");
	quick_sort(exp, 0, n-1);
	printf("정렬 결과 = ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", exp[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", exp[i]);
	}
	printf("\n비교 횟수 = %d회\n", count);


}





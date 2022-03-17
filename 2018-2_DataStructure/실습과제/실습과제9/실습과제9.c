#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1) 파일로부터 데이터를 입력 받아서 오름차순으로 정렬하는 단순 정렬 알고리즘 두가지(삽입 정렬과 버블 정렬)
를 각각 구현한다.
2) 주어지는 입력 파일은 “input1.txt”, “input2.txt”, “input3.txt”이며 첫 줄에는 정렬할 데이터의 개수, 두번째 줄
부터는 정렬할 데이터들이 빈칸에 의해 나누어져 나열되어 있다. (최대 10,000개)
3) 각 알고리즘 및 파일 별로 정렬을 위해 실행한 비교 횟수와 정렬 결과(앞부분 10개와 뒷부분 10개)를 화면에 출
력한다. */

int compare = 0;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void insertion_sort(int list[], int n) {
	int i, j, key;
	compare = 0;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			compare += 1;
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}

void bubble_sort(int list[], int n) {
	int i, j = 0, flag = true;
	compare = 0;
	while ((j < n - 1) && flag) {
		flag = false;
		for (i = n - 1; i > j; i--) {
			compare += 1;
			if (list[i] < list[i - 1]) {
				flag = true;
				swap(&list[i], &list[i - 1]);
			}
		}
		j++;
	}
}



int main() {

	int n, i = 0;
	FILE *fp1 = fopen("input1.txt", "r"), *fp2, *fp3;

	fscanf(fp1, "%d", &n);

	int *expi = (int *)malloc(sizeof(int)*n);
	int *expb = (int *)malloc(sizeof(int)*n);

	while (!feof(fp1)) {
		fscanf(fp1, "%d", &expi[i]);
		i++;
	}
	fclose(fp1);

	memcpy(expb, expi, n * sizeof(int));

	printf("1. 입력 파일 (\"input1.txt\")\n");
	printf("%d\n", n);
	for (int i = 0; i < 10; i++) {
		printf("%d ", expi[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", expi[i]);
	}printf("\n");

	printf("출력\n");
	insertion_sort(expi, n);
	printf("삽입 정렬 결과 = ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", expi[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", expi[i]);
	}
	printf("\n비교 횟수 = %d\n", compare);


	bubble_sort(expb, n);
	printf("버블 정렬 결과 = ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", expb[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", expb[i]);
	}
	printf("\n비교 횟수 = %d\n\n", compare);

	i = 0;
	fp2 = fopen("input2.txt", "r");
	fscanf(fp2, "%d", &n);

	expi = (int *)malloc(sizeof(int)*n);
	expb = (int *)malloc(sizeof(int)*n);

	while (!feof(fp2)) {
		fscanf(fp2, "%d", &expi[i]);
		i++;
	}
	fclose(fp2);

	memcpy(expb, expi, n * sizeof(int));

	printf("2. 입력 파일 (\"input2.txt\")\n");
	printf("%d\n", n);
	for (int i = 0; i < 10; i++) {
		printf("%d ", expi[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", expi[i]);
	}printf("\n");

	printf("출력\n");
	insertion_sort(expi, n);
	printf("삽입 정렬 결과 = ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", expi[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", expi[i]);
	}
	printf("\n비교 횟수 = %d\n", compare);


	bubble_sort(expb, n);
	printf("버블 정렬 결과 = ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", expb[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", expb[i]);
	}
	printf("\n비교 횟수 = %d\n\n", compare);


	i = 0;
	fp3 = fopen("input3.txt", "r");

	fscanf(fp3, "%d", &n);

	expi = (int *)malloc(sizeof(int)*n);
	expb = (int *)malloc(sizeof(int)*n);

	while (!feof(fp3)) {
		fscanf(fp3, "%d", &expi[i]);
		i++;
	}
	fclose(fp3);

	memcpy(expb, expi, n * sizeof(int));

	printf("3. 입력 파일 (\"input3.txt\")\n");
	printf("%d\n", n);
	for (int i = 0; i < 10; i++) {
		printf("%d ", expi[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", expi[i]);
	}printf("\n");

	printf("출력\n");
	insertion_sort(expi, n);
	printf("삽입 정렬 결과 = ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", expi[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", expi[i]);
	}
	printf("\n비교 횟수 = %d\n", compare);


	bubble_sort(expb, n);
	printf("버블 정렬 결과 = ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", expb[i]);
	}
	printf("... ... ... ");
	for (int i = n - 10; i < n; i++) {
		printf("%d ", expb[i]);
	}
	printf("\n비교 횟수 = %d\n\n", compare);
}

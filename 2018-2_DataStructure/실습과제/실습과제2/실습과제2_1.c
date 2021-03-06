#include <stdio.h>

//주어진 키 값이 있는 인덱스를 순차탐색으로 찾기.
int seq_Search(int list[], int n, int key, int* nn);

int main(void) {
	int list[100];
	int n, i=0, key1, key2;
	int nn = 0;

	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		scanf_s("%d", &list[i]);

	scanf_s("%d", &key1);
	scanf_s("%d", &key2);

	printf("n = %d\n", n);
	printf("Data = ");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

	printf("\n\nKey = %d\n", key1);
	printf("Index = %d\n", seq_Search(list, n, key1, &nn));
	printf("the number of comparisons = %d\n\n", nn);

	printf("Key = %d\n", key2);
	printf("Index = %d\n", seq_Search(list, n, key2, &nn));
	printf("the number of comparisons = %d\n\n", nn);
}

int seq_Search(int list[], int n, int key, int* nn) {
	for (int i = 0; i < n; i++) {
		*nn = i + 1;
		if (list[i] == key)
			return i;
	}
	return -1;
}

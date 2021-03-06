#include <stdio.h>

int seq_Search(int list[], int n, int key, int* nn ,int ii);

int main(void) {
	int list[100];
	int n, i = 0, ii=0, key1, key2;
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
	printf("Index = %d\n", seq_Search(list, n, key1, &nn, ii));
	printf("the number of comparisons = %d\n\n", nn);

	printf("Key = %d\n", key2);
	printf("Index = %d\n", seq_Search(list, n, key2, &nn, ii));
	printf("the number of comparisons = %d\n\n", nn);
}

int seq_Search(int list[], int n, int key, int* nn, int ii) {
	for (int i = ii; i < n; i++) {
		*nn = i + 1;
		if (list[i] == key)
			return i;
		else if (list[i] > key) {
			return -1;
		}
		else
			return seq_Search(list, n, key, nn, ii + 1);
	}
}

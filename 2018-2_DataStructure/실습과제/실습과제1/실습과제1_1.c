#include <stdio.h>

//배열 내 최대 최소를 동시에 찾는 함수
void findMaxMin(int n, int data[], int* max, int* min);

int main(void) {
	int i, n;
	int max, min;
	scanf_s("%d", &n);
	int data[100];
	for (i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("n = %d\n", n);
	printf("data = ");
	for (i = 0; i < n; i++) {
		printf("%d", data[i]);
		if (i < n - 1) {
			printf(", ");
		}
	}

	findMaxMin(n, data, &max, &min);

	printf("\n\n");
	printf("Maximum = %d\n", max);
	printf("Minimum = %d\n", min);
}

void findMaxMin(int n, int data[], int* max, int* min) {
	*max = data[0];
	*min = data[0];
	for (int i = 0; i < n; i++) {
		if (*max < data[i])
			*max = data[i];

		if (*min > data[i])
			*min = data[i];
	}
}


#include <stdio.h>

//Çà·ÄÀÇ °öÀ» ÇÏ´Â ÇÔ¼ö
void SmatrixMultiply(int n, int a[100][100], int b[100][100], int c[100][100]);

int main(void) {

	int n;
	scanf_s("%d", &n);
	int a[100][100], b[100][100], c[100][100];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &a[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &b[i][j]);

	SmatrixMultiply(n, a, b, c);

	printf("\nA = ");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
		printf("    ");
	}
	
	
	printf("\nB = ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", b[i][j]);
		printf("\n");
		printf("    ");
	}
			

	printf("\nC = ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", c[i][j]);
		printf("\n");
		printf("    ");
	}
}

void SmatrixMultiply(int n, int a[100][100], int b[100][100], int c[100][100]) {	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = 0;
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

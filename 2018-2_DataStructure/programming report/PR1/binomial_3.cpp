#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

long long binomial_3(long long n, long long k) {
	int bin[500][500]; //2���� �迭 ����
	for (long long i = 1; i <= n; i++) {
		for (long long j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				bin[i][j] = 1; //nC1�� nCn ���� �ش��ϴ� �κп� bin�� 1 ����.
			}
			else {
				if (i >= 2)
					bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
				// ����� ���� �̿��Ͽ� �迭�� ���װ�� �� ����
			}
		}
	}
	return bin[n][k]; //n�� k���� ����� ���� return
}// ���װ�� ���� ����� ���Ǹ� �̿��Ͽ�, �ݺ����� �̿��� ���ϴ� ���

int main(void) {
	//1771076 ���̹����� ������
	long long n, k, result;
	LARGE_INTEGER start, end, liFrequency;

	scanf("%lld %lld", &n, &k); //n, k �Է¹���

	QueryPerformanceFrequency(&liFrequency);
	QueryPerformanceCounter(&start);
	result = binomial_3(n, k);
	QueryPerformanceCounter(&end);

	printf("2. n = %lld, k = %lld\n", n, k);
	printf("���װ�� = %lld\n", result); //n, k, ���װ�� ���
	printf("�ҿ�ð� = %8.6f��sec\n", ((double)(end.QuadPart - start.QuadPart) / (double)liFrequency.QuadPart) * 1000000);
	//�ι�° ����� ���� ��� ���
}
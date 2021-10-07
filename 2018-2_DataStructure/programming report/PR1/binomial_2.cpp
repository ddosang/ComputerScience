#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

long long binomial_2(long long n, long long k) {
	if (k == 0 || k == n) {
		return 1;
	}
	else {
		return (binomial_2(n - 1, k - 1) + binomial_2(n - 1, k));
	}
}// ���װ�� ���� ����� ���Ǹ� �̿��Ͽ�, ��������� ���ϴ� ���.



int main(void) {
	long long n, k, result;
	LARGE_INTEGER start, end, liFrequency;

	scanf("%lld %lld", &n, &k); //n, k �Է¹���
	
	QueryPerformanceFrequency(&liFrequency);
	QueryPerformanceCounter(&start);
	result = binomial_2(n, k);
	QueryPerformanceCounter(&end);

	printf("2. n = %lld, k = %lld\n", n, k);
	printf("���װ�� = %lld\n", result); //n, k, ���װ�� ���
	printf("�ҿ�ð� = %8.6f��sec\n", ((double)(end.QuadPart - start.QuadPart) / (double)liFrequency.QuadPart) * 1000000);
	//�ι�° ����� ���� ��� ���
}
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

long long factorial(long long n) {
	long long fac = 1;
	if (n == 0) fac = 1;
	for (long long i = 1; i <= n; i++)
		fac *= i;
	return fac;
}//factorial ���� �ݺ��� ����� �̿��Ͽ� ���ϴ� �Լ�

long long binomial_1(long long n, long long k) {
	return factorial(n) / (factorial(n - k) * factorial(k));
}// ���װ�� ���� factorial �Լ��� �̿��Ͽ�, ���Ǹ� �̿��� ���ϴ� ���.
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

	//���α׷� ���� �ð��� ���ϴ� �Լ�, �ð� ���� ����
	QueryPerformanceFrequency(&liFrequency);
	QueryPerformanceCounter(&start);
	//��� ���α׷��� �����Ͽ� gcd �� ���ϴ� �Լ� ȣ��
	result = binomial_1(n, k);
	//�ð� ���� ��
	QueryPerformanceCounter(&end);
	
	printf("1. n = %lld, k = %lld\n", n, k);
	printf("���װ�� = %lld\n", result); //n, k, ���װ�� ���
	printf("�ҿ�ð� = %8.6f��sec\n", ((double)(end.QuadPart - start.QuadPart) / (double)liFrequency.QuadPart) * 1000000);
	//ù��° ����� ���� ��� ���
	
}
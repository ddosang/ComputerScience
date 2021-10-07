#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

long long factorial(long long n) {
	long long fac = 1;
	if (n == 0) fac = 1;
	for (long long i = 1; i <= n; i++)
		fac *= i;
	return fac;
}//factorial 값을 반복적 방법을 이용하여 구하는 함수

long long binomial_1(long long n, long long k) {
	return factorial(n) / (factorial(n - k) * factorial(k));
}// 이항계수 값을 factorial 함수를 이용하여, 정의를 이용해 구하는 방법.
long long binomial_2(long long n, long long k) {
	if (k == 0 || k == n) {
		return 1;
	}
	else {
		return (binomial_2(n - 1, k - 1) + binomial_2(n - 1, k));
	}
}// 이항계수 값을 재귀적 정의를 이용하여, 재귀적으로 구하는 방법.

int main(void) {
	long long n, k, result;
	LARGE_INTEGER start, end, liFrequency;

	scanf("%lld %lld", &n, &k); //n, k 입력받음

	//프로그램 수행 시간을 구하는 함수, 시간 측정 시작
	QueryPerformanceFrequency(&liFrequency);
	QueryPerformanceCounter(&start);
	//재귀 프로그램을 실행하여 gcd 값 구하는 함수 호출
	result = binomial_1(n, k);
	//시간 측정 끝
	QueryPerformanceCounter(&end);
	
	printf("1. n = %lld, k = %lld\n", n, k);
	printf("이항계수 = %lld\n", result); //n, k, 이항계수 출력
	printf("소요시간 = %8.6fμsec\n", ((double)(end.QuadPart - start.QuadPart) / (double)liFrequency.QuadPart) * 1000000);
	//첫번째 방법에 대한 결과 출력
	
}
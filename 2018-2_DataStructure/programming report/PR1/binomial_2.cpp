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
}// 이항계수 값을 재귀적 정의를 이용하여, 재귀적으로 구하는 방법.



int main(void) {
	long long n, k, result;
	LARGE_INTEGER start, end, liFrequency;

	scanf("%lld %lld", &n, &k); //n, k 입력받음
	
	QueryPerformanceFrequency(&liFrequency);
	QueryPerformanceCounter(&start);
	result = binomial_2(n, k);
	QueryPerformanceCounter(&end);

	printf("2. n = %lld, k = %lld\n", n, k);
	printf("이항계수 = %lld\n", result); //n, k, 이항계수 출력
	printf("소요시간 = %8.6fμsec\n", ((double)(end.QuadPart - start.QuadPart) / (double)liFrequency.QuadPart) * 1000000);
	//두번째 방법에 대한 결과 출력
}
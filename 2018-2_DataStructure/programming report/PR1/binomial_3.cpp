#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

long long binomial_3(long long n, long long k) {
	int bin[500][500]; //2차원 배열 선언
	for (long long i = 1; i <= n; i++) {
		for (long long j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				bin[i][j] = 1; //nC1과 nCn 값에 해당하는 부분에 bin에 1 저장.
			}
			else {
				if (i >= 2)
					bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
				// 재귀적 정의 이용하여 배열에 이항계수 값 저장
			}
		}
	}
	return bin[n][k]; //n행 k열에 저장된 값을 return
}// 이항계수 값을 재귀적 정의를 이용하여, 반복문을 이용해 구하는 방법

int main(void) {
	//1771076 사이버보안 임은지
	long long n, k, result;
	LARGE_INTEGER start, end, liFrequency;

	scanf("%lld %lld", &n, &k); //n, k 입력받음

	QueryPerformanceFrequency(&liFrequency);
	QueryPerformanceCounter(&start);
	result = binomial_3(n, k);
	QueryPerformanceCounter(&end);

	printf("2. n = %lld, k = %lld\n", n, k);
	printf("이항계수 = %lld\n", result); //n, k, 이항계수 출력
	printf("소요시간 = %8.6fμsec\n", ((double)(end.QuadPart - start.QuadPart) / (double)liFrequency.QuadPart) * 1000000);
	//두번째 방법에 대한 결과 출력
}
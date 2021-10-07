#include <stdio.h>


//x^y mod p 를 계산하는 함수.
long long square_and_multiply(long long x, long long y, long long p) {
	long long result = 1;
	while (y > 0) {
		if (y % 2 != 0) { //y가 2로 나누어지 않으면 2진수가 1인 경우이므로,
			result *= x; //result에 x를 곱하고
			result %= p; //mod p

		}
		x *= x; //2로 나누어질 때도 나누어지지 않을때도
		x %= p; //x에 제곱을 하고 mod p
		y /= 2; //다음 단계로 넘어가야하므로 y는 2로 나눔

	}
	return result;

}

//n! mod m 을 계산하는 함수. 
long long fact_n_mod_m(long long n, long long m) {
	long long result = 1;
	for (long long i = 1; i <= n; i++) {
		result *= i;
		result %= m;

	}
	return result;

}

int main() {
	long n, k;
	long m = 1000000007;
	scanf("%d %d", &n, &k);
	long long result = 1;

	long long a = fact_n_mod_m(n, m); // n! mod m
	long long b = fact_n_mod_m(k, m) * fact_n_mod_m(n - k, m) % m; // k!(n-k)! mod m
	long long inverse_b = square_and_multiply(b, m - 2, m); //b의 역원 b^(m-2) 구함.

	inverse_b %= m; //b의 역원 mod m
	result = a * inverse_b % m; //결과 = a * b^(m-2) mod m

	printf("%lld", result);

	return 0;
}

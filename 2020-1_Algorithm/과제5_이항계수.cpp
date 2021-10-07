#include <stdio.h>


//x^y mod p �� ����ϴ� �Լ�.
long long square_and_multiply(long long x, long long y, long long p) {
	long long result = 1;
	while (y > 0) {
		if (y % 2 != 0) { //y�� 2�� �������� ������ 2������ 1�� ����̹Ƿ�,
			result *= x; //result�� x�� ���ϰ�
			result %= p; //mod p

		}
		x *= x; //2�� �������� ���� ���������� ��������
		x %= p; //x�� ������ �ϰ� mod p
		y /= 2; //���� �ܰ�� �Ѿ���ϹǷ� y�� 2�� ����

	}
	return result;

}

//n! mod m �� ����ϴ� �Լ�. 
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
	long long inverse_b = square_and_multiply(b, m - 2, m); //b�� ���� b^(m-2) ����.

	inverse_b %= m; //b�� ���� mod m
	result = a * inverse_b % m; //��� = a * b^(m-2) mod m

	printf("%lld", result);

	return 0;
}

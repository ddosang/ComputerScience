#include <stdio.h>

//팩토리얼, 피보나치 재귀 함수
int factorial(int n);
int fibonacci(int n);

int main(void) {
	int n, fac = 1, fib = 0;
	scanf_s("%d", &n);

	printf("n = %d\n", n);
	printf("The factorial of %d = %d\n", n, factorial(n));
	printf("The %d-th Fibonacci number = %d\n", n, fibonacci(n));
}

int factorial(int n) {
	if (n <= 0)
		return 1;
	else
		return (n*factorial(n - 1));
}
int fibonacci(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (fibonacci(n - 1) + fibonacci(n - 2));
}

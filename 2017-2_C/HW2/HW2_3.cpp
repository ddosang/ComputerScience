#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int isPrime(int); //prototyping
int main(void)
{
	int a, n,i;//정수형 변수 선언
	printf("Input the upper limit: ");
	scanf("%d", &n); //어느 범위에서 소수를 찾을것인지 입력받는다.
	printf("Prime numbers between 1 and %d are ...\n",n);

	
	for (i = 2; i <= n; i++)
	{
		a = isPrime(i);//함수에 i대입
		if (a == 1)
			printf("%d ",i);
		/*루프 안에 넣었을때 소수이면 출력해야 하므로 a값이 1일때 출력*/
	}
	printf("\n");

	return 0;

}

int isPrime(int n)
{
/*n이 소수인지 아닌지 판별하는 함수*/
	int i, a;
	for (i = 2; i <= n - 1; i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;//소수이면 1을, 소수가 아니면 0을 반환
}
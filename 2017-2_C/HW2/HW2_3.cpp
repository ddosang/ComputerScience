#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int isPrime(int); //prototyping
int main(void)
{
	int a, n,i;//������ ���� ����
	printf("Input the upper limit: ");
	scanf("%d", &n); //��� �������� �Ҽ��� ã�������� �Է¹޴´�.
	printf("Prime numbers between 1 and %d are ...\n",n);

	
	for (i = 2; i <= n; i++)
	{
		a = isPrime(i);//�Լ��� i����
		if (a == 1)
			printf("%d ",i);
		/*���� �ȿ� �־����� �Ҽ��̸� ����ؾ� �ϹǷ� a���� 1�϶� ���*/
	}
	printf("\n");

	return 0;

}

int isPrime(int n)
{
/*n�� �Ҽ����� �ƴ��� �Ǻ��ϴ� �Լ�*/
	int i, a;
	for (i = 2; i <= n - 1; i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;//�Ҽ��̸� 1��, �Ҽ��� �ƴϸ� 0�� ��ȯ
}
#include <stdio.h>
#include <string.h>
#include <math.h>

int func_bin(int *a); //�Լ� ������Ÿ����

int main() {
	int arr[8]; //1����Ʈ = 8��Ʈ �̹Ƿ� 8ĭ¥�� ������ �迭 ����
	int *a; //������ ������ a ����
	int dem;//������ ���� dem ����

	a = arr; //a�� ������ �迭 arr�� �ּ� ���� (arr == &arr[0])

	printf("Input the bits for one byte.");
	for (int i = 0; i < 8; i++)
		scanf(" %d", (a + i));
	// 8���� ����(0 || 1)�� �Է¹޴´�.
	printf("\n");

	printf("Binary number: ");
	for (int i = 0; i < 8; i++)
		printf("%d ", *(a + i));
	// 2������ ��� : �տ��� �Է¹��� 8���� ���ڸ� ����Ѵ�.
	// �����͸� �̿��ϸ�, *(a + i) == a[i]

	dem = func_bin(a);
	printf("\n");
	printf("Demical number: %d\n", dem);
	//�Լ��� ���ϰ��� dem�� ���� �� ����Ѵ�.
}

int func_bin(int *a) {// 2������ 10������ �ٲپ� �����ϴ� �Լ� func_bin
	int dem = 0;
	
	for (int i = 0; i < 8; i++) {
		if (*(a + i) == 1)
			dem += (*(a + i)) * pow(2, 7 - i);
	}
	/*2. ������ ���� �� ó�� 
	00000101 �� 0 x 2^7+ 0 x 2^6+0 x 2^5+ 0 x 2^4
	+ 0 x 2^3+ 1 x 2^2 + 0 x 2^1 +0 x 2^0 �̹Ƿ�
	a[i]���� 1�� ����� ������ 2^(7-i)�� ���� ��
	dem�� ��� ���Ѵ�.
	�װ��� ���� <math.h> �� pow �Լ��� �̿��Ѵ�.*/
	return dem;
	//dem ���� ��ȯ�Ѵ�.
}
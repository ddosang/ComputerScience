#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#define price1 3000
#define price2 3700
#define price3 3500
#define price4 1200 //�޴��� ���� ���� ����
void func_menu();
int func_order(int); //prototyping
int main(void)
{
	int a=0, total = 0, price=0; //������ ���� a, total, price ���� �� 0���� �ʱ�ȭ
	char ch; //������ ���� ch ����
	do
	{
		func_menu(); //�޴��� ��� �Լ� ���
		price = func_order(a); //�ֹ����� �޴��� ������ ��ȯ���ִ� �Լ� ���
		total += price; //��ü ���ݿ� �ջ�

		printf("\t-> Press 'y' to continue, Press any other key to quit.:");
		scanf(" %c", &ch);
	} while (ch == 'y');
	/*do while ���� �̿��� �չ��忡�� ���� ���ڰ� y�϶� �ݺ�*/

	printf("------------------------------------------------------------------------\n");
	printf("Total amount of pay : %d\n", total); // ��ü ���� (total) ���
	return 0;
}

void func_menu() {
	/*��ȭ ���� ���� �޴��� ��� �Լ�*/
	printf("********************************************\n");
	printf("*            EWHA BURGER                   *\n");
	printf("********************************************\n");
	printf("Menu:\n");
	printf("\t1. Cheese Burger : 3, 000\n");
	printf("\t2. Bulgogi Burger : 3, 700\n");
	printf("\t3. Fish Burger : 3, 500\n");
	printf("\t4. Soda Drink : 1, 200\n");
}

int func_order(int a) {
	/*�ֹ� �ް� ������ return�ϴ� �Լ�*/
	int price=0; //�������� price ���� �� 0���� �ʱ�ȭ
	printf("Please choose the menu: ");
	scanf("%d", &a);

	switch (a)
	{

	case 4: price = price4; break;
	case 3: price = price3; break;
	case 2: price = price2; break;
	case 1: price = price1; break; 
	//a���� ���� price�� ������ �޴� �� �ο�

	defalut:printf("Invalid Menu!"); break;
	}
	return price;//price ��ȯ
}

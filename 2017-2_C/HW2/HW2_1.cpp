#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#define price1 3000
#define price2 3700
#define price3 3500
#define price4 1200 //�޴��� ���� ���� ����
int main(void)
{
	int a, total = 0; //������ ���� a�� total ���� �� total�� 0���� �ʱ�ȭ
	char ch; //������ ���� ch ����
	do
	{
		printf("********************************************\n");
		printf("*            EWHA BURGER                   *\n");
		printf("********************************************\n");
		printf("Menu:\n");
		printf("\t1. Cheese Burger : 3, 000\n");
		printf("\t2. Bulgogi Burger : 3, 700\n");
		printf("\t3. Fish Burger : 3, 500\n");
		printf("\t4. Soda Drink : 1, 200\n");
		/*��ȭ ���� ���� �޴��� ���*/

		printf("Please choose the menu: ");
		scanf("%d", &a);
		/*�޴� ��ȣ a�� �޴��� ���°��� scanf�� �޾Ƶ��δ�*/

		switch (a)
		{

		case 4: total += price4; break;
		case 3: total += price3; break;
		case 2: total += price2; break;
		case 1: total += price1; break;

		default: printf("Invalid Menu!\n"); break;

		}/*switch���� ����� 1~4 �޴��� ����� �� total�� �� �޴��� ������ ���Ѵ�.
		 ���� �޴��ǿ� ���� �޴��� ����  Invalid Menu!��� ������ ��µǰ� �Ѵ�.*/

		printf("\t-> Press 'y' to continue, Press any other key to quit.:");
		scanf(" %c", &ch);
	} while (ch == 'y'); //do while ���� ����� �ٷ� �չ��忡�� �Էµ� ���ڰ� y�϶� �ݺ��ϰ� �Ѵ�.

	printf("------------------------------------------------------------------------\n");
	printf("Total amount of pay : %d\n", total); // ��ü ���� (total) ���
	return 0;
}
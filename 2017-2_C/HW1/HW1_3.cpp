/*1771076 ������ ����1 3�� ����*/
#include <stdio.h>
int main(void)
{
	int i = 1, n, score; // int�� ���� i, n, score ����, i=1�� �ʱ�ȭ
						 //������ score�� ���� ���� ����, score ���ð� ���� �������̹Ƿ� int�� �ϰڴ�.
	float average, sum = 0; // float�� ���� average, sum ����. sum=0���� �ʱ�ȭ
	printf("How many students are there? ");
	scanf("%d", &n); //�л��� �Է� �޴´�.

	for (i = 1; i <= n;i++) //i�� 1���� �����Ͽ� n���� ���������� �ϳ��� �ø���
	{
		printf("Student %d : ", i); //'student 4 : ' ���·� �߷�
		scanf("%d", &score); //���� �Է� �ޱ�
		sum = sum + score; // sum�̶�� ������ sum+score ���� �����Ѵ�.
	}
	average = sum / n; //��� ����

	printf("==========================\n");
	printf("The sum of scores : %.0f\n", sum); //���ÿ� ���°�ó�� �Ҽ��� ���� sum���� ���
	printf("The average of scores : %.2f\n", average); //average���� �Ҽ��� ��°�ڸ����� ���

	return 0;
}
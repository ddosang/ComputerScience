/*����1 2�� ����*/
#include <stdio.h>
int main(void)
{
	int i = 1, n, score; // int�� ���� i, n, score ����, i=1�� �ʱ�ȭ
	//������ score�� ���� ���� ����, score ���ð� ���� �������̹Ƿ� int�� �ϰڴ�.
	float average, sum = 0; // float�� ���� average, sum ����. sum=0���� �ʱ�ȭ
	printf("How many students are there? ");
	scanf("%d", &n); //�л��� �Է� �޴´�.
	
	while (i <= n) //i�� n���� �������� �ݺ�
	{
		printf("Student %d : ", i); //'student 4 : ' ���·� �߷�
		scanf("%d", &score); //���� �Է� �ޱ�
		sum = sum + score; // sum�̶�� ������ sum+score ���� �����Ѵ�.
		i = i + 1; //i�� i+1�� �����Ѵ�.
	}
	average = sum / n; //��� ����

	printf("==========================\n");
	printf("The sum of scores : %.0f\n", sum); //���ÿ� ���°�ó�� �Ҽ��� ���� sum���� ���
	printf("The average of scores : %.2f\n", average); //average���� �Ҽ��� ��°�ڸ����� ���

	return 0;
}
/*����1 1�� ����*/
#include <stdio.h>
#define Pi 3.141592
int main(void)
{

	int r; //������ r ����
	double area, circumference;//���� ������ ���� ���� ����

	printf("Input the radius of a circle: ");
	scanf("%d", &r); //r�� �Է¹޴´�.

	area = Pi*r*r;
	circumference = 2 * Pi*r;//���� ���̿� ���� �����


	printf("\n==============================\n");
	printf("The area of the circle is %.2lf\n.", area);//�Ҽ��� ���ڸ��� double�� ���� ���� ���
	printf("The circumference of the circle is %.2lf.\n", circumference);//�Ҽ��� ���ڸ��� double�� ���� ���� ���

	return 0;

}
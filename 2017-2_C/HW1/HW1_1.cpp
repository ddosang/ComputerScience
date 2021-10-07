/*과제1 1번 문제*/
#include <stdio.h>
#define Pi 3.141592
int main(void)
{

	int r; //정수형 r 선언
	double area, circumference;//넓이 변수와 지름 변수 선언

	printf("Input the radius of a circle: ");
	scanf("%d", &r); //r을 입력받는다.

	area = Pi*r*r;
	circumference = 2 * Pi*r;//원의 넓이와 지름 관계식


	printf("\n==============================\n");
	printf("The area of the circle is %.2lf\n.", area);//소숫점 두자리로 double형 넓이 변수 출력
	printf("The circumference of the circle is %.2lf.\n", circumference);//소숫점 두자리로 double형 지름 변수 출력

	return 0;

}
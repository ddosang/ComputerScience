#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#define price1 3000
#define price2 3700
#define price3 3500
#define price4 1200 //메뉴에 따른 가격 정의
int main(void)
{
	int a, total = 0; //정수형 변수 a와 total 선언 후 total을 0으로 초기화
	char ch; //문자형 변수 ch 선언
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
		/*이화 버거 가게 메뉴판 출력*/

		printf("Please choose the menu: ");
		scanf("%d", &a);
		/*메뉴 번호 a로 메뉴를 고르는것을 scanf로 받아들인다*/

		switch (a)
		{

		case 4: total += price4; break;
		case 3: total += price3; break;
		case 2: total += price2; break;
		case 1: total += price1; break;

		default: printf("Invalid Menu!\n"); break;

		}/*switch문을 사용해 1~4 메뉴를 골랐을 때 total에 각 메뉴의 가격을 더한다.
		 만약 메뉴판에 없는 메뉴를 고르면  Invalid Menu!라는 문구가 출력되게 한다.*/

		printf("\t-> Press 'y' to continue, Press any other key to quit.:");
		scanf(" %c", &ch);
	} while (ch == 'y'); //do while 문을 사용해 바로 앞문장에서 입력된 글자가 y일때 반복하게 한다.

	printf("------------------------------------------------------------------------\n");
	printf("Total amount of pay : %d\n", total); // 전체 가격 (total) 출력
	return 0;
}
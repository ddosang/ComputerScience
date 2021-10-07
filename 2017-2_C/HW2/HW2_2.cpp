#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#define price1 3000
#define price2 3700
#define price3 3500
#define price4 1200 //메뉴에 따른 가격 정의
void func_menu();
int func_order(int); //prototyping
int main(void)
{
	int a=0, total = 0, price=0; //정수형 변수 a, total, price 선언 후 0으로 초기화
	char ch; //문자형 변수 ch 선언
	do
	{
		func_menu(); //메뉴판 출력 함수 사용
		price = func_order(a); //주문받은 메뉴의 가격을 반환해주는 함수 사용
		total += price; //전체 가격에 합산

		printf("\t-> Press 'y' to continue, Press any other key to quit.:");
		scanf(" %c", &ch);
	} while (ch == 'y');
	/*do while 문을 이용해 앞문장에서 받은 문자가 y일때 반복*/

	printf("------------------------------------------------------------------------\n");
	printf("Total amount of pay : %d\n", total); // 전체 가격 (total) 출력
	return 0;
}

void func_menu() {
	/*이화 버거 가게 메뉴판 출력 함수*/
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
	/*주문 받고 가격을 return하는 함수*/
	int price=0; //지역변수 price 선언 후 0으로 초기화
	printf("Please choose the menu: ");
	scanf("%d", &a);

	switch (a)
	{

	case 4: price = price4; break;
	case 3: price = price3; break;
	case 2: price = price2; break;
	case 1: price = price1; break; 
	//a값에 따라 price에 각각의 메뉴 값 부여

	defalut:printf("Invalid Menu!"); break;
	}
	return price;//price 반환
}

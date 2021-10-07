/*과제1 2번 문제*/
#include <stdio.h>
int main(void)
{
	int i = 1, n, score; // int형 변수 i, n, score 선언, i=1로 초기화
	//문제에 score에 대한 말이 없고, score 예시가 전부 정수형이므로 int로 하겠다.
	float average, sum = 0; // float형 변수 average, sum 선언. sum=0으로 초기화
	printf("How many students are there? ");
	scanf("%d", &n); //학생수 입력 받는다.
	
	while (i <= n) //i가 n보다 작은동안 반복
	{
		printf("Student %d : ", i); //'student 4 : ' 형태로 추력
		scanf("%d", &score); //점수 입력 받기
		sum = sum + score; // sum이라는 변수에 sum+score 값을 대입한다.
		i = i + 1; //i에 i+1을 대입한다.
	}
	average = sum / n; //평균 수식

	printf("==========================\n");
	printf("The sum of scores : %.0f\n", sum); //예시에 나온것처럼 소숫점 없이 sum값을 출력
	printf("The average of scores : %.2f\n", average); //average값을 소숫점 둘째자리까지 출력

	return 0;
}
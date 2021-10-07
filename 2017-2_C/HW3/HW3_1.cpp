#include <stdio.h>
#include <string.h>
#include <math.h>

int func_bin(int *a); //함수 프로토타이핑

int main() {
	int arr[8]; //1바이트 = 8비트 이므로 8칸짜리 정수형 배열 생성
	int *a; //정수형 포인터 a 선언
	int dem;//정수형 변수 dem 선언

	a = arr; //a에 정수형 배열 arr의 주소 대입 (arr == &arr[0])

	printf("Input the bits for one byte.");
	for (int i = 0; i < 8; i++)
		scanf(" %d", (a + i));
	// 8개의 숫자(0 || 1)를 입력받는다.
	printf("\n");

	printf("Binary number: ");
	for (int i = 0; i < 8; i++)
		printf("%d ", *(a + i));
	// 2진수를 출력 : 앞에서 입력받은 8개의 숫자를 출력한다.
	// 포인터를 이용하면, *(a + i) == a[i]

	dem = func_bin(a);
	printf("\n");
	printf("Demical number: %d\n", dem);
	//함수의 리턴값을 dem에 대입 후 출력한다.
}

int func_bin(int *a) {// 2진수를 10진수로 바꾸어 리턴하는 함수 func_bin
	int dem = 0;
	
	for (int i = 0; i < 8; i++) {
		if (*(a + i) == 1)
			dem += (*(a + i)) * pow(2, 7 - i);
	}
	/*2. 문제에 나온 것 처럼 
	00000101 → 0 x 2^7+ 0 x 2^6+0 x 2^5+ 0 x 2^4
	+ 0 x 2^3+ 1 x 2^2 + 0 x 2^1 +0 x 2^0 이므로
	a[i]에서 1이 저장된 곳에만 2^(7-i)를 곱한 후
	dem에 모두 더한다.
	그것을 위해 <math.h> 와 pow 함수를 이용한다.*/
	return dem;
	//dem 값을 반환한다.
}
#include <stdio.h>
const int MAX = 1001; //문제에서 주어진 입력 배열 최대 크기를 상수로 지정.


//최장 증가 부분 수열을 화면에 출력하고, 그 길이를 출력/return 하는 함수.
int longest_increasing_subseq(int n, int* s) { 
	//입력값 : 입력 배열 s와 입력 배열의 크기 n


	int i, j;  //for문을 돌리기 위해 사용.
	int max = n + 1;  //중간 계산시 배열의 index를 1~n 으로 사용하기 위해 사용하는 변수.

	int h[1000] = { 0 }, p[1000] = { 0 };  //h : 수열 길이, p: 전 값 인덱스를 담기 위한 수열.
	int max_result = 0, index;  //최장 증가 부분 수열 길이를 담을 max_result
	int lis[1000] = { 0 };  //최장 증가 수열을 담을 배열 lis



//0~(n-1)을 index로 쓰던 배열을 1~n으로 옮기고, s[0]에 작은 값을 저장
	for (int i = n - 1; i >= 0; i--) {
		*(s + i + 1) = *(s + i);
	}
	*(s + 0) = -10; //0번에 매우 작은 값을 넣는다. 수열에 있는 값이 모두 양수라 가정하고 -10을 넣었다.
	


//모든 원소의 h값과 p값을 계산하여 넣어준다.
	for (i = 1; i < max ; i++) {
		for (j = 0; j < i; j++) {
			if ((*(s + i) > * (s + j)) && (h[i] <= h[j])) { //h값과 p값은 다음 조건을 만족 할 때 바뀜
				//앞의 원소보다 커야 하는 조건과, h배열에 작은 값이 갱신되지 않게 하기 위한 조건. 

				h[i] = h[j] + 1;
				p[i] = j; //이전 원소의 index를 저장
			}
		}
	}



//최장 부분 수열의 길이 찾기.
	for (i = 1; i < max; i++) {
		if (max_result < h[i]) {
			max_result = h[i];
			index = i;
			//저장 된 값 중 가장 큰 값 사용.
		}
	}





//최장 증가 수열을 lis 배열에 저장
	i = max_result;

	while (index != 0) {
		lis[--i] = *(s + index);
		index = p[index];
	}


//lis 배열을 순서대로 출력해 최장 증가 부분 수열 출력
	printf("\n최장 증가 부분 수열: ");
	for (i = 0; i < max_result; i++) {
		printf("%d ", lis[i]);
	}

//최장 증가 부분 수열의 길이.
	printf("\n최장 증가 부분 수열 길이 : %d\n", max_result);
	
	return max_result; //최장 증가 수열의 길이 return
}



int main() {
	int s[MAX], n; //입력을 위한 변수 선언

	printf("수열 길이 : ");
	scanf("%d", &n); //수열 길이 n을 입력받음.

	printf("수열 원소 : ");
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i]); //앞에서 입력받은(n) 개수만큼 수열의 원소를 입력함.

	longest_increasing_subseq(n, s); //함수 호출

	return 0;
}
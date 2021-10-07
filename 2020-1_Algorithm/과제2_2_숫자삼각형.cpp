#include <stdio.h>
const int MAX = 50; //배열의 최대 크기 : 백준 문제에 맞추면 501이어야하지만, 로컬에서 돌릴 때, 배열 오류가 나서 작게 줄였음. 

int number_triangle(int a[][MAX], int n) { //최적의 경로, 경로값 계산하여 출력해주는 함수

	int best[MAX][MAX] = { 0 }; //숫자 삼각형 레벨 1에서 레벨 x의 y번째 위치에서 끝나는 최적 경로값을 best[x][y]에 저장
	
	int i, j;
	int max_result = 0; //최적의 경로값을 저장하기 위한 변수
	char lrlr[MAX][MAX] = { 'A' }; //최적의 경로로 (x, y)에 올 때 (x - 1)레벨의 왼쪽에서 왔는지 오른쪽에서 왔는지를 저장

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			if (best[i - 1][j - 1] > best[i - 1][j]) {//왼쪽 루트가 더 큰 경우
				best[i][j] = a[i][j] + best[i - 1][j - 1]; //왼쪽 루트의 최적 경로값에 a[i][j]값을 더하고,
				lrlr[i][j] = 'L'; //왼쪽에서 왔다고 표시
			}
			else {
				best[i][j] = a[i][j] + best[i - 1][j];
				lrlr[i][j] = 'R';
			}//오른쪽 루트가 더 큰 경우.
		}
	}


	for (i = 1; i <= n; i++) {
		if (max_result < best[n][i]) max_result = best[n][i];
	}//n 레벨에서 best값이 가장 큰 값을 찾으면 그 값이 최적의 경로값이다.



//숫자 삼각형에서 최적 경로 자체를 출력하기 위한 코드



	int lis[MAX] = { 0 };
	int lr_right;


	//배열을 출력하기 위해 최적의 경로 값에서 lrlr 값을 보고 위 레벨의 원소로 찾아갈 것이므로
	for (i = 1; i <= n; i++) {
		if (best[n][i] == max_result) {
			lis[n] = a[n][i];
			lr_right = i;
		}
	}//n 레벨에서 최적의 경로 값을 가지는 위치를 찾아 
	//숫자 삼각형 최적 경로 배열 lis의 맨 마지막값에 넣고
	//그 때의 y좌표를 lr_right에 저장한다.


	int finder = lrlr[n][lr_right]; //최적의 경로값을 가지는 위치의 lrlr 배열 값을 finder에 저장


	for (int i = n; i > 1; i--) {
		if (finder == 'L') { //만약 왼쪽에서 왔다면 왼쪽 값을 찾기 위해서는 x,y 좌표가 모두 1씩 줄어들어야 함
			lr_right--; //y 좌표를 하나 줄이고
			lis[i - 1] = a[i - 1][lr_right]; //x좌표를 줄여 그 때의 배열 값을 넣음
			finder = lrlr[i - 1][lr_right];  //이제 왼쪽 값을 기준으로 움직여야하므로 lrlr 배열도 똑같이 처리
		}
		else if (finder == 'R') {
			lis[i - 1] = a[i - 1][lr_right];
			finder = lrlr[i - 1][lr_right];
		}//오른쪽 일 때는 오른쪽의 좌표에 맞추어서 같은 과정을 진행한다.
	}// lis 배열에 최적의 경로 저장.



	//최적의 경로를 출력
	printf("\nbest route: ");
	for (i = 1; i <= n; i++) {
		printf("%d ", lis[i]);
	}
	
	//반환값으로 max_result를 가지지만, 함수 하나로 처리하려고 출력 코드를 넣었음.
	printf("\n max_result : %d", max_result); 

	
	return max_result;
}

int main() {

	int n, tri[MAX][MAX] = { 0 };
	scanf("%d", &n); //레벨 값을 입력 받음.

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &tri[i][j]); //그 레벨 값에 맞추어 숫자 삼각형을 입력 받음.


	number_triangle(tri, n); //함수 호출

	return 0;
}



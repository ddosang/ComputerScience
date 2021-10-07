#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define ROOPCOUNT 10000 //방 온도 계산을 위해 for loop를 몇 번 돌지 저장.

int main(void) {
	//프로세스 4개로 실행

	int my_rank, size; //process 번호와 개수
	double R[102][102] = { 0.0 }; //방안의 초기 온도.

	double smallR[27][102] = { 0.0 }; //각 프로세스가 방 온도를 나누어 가질 배열
	//벽난로 문제에서 방 내부(100*100) 을 4개의 process에게 세로로 쪼개 줄 것이므로
	//각각 25*100 이나 벽난로 문제에서는 가장자리가 필요하므로 한 배열의 크기가 27*102가 됨.

	double scatterR[100][102] = { 0.0 }; 
	//MPI_Scatter를 이용해 100개 행을 25개 행씩 나누기 위해
	//나누는 용도의 배열을 새로 선언. 이 배열은 R배열의 1행부터 100행까지를 담은것.
	//초기엔 어차피 R배열의 1~100행이 모두 0으로 채워져 있으니 초기화는 0으로 하면 됨.

	int m1, m2, n1, n2; //결과 테스트를 위한 구간 출력을 위한 변수.


	MPI_Status status;
	MPI_Datatype rowType; //25행으로 쪼깰것이므로 행 타입 변수 선언


	for (int j = 40; j < 60; j++)
		R[0][j] = 200.0; //벽난로의 온도 (계속 유지)

	//MPI 실행을 위한 함수.
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	//MPI_Comm_size(MPI_COMM_WORLD, &size); //size는 사용하지 않아서 주석처리.


	//행에 대한 datatype 정의
	MPI_Type_contiguous(102, MPI_DOUBLE, &rowType);
	MPI_Type_commit(&rowType);

	//배열 쪼개야함. MPI_Scatter를 이용해 100개 행을 25개 행씩 나누어 smallR의 1행~25행에 저장한다.
	MPI_Scatter(scatterR, 25, rowType, &smallR[1][0], 25, rowType, 0, MPI_COMM_WORLD);


	//각 프로세스가 나눠진 구역의 방의 온도를 계산한다.
	if (my_rank == 0) {
		//smallR은 현재 0행과 26행이 전부 0으로 채워져 있으므로, 
		//process0이 가져간 맨 윗 배열의 경우에는 0행에 벽난로의 온도를 넣어준다.
		for(int i = 40; i < 60 ; i++) {
			smallR[0][i] = 200.0;
		}

		//위에서 말했듯 smallR은 현재 0행과 26행이 전부 0으로 채워져 있으므로, 
		//가장자리 정보를 먼저 공유한 후 계산을 해야함.

		//0번의 25번행 -> 1번의 0번 행, 1번의 1번행 -> 0번의 26번행
		MPI_Sendrecv(&smallR[25][0], 1, rowType, 1, 1, &smallR[26][0], 1, rowType, 1, 1, MPI_COMM_WORLD, &status);

		for (int k = 0; k < ROOPCOUNT; k++) {
			//방 온도 1회 계산
			for (int i = 1; i < 26; i++) {
				for (int j = 1; j < 101; j++) {
					smallR[i][j] = 0.25 * (smallR[i][j - 1] + smallR[i][j + 1] + smallR[i - 1][j] + smallR[i + 1][j]);
				}
			}
			//가장자리 정보 공유 : 0번의 25번행 -> 1번의 0번 행, 1번의 1번행 -> 0번의 26번행
			MPI_Sendrecv(&smallR[25][0], 1, rowType, 1, 1, &smallR[26][0], 1, rowType, 1, 1, MPI_COMM_WORLD, &status);
		}
	} else if (my_rank == 1) {
		//1, 2번의 경우에는 위아래의 배열을 담당하는 프로세스가 모두 존재해서, sendrecv를 2회 실행해야함

		//가장자리 정보 공유 : 1번의 1번행 -> 0번의 26번행, 0번의 25번행 -> 1번의 0번 행
		MPI_Sendrecv(&smallR[1][0], 1, rowType, 0, 1, &smallR[0][0], 1, rowType, 0, 1, MPI_COMM_WORLD, &status);
		//1번의 25번행 -> 2번의 0번행, 2번의 1번행 -> 1번의 26번 행
		MPI_Sendrecv(&smallR[25][0], 1, rowType, 2, 1, &smallR[26][0], 1, rowType, 2, 1, MPI_COMM_WORLD, &status);

		for (int k = 0; k < ROOPCOUNT; k++) {
			//방 온도 1회 계산
			for (int i = 1; i < 26; i++) {
				for (int j = 1; j < 101; j++) {
					smallR[i][j] = 0.25 * (smallR[i][j - 1] + smallR[i][j + 1] + smallR[i - 1][j] + smallR[i + 1][j]);
				}
			}
			//가장자리 정보 공유 : 1번의 1번행 -> 0번의 26번행, 0번의 25번행 -> 1번의 0번 행
			MPI_Sendrecv(&smallR[1][0], 1, rowType, 0, 1, &smallR[0][0], 1, rowType, 0, 1, MPI_COMM_WORLD, &status);
			//1번의 25번행 -> 2번의 0번행, 2번의 1번행 -> 1번의 26번 행
			MPI_Sendrecv(&smallR[25][0], 1, rowType, 2, 1, &smallR[26][0], 1, rowType, 2, 1, MPI_COMM_WORLD, &status);
		}

	} else if (my_rank == 2) {
		//가장자리 정보 공유 : 2번의 1번행 -> 1번의 26번행, 1번의 25번행 -> 2번의 0번행
		MPI_Sendrecv(&smallR[1][0], 1, rowType, 1, 1, &smallR[0][0], 1, rowType, 1, 1, MPI_COMM_WORLD, &status);
		//2번의 25번행 -> 3번의 0번행, 3번의 1번행 -> 2번의 26번행
		MPI_Sendrecv(&smallR[25][0], 1, rowType, 3, 1, &smallR[26][0], 1, rowType, 3, 1, MPI_COMM_WORLD, &status);

		for (int k = 0; k < ROOPCOUNT; k++) {
			//방 온도 1회 계산
			for (int i = 1; i < 26; i++) {
				for (int j = 1; j < 101; j++) {
					smallR[i][j] = 0.25 * (smallR[i][j - 1] + smallR[i][j + 1] + smallR[i - 1][j] + smallR[i + 1][j]);
				}
			}
			//가장자리 정보 공유 : 2번의 1번행 -> 1번의 26번행, 1번의 25번행 -> 2번의 0번행
			MPI_Sendrecv(&smallR[1][0], 1, rowType, 1, 1, &smallR[0][0], 1, rowType, 1, 1, MPI_COMM_WORLD, &status);
			//2번의 25번행 -> 3번의 0번행, 3번의 1번행 -> 2번의 26번행
			MPI_Sendrecv(&smallR[25][0], 1, rowType, 3, 1, &smallR[26][0], 1, rowType, 3, 1, MPI_COMM_WORLD, &status);
		}

	} else {
		//가장자리 정보 공유 : 3번의 1번행 -> 2번의 26번행, 2번의 25번행 -> 3번의 0번행
		MPI_Sendrecv(&smallR[1][0], 1, rowType, 2, 1, &smallR[0][0], 1, rowType, 2, 1, MPI_COMM_WORLD, &status);

		for (int k = 0; k < ROOPCOUNT; k++) {
			//방 온도 1회 계산
			for (int i = 1; i < 26; i++) {
				for (int j = 1; j < 101; j++) {
					smallR[i][j] = 0.25 * (smallR[i][j - 1] + smallR[i][j + 1] + smallR[i - 1][j] + smallR[i + 1][j]);
				}
			}
			//가장자리 정보 공유 : 3번의 1번행 -> 2번의 26번행, 2번의 25번행 -> 3번의 0번행
			MPI_Sendrecv(&smallR[1][0], 1, rowType, 2, 1, &smallR[0][0], 1, rowType, 2, 1, MPI_COMM_WORLD, &status);
		}
	} 
	

	//계산 끝나면 배열 합쳐야함. R배열의 1행에 합쳐온다.
	MPI_Gather(&smallR[1][0], 25, rowType, &R[1][0], 25, rowType, 0, MPI_COMM_WORLD);

	
	//전송, 받기 끝나고 출력할 구간을 입력받아 그 구간을 출력.
	if (my_rank == 0) {
		printf("출력할 구간 (m1, m2, n1, n2) : ");
		scanf("%d %d %d %d", &m1, &m2, &n1, &n2);

		for (int i = m1; i <= m2; i++) {
			for (int j = n1; j <= n2; j++) {
				printf("%5.1f ", R[i][j]);
			}
			printf("\n");
		}
	}

	MPI_Finalize();

	return 0;
}


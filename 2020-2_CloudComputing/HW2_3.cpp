#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(void) {
	//프로세스 2개로 실행

	int my_rank, size; //process 번호와 개수
	int A[5][5] = { 0 };
	int B[5][5] = { 0 };
	MPI_Status status;
	MPI_Datatype columnType;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);


	//data 생성
	if (my_rank == 0) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				A[i][j] = i * 5 + j;
			}
		}
	} else if (my_rank == 1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				B[i][j] = i * 5 + j + 50;
			}
		}
	}

	//datatype 정의
	MPI_Type_vector(5, 1, 5, MPI_INT, &columnType);
	MPI_Type_commit(&columnType);


	//sendrecv
	if (my_rank == 0) {
		MPI_Sendrecv(&A[0][3], 1, columnType, 1, 3, &A[0][4], 1, columnType, 1, 2, MPI_COMM_WORLD, &status);

		//열 번호를 tag로 이용
		//b의 2번열 받아서 a의 4번열에 저장

	} else if (my_rank == 1) {
		MPI_Sendrecv(&B[0][2], 1, columnType, 0, 2, &B[0][4], 1, columnType, 0, 3, MPI_COMM_WORLD, &status);
		//a의 3번열 받아서 b의 4번 열에 저장.
	}


	//전송, 받기 끝나고 출력
	if (my_rank == 1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				printf("%d ", B[i][j]);
			}
			printf("\n");
		}
	}


	MPI_Finalize();

	return 0;
}


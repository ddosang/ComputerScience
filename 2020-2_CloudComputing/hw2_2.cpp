#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(void) {
	//프로세스 5개로 실행

	int my_rank, size; //process 번호와 개수
	int A[10][10];
	int B[2][10];

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);


	if (my_rank == 0) {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				A[i][j] = i * 10 + j;
	}

	MPI_Scatter(A, 20, MPI_INT, B, 20, MPI_INT, 0, MPI_COMM_WORLD); //2행씩 나눔.
	//MPI_Scatter(나눌변수,변수크기,변수형,보낸 값 받는 수,크기,변수형,노드순번,통신자)
	


	if (my_rank == 3) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d ", B[i][j]);
			}
			printf("\n");
		}	
	}


	MPI_Finalize();

	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(void) {
	//���μ��� 2���� ����

	int my_rank, size; //process ��ȣ�� ����
	int A[5][5] = { 0 };
	int B[5][5] = { 0 };
	MPI_Status status;
	MPI_Datatype columnType;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);


	//data ����
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

	//datatype ����
	MPI_Type_vector(5, 1, 5, MPI_INT, &columnType);
	MPI_Type_commit(&columnType);


	//sendrecv
	if (my_rank == 0) {
		MPI_Sendrecv(&A[0][3], 1, columnType, 1, 3, &A[0][4], 1, columnType, 1, 2, MPI_COMM_WORLD, &status);

		//�� ��ȣ�� tag�� �̿�
		//b�� 2���� �޾Ƽ� a�� 4������ ����

	} else if (my_rank == 1) {
		MPI_Sendrecv(&B[0][2], 1, columnType, 0, 2, &B[0][4], 1, columnType, 0, 3, MPI_COMM_WORLD, &status);
		//a�� 3���� �޾Ƽ� b�� 4�� ���� ����.
	}


	//����, �ޱ� ������ ���
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


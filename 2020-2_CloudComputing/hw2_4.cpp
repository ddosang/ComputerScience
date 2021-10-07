#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define ROOPCOUNT 10000 //�� �µ� ����� ���� for loop�� �� �� ���� ����.

int main(void) {
	//���μ��� 4���� ����

	int my_rank, size; //process ��ȣ�� ����
	double R[102][102] = { 0.0 }; //����� �ʱ� �µ�.

	double smallR[27][102] = { 0.0 }; //�� ���μ����� �� �µ��� ������ ���� �迭
	//������ �������� �� ����(100*100) �� 4���� process���� ���η� �ɰ� �� ���̹Ƿ�
	//���� 25*100 �̳� ������ ���������� �����ڸ��� �ʿ��ϹǷ� �� �迭�� ũ�Ⱑ 27*102�� ��.

	double scatterR[100][102] = { 0.0 }; 
	//MPI_Scatter�� �̿��� 100�� ���� 25�� �྿ ������ ����
	//������ �뵵�� �迭�� ���� ����. �� �迭�� R�迭�� 1����� 100������� ������.
	//�ʱ⿣ ������ R�迭�� 1~100���� ��� 0���� ä���� ������ �ʱ�ȭ�� 0���� �ϸ� ��.

	int m1, m2, n1, n2; //��� �׽�Ʈ�� ���� ���� ����� ���� ����.


	MPI_Status status;
	MPI_Datatype rowType; //25������ �ɱ����̹Ƿ� �� Ÿ�� ���� ����


	for (int j = 40; j < 60; j++)
		R[0][j] = 200.0; //�������� �µ� (��� ����)


	//MPI ������ ���� �Լ�.
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	//MPI_Comm_size(MPI_COMM_WORLD, &size); //size�� ������� �ʾƼ� �ּ�ó��.


	//�࿡ ���� datatype ����
	MPI_Type_contiguous(102, MPI_DOUBLE, &rowType);
	MPI_Type_commit(&rowType);

	//�迭 �ɰ�����. MPI_Scatter�� �̿��� 100�� ���� 25�� �྿ ������ smallR�� 1��~25�࿡ �����Ѵ�.
	MPI_Scatter(scatterR, 25, rowType, &smallR[1][0], 25, rowType, 0, MPI_COMM_WORLD);


	//�� ���μ����� ������ ������ ���� �µ��� ����Ѵ�.
	if (my_rank == 0) {
		//smallR�� ���� 0��� 26���� ���� 0���� ä���� �����Ƿ�, 
		//process0�� ������ �� �� �迭�� ��쿡�� 0�࿡ �������� �µ��� �־��ش�.
		for(int i = 40; i < 60 ; i++) {
			smallR[0][i] = 200.0;
		}

		//������ ���ߵ� smallR�� ���� 0��� 26���� ���� 0���� ä���� �����Ƿ�, 
		//�����ڸ� ������ ���� ������ �� ����� �ؾ���.

		//0���� 25���� -> 1���� 0�� ��, 1���� 1���� -> 0���� 26����
		MPI_Sendrecv(&smallR[25][0], 1, rowType, 1, 1, &smallR[26][0], 1, rowType, 1, 1, MPI_COMM_WORLD, &status);

		for (int k = 0; k < ROOPCOUNT; k++) {
			//�� �µ� 1ȸ ���
			for (int i = 1; i < 26; i++) {
				for (int j = 1; j < 101; j++) {
					smallR[i][j] = 0.25 * (smallR[i][j - 1] + smallR[i][j + 1] + smallR[i - 1][j] + smallR[i + 1][j]);
				}
			}
			//�����ڸ� ���� ���� : 0���� 25���� -> 1���� 0�� ��, 1���� 1���� -> 0���� 26����
			MPI_Sendrecv(&smallR[25][0], 1, rowType, 1, 1, &smallR[26][0], 1, rowType, 1, 1, MPI_COMM_WORLD, &status);
		}
	} else if (my_rank == 1) {
		//1, 2���� ��쿡�� ���Ʒ��� �迭�� ����ϴ� ���μ����� ��� �����ؼ�, sendrecv�� 2ȸ �����ؾ���

		//�����ڸ� ���� ���� : 1���� 1���� -> 0���� 26����, 0���� 25���� -> 1���� 0�� ��
		MPI_Sendrecv(&smallR[1][0], 1, rowType, 0, 1, &smallR[0][0], 1, rowType, 0, 1, MPI_COMM_WORLD, &status);
		//1���� 25���� -> 2���� 0����, 2���� 1���� -> 1���� 26�� ��
		MPI_Sendrecv(&smallR[25][0], 1, rowType, 2, 1, &smallR[26][0], 1, rowType, 2, 1, MPI_COMM_WORLD, &status);

		for (int k = 0; k < ROOPCOUNT; k++) {
			//�� �µ� 1ȸ ���
			for (int i = 1; i < 26; i++) {
				for (int j = 1; j < 101; j++) {
					smallR[i][j] = 0.25 * (smallR[i][j - 1] + smallR[i][j + 1] + smallR[i - 1][j] + smallR[i + 1][j]);
				}
			}
			//�����ڸ� ���� ���� : 1���� 1���� -> 0���� 26����, 0���� 25���� -> 1���� 0�� ��
			MPI_Sendrecv(&smallR[1][0], 1, rowType, 0, 1, &smallR[0][0], 1, rowType, 0, 1, MPI_COMM_WORLD, &status);
			//1���� 25���� -> 2���� 0����, 2���� 1���� -> 1���� 26�� ��
			MPI_Sendrecv(&smallR[25][0], 1, rowType, 2, 1, &smallR[26][0], 1, rowType, 2, 1, MPI_COMM_WORLD, &status);
		}

	} else if (my_rank == 2) {
		//�����ڸ� ���� ���� : 2���� 1���� -> 1���� 26����, 1���� 25���� -> 2���� 0����
		MPI_Sendrecv(&smallR[1][0], 1, rowType, 1, 1, &smallR[0][0], 1, rowType, 1, 1, MPI_COMM_WORLD, &status);
		//2���� 25���� -> 3���� 0����, 3���� 1���� -> 2���� 26����
		MPI_Sendrecv(&smallR[25][0], 1, rowType, 3, 1, &smallR[26][0], 1, rowType, 3, 1, MPI_COMM_WORLD, &status);

		for (int k = 0; k < ROOPCOUNT; k++) {
			//�� �µ� 1ȸ ���
			for (int i = 1; i < 26; i++) {
				for (int j = 1; j < 101; j++) {
					smallR[i][j] = 0.25 * (smallR[i][j - 1] + smallR[i][j + 1] + smallR[i - 1][j] + smallR[i + 1][j]);
				}
			}
			//�����ڸ� ���� ���� : 2���� 1���� -> 1���� 26����, 1���� 25���� -> 2���� 0����
			MPI_Sendrecv(&smallR[1][0], 1, rowType, 1, 1, &smallR[0][0], 1, rowType, 1, 1, MPI_COMM_WORLD, &status);
			//2���� 25���� -> 3���� 0����, 3���� 1���� -> 2���� 26����
			MPI_Sendrecv(&smallR[25][0], 1, rowType, 3, 1, &smallR[26][0], 1, rowType, 3, 1, MPI_COMM_WORLD, &status);
		}

	} else {
		//�����ڸ� ���� ���� : 3���� 1���� -> 2���� 26����, 2���� 25���� -> 3���� 0����
		MPI_Sendrecv(&smallR[1][0], 1, rowType, 2, 1, &smallR[0][0], 1, rowType, 2, 1, MPI_COMM_WORLD, &status);

		for (int k = 0; k < ROOPCOUNT; k++) {
			//�� �µ� 1ȸ ���
			for (int i = 1; i < 26; i++) {
				for (int j = 1; j < 101; j++) {
					smallR[i][j] = 0.25 * (smallR[i][j - 1] + smallR[i][j + 1] + smallR[i - 1][j] + smallR[i + 1][j]);
				}
			}
			//�����ڸ� ���� ���� : 3���� 1���� -> 2���� 26����, 2���� 25���� -> 3���� 0����
			MPI_Sendrecv(&smallR[1][0], 1, rowType, 2, 1, &smallR[0][0], 1, rowType, 2, 1, MPI_COMM_WORLD, &status);
		}
	} 
	

	//��� ������ �迭 ���ľ���. R�迭�� 1�࿡ ���Ŀ´�.
	MPI_Gather(&smallR[1][0], 25, rowType, &R[1][0], 25, rowType, 0, MPI_COMM_WORLD);

	
	//����, �ޱ� ������ ����� ������ �Է¹޾� �� ������ ���.
	if (my_rank == 0) {
		printf("����� ���� (m1, m2, n1, n2) : ");
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


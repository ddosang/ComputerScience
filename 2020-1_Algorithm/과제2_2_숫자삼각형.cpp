#include <stdio.h>
const int MAX = 50; //�迭�� �ִ� ũ�� : ���� ������ ���߸� 501�̾��������, ���ÿ��� ���� ��, �迭 ������ ���� �۰� �ٿ���. 

int number_triangle(int a[][MAX], int n) { //������ ���, ��ΰ� ����Ͽ� ������ִ� �Լ�

	int best[MAX][MAX] = { 0 }; //���� �ﰢ�� ���� 1���� ���� x�� y��° ��ġ���� ������ ���� ��ΰ��� best[x][y]�� ����
	
	int i, j;
	int max_result = 0; //������ ��ΰ��� �����ϱ� ���� ����
	char lrlr[MAX][MAX] = { 'A' }; //������ ��η� (x, y)�� �� �� (x - 1)������ ���ʿ��� �Դ��� �����ʿ��� �Դ����� ����

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			if (best[i - 1][j - 1] > best[i - 1][j]) {//���� ��Ʈ�� �� ū ���
				best[i][j] = a[i][j] + best[i - 1][j - 1]; //���� ��Ʈ�� ���� ��ΰ��� a[i][j]���� ���ϰ�,
				lrlr[i][j] = 'L'; //���ʿ��� �Դٰ� ǥ��
			}
			else {
				best[i][j] = a[i][j] + best[i - 1][j];
				lrlr[i][j] = 'R';
			}//������ ��Ʈ�� �� ū ���.
		}
	}


	for (i = 1; i <= n; i++) {
		if (max_result < best[n][i]) max_result = best[n][i];
	}//n �������� best���� ���� ū ���� ã���� �� ���� ������ ��ΰ��̴�.



//���� �ﰢ������ ���� ��� ��ü�� ����ϱ� ���� �ڵ�



	int lis[MAX] = { 0 };
	int lr_right;


	//�迭�� ����ϱ� ���� ������ ��� ������ lrlr ���� ���� �� ������ ���ҷ� ã�ư� ���̹Ƿ�
	for (i = 1; i <= n; i++) {
		if (best[n][i] == max_result) {
			lis[n] = a[n][i];
			lr_right = i;
		}
	}//n �������� ������ ��� ���� ������ ��ġ�� ã�� 
	//���� �ﰢ�� ���� ��� �迭 lis�� �� ���������� �ְ�
	//�� ���� y��ǥ�� lr_right�� �����Ѵ�.


	int finder = lrlr[n][lr_right]; //������ ��ΰ��� ������ ��ġ�� lrlr �迭 ���� finder�� ����


	for (int i = n; i > 1; i--) {
		if (finder == 'L') { //���� ���ʿ��� �Դٸ� ���� ���� ã�� ���ؼ��� x,y ��ǥ�� ��� 1�� �پ���� ��
			lr_right--; //y ��ǥ�� �ϳ� ���̰�
			lis[i - 1] = a[i - 1][lr_right]; //x��ǥ�� �ٿ� �� ���� �迭 ���� ����
			finder = lrlr[i - 1][lr_right];  //���� ���� ���� �������� ���������ϹǷ� lrlr �迭�� �Ȱ��� ó��
		}
		else if (finder == 'R') {
			lis[i - 1] = a[i - 1][lr_right];
			finder = lrlr[i - 1][lr_right];
		}//������ �� ���� �������� ��ǥ�� ���߾ ���� ������ �����Ѵ�.
	}// lis �迭�� ������ ��� ����.



	//������ ��θ� ���
	printf("\nbest route: ");
	for (i = 1; i <= n; i++) {
		printf("%d ", lis[i]);
	}
	
	//��ȯ������ max_result�� ��������, �Լ� �ϳ��� ó���Ϸ��� ��� �ڵ带 �־���.
	printf("\n max_result : %d", max_result); 

	
	return max_result;
}

int main() {

	int n, tri[MAX][MAX] = { 0 };
	scanf("%d", &n); //���� ���� �Է� ����.

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &tri[i][j]); //�� ���� ���� ���߾� ���� �ﰢ���� �Է� ����.


	number_triangle(tri, n); //�Լ� ȣ��

	return 0;
}



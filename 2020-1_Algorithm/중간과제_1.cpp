#include <stdio.h>
//�ʱⰪ�� �̸� �����صд�.
#define TRUE 1
#define FALSE 0
#define CITYMAX 1001 //������ �� �Ѱ���.
#define INF 987654321 //���� ū ��.

int dist[CITYMAX]; // ��������� i ���ñ����� �ּ� ����� dist[i]�� ����
int isVisited[CITYMAX]; // Ư�� ������ �湮 �Ǿ������� ����� �迭 isVisited
int W[CITYMAX][CITYMAX]; // �־��� �׷���(���ÿ� ���� �뼱)�� ����


//���� ���� n, ���� ���� start, ���� ���� end�� �Է��ϸ�
//���� �������� ���� �������� ���� �ּ� ����� printf�� ������ִ� �Լ�.
void dijkstra(int n, int start, int end) { 
	//���� ������ ��� ������ ���� ������ �Է� �޴´�.
	int i, u, w;

	for (i = 0; i < n; i++) {
		dist[i] = W[start][i]; //dist �迭�� ���� �������� �� ���������� �Ÿ���
		isVisited[i] = FALSE; //isVisited �迭�� ������ �� ���� ������
	} //�ʱ�ȭ�Ѵ�.


	dist[start] = 0; //���� �����̹Ƿ� start���� start ������ ����� 0

	for (int i = 1; i <= n; i++) { //n�� �ݺ�.

		int min = INF; //min �� �ʱ�ȭ

		// ���� ����� ���� ���� ���� ã�´�.
		for (int j = 1; j <= n; j++) {
			if (!isVisited[j] && min > dist[j]) { 
				//j�� �湮�� �� ���� �����̰�, 
				//���� min ���� start���� j���� ���� ��뺸�� ũ��
				min = dist[j]; // min ���� �� ���� �������
				start = j; //start�� �� ������ ����.
			}
		}

		isVisited[start] = TRUE; //������ �ٲ� start ���� �湮 ���

		for (int u = 1; u <= n; u++) {
			if (W[start][u] != INF && dist[u] > dist[start] + W[start][u]) {
				dist[u] = dist[start] + W[start][u];
			}// �ٲ� start�� ������ w ���� dist�� �����Ѵ�.
		}
	}

	printf("%d", dist[end]);
}



int main() {
	int n, m, start, end, cost;

	scanf("%d", &n);  scanf("%d", &m); //���� ������ ���� �뼱 ���� �Է� �޴´�.


	//�Է¹��� ���� ������ ���� ��������� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			W[i][j] = INF;
			if (i == j) {
				W[i][j] = 0;
			}
		}
		dist[i] = INF;
		isVisited[i] = 0;
	}


	// �Է� ���� ���� ����, ���� ����, ������ �� �Ǿ� �����Ƿ� 
	// ������� �Է� �ް�, ������ ���� ������� �׷����� ����� ������ ������ 
	// ������Ŀ� �� ������ �����Ѵ�.
	for (int i = 1; i <= m; i++) {
		scanf("%d", &start); scanf("%d", &end); scanf("%d", &cost);
		if (cost < W[start][end])
			W[start][end] = cost;
	}

	scanf("%d", &start); scanf("%d", &end); // �츮�� �ּ� ����� ã�� ���� ����, ���� ���ø� �Է� ����.


	dijkstra(n, start, end); //�� ������ dijkstra �Լ� ȣ��


	return 0;
}








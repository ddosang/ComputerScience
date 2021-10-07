#include <stdio.h>
//초기값을 미리 선언해둔다.
#define TRUE 1
#define FALSE 0
#define CITYMAX 1001 //도시의 값 한계점.
#define INF 987654321 //아주 큰 값.

int dist[CITYMAX]; // 출발지부터 i 도시까지의 최소 비용을 dist[i]에 저장
int isVisited[CITYMAX]; // 특정 정점이 방문 되었는지를 기록할 배열 isVisited
int W[CITYMAX][CITYMAX]; // 주어진 그래프(도시와 버스 노선)를 저장


//도시 개수 n, 시작 지점 start, 도착 지점 end를 입력하면
//시작 지점에서 도착 지점으로 가는 최소 비용을 printf로 출력해주는 함수.
void dijkstra(int n, int start, int end) { 
	//도시 개수와 출발 지점과 도착 지점을 입력 받는다.
	int i, u, w;

	for (i = 0; i < n; i++) {
		dist[i] = W[start][i]; //dist 배열을 시작 지점에서 각 정점까지의 거리로
		isVisited[i] = FALSE; //isVisited 배열은 도착한 적 없는 것으로
	} //초기화한다.


	dist[start] = 0; //시작 정점이므로 start에서 start 까지의 비용은 0

	for (int i = 1; i <= n; i++) { //n번 반복.

		int min = INF; //min 값 초기화

		// 버스 비용이 가장 적은 점을 찾는다.
		for (int j = 1; j <= n; j++) {
			if (!isVisited[j] && min > dist[j]) { 
				//j가 방문된 적 없는 정점이고, 
				//현재 min 값이 start에서 j까지 가는 비용보다 크면
				min = dist[j]; // min 값을 그 때의 비용으로
				start = j; //start를 그 점으로 갱신.
			}
		}

		isVisited[start] = TRUE; //위에서 바뀐 start 점에 방문 기록

		for (int u = 1; u <= n; u++) {
			if (W[start][u] != INF && dist[u] > dist[start] + W[start][u]) {
				dist[u] = dist[start] + W[start][u];
			}// 바뀐 start에 인접한 w 들의 dist를 재계산한다.
		}
	}

	printf("%d", dist[end]);
}



int main() {
	int n, m, start, end, cost;

	scanf("%d", &n);  scanf("%d", &m); //도시 개수와 버스 노선 개수 입력 받는다.


	//입력받은 도시 개수를 토대로 인접행렬을 초기화
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


	// 입력 값이 시작 도시, 도착 도시, 버스비 로 되어 있으므로 
	// 순서대로 입력 받고, 버스비가 현재 인접행렬 그래프에 저장된 값보다 작으면 
	// 인접행렬에 그 버스비를 저장한다.
	for (int i = 1; i <= m; i++) {
		scanf("%d", &start); scanf("%d", &end); scanf("%d", &cost);
		if (cost < W[start][end])
			W[start][end] = cost;
	}

	scanf("%d", &start); scanf("%d", &end); // 우리가 최소 비용을 찾을 시작 도시, 도착 도시를 입력 받음.


	dijkstra(n, start, end); //그 값으로 dijkstra 함수 호출


	return 0;
}








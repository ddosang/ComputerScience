import sys
import heapq
INF = 987654321 #미리 정해둔 큰 값.




def dijkstra():
    pq = [] #우선순위큐 pq (heap으로 구현)


    #출발점에서 목적지 i 까지의 거리를 dist[i]에 저장한다.
    dist = [INF for _ in range(V+1)]  #초기화
    dist[start] = 0  # 출발점부터 출발점까지의 거리는 0
    
    
    heapq.heappush(pq, [0, start]) #pq에 0, start를 삽입한다.


    while pq:
        cost, position = heapq.heappop(pq) #pq에서 pop 해서 나온 가중치와 목적지를 cost, pos에 저장
        #pop을 해서 나온 값이므로, 가중치가 가장 작은 것이 나온다.
        
        for c, p in W[position]: #W[position] : position를 출발점으로 하는 W 배열 값. (pos를 거쳐감)
              
            c += cost
            # W[position]의 가중치 값 c에 cost 값을 더한 것(position 점을 거쳐가는 것)과
            #현재까지 start에서 p까지 가는 가장 작은 값인 dist[p]값을 비교해서
            
            if dist[p] > c: #position를 거쳐가는 것의 가중치가 더 작은 경우
                dist[p] = c #dist 값을 더 작은 c값으로 수정하고,
                heapq.heappush(pq, [c, p]) #우선순위 큐에 그 값을 push한다.

    #pq가 빌 때 까지 반복



    #최단경로를 찾으면 출력한다.
    for i in range(1, V+1): 
        if dist[i] == INF:
            print("INF") 
        else:
            print(dist[i])




#main

V, E = map(int, sys.stdin.readline().split()) #정점, 간선 개수 입력 받음
start = int(input()) #출발점 입력 받음.

W = [[] for _ in range(V+1)] #[도착점, 출발점에서 도착점까지 가중치]를 저장할 W 배열을 만든다.



for _ in range(E): # 간선 정보 
    u, v, w = map(int, sys.stdin.readline().split()) # 출발점, 도착점, 가중치를 입력받아
    W[u].append([w, v])#W[출발점] 배열에 해당되는 어떤 출발점에 대한 모든
                        #[도착점, 출발점에서 도착점까지 가중치] 배열을 넣는다.
                    #가중치가 작은 것을 우선순위가 높은 것로 사용.


dijkstra() #알고리즘 호출

    


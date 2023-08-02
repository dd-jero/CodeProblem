import sys
INF = sys.maxsize # 최대 정수값 

def floyd():

    for mid in range(1,n+1): # 거치는 노드
        for start in range(1,n+1): # 시작 노드
            for end in range(1,n+1): # 도착 노드
                if dist[start][end] > dist[start][mid] + dist[mid][end]:
                    dist[start][end] = dist[start][mid] + dist[mid][end]

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

dist = [[INF]*(n+1) for _ in range(n+1)] # 최대 정수값으로 각 노드 간의 거리 초기화 

for _ in range(m):
    a,b,c = map(int,sys.stdin.readline().split())

    if dist[a][b] != INF: # 이미 노드 간의 거리가 존재하면 더 작은 값 저장
        if dist[a][b] > c:
            dist[a][b] = c
    else:
        dist[a][b] = c

floyd()

for i in range(1,n+1):
    for j in range(1,n+1):

        if i == j:
            print(0, end=" ")
        else:
            if dist[i][j] == INF:
                print(0,end=" ")
            else:
                print(dist[i][j], end=" ")
    
    print()


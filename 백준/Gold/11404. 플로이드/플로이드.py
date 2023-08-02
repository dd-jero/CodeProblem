import sys
INF = sys.maxsize

def floyd():

    for mid in range(1,n+1):
        for start in range(1,n+1):
            for end in range(1,n+1):
                if dist[start][end] > dist[start][mid] + dist[mid][end]:
                    dist[start][end] = dist[start][mid] + dist[mid][end]

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

dist = [[INF]*(n+1) for _ in range(n+1)]

for _ in range(m):
    a,b,c = map(int,sys.stdin.readline().split())

    if dist[a][b] != INF:
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


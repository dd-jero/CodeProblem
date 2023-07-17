import sys
from collections import deque

def solution(cur):

    q = deque()
    q.append(cur)
    visited[cur] = 1

    while q:
        temp = q.popleft()

        for i in range(1,n+1):
            if connected[temp][i] and not visited[i]:
                q.append(i)
                visited[i] = 1

def main():
    global visited, connected, n
    n,m = map(int,sys.stdin.readline().split())
    connected = [[0]*(n+1) for _ in range(n+1)]
    visited = [0]*(n+1)
    cnt = 0

    for _ in range(m):
        u,v = map(int,sys.stdin.readline().split())
        connected[u][v] = 1
        connected[v][u] = 1

    for i in range(1,n+1):
        for j in range(1,n+1):
            if connected[i][j] and not visited[i]:
                solution(i)
                cnt += 1
                
    for i in range(1, n+1): # 간선정보가 없는 노드는 단일 요소(연결 요소)로 포함해야함!
        if not visited[i]:
            cnt += 1

    print(cnt)

if __name__ == "__main__":
    main()
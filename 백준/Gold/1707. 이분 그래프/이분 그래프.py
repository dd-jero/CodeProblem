import sys
from collections import deque

def bfs(start):
    q = deque()
    q.append(start)
    visited[start] = 1 # 정점 1은 집합 1에 속함.

    while q:
        cur = q.popleft()

        for i in graph[cur]: # 인접 노드 확인 
            if not visited[i]: # 인접 노드에 방문하지 않았으면 큐 삽입, 집합 -1에 속함
                q.append(i)
                visited[i] = -1 * visited[cur]
            elif visited[i] == visited[cur]: # 인접 노드가 같은 집합이면 
                return False
    
    return True

k = int(sys.stdin.readline().strip())

for _ in range(k):
    v,e = map(int,sys.stdin.readline().strip().split()) # 정점 개수와 간선 개수 

    graph = [[] for _ in range(v+1)] # 그래프
    visited = [0]*(v+1) # 이분 그래프 확인 

    for _ in range(e):
        f,s = map(int,sys.stdin.readline().strip().split()) # 인접한 두 정점 
        # 무방향
        graph[f].append(s) 
        graph[s].append(f)

    for i in range(1,v+1):
        if not visited[i]:
            res = bfs(i)

            if not res:
                break

    print('YES' if res else 'NO')

    

import sys
from collections import deque

def solution():
    q = deque([1]) # 트리의 루트는 1
    visited = [0]*(n+1)
    visited[1] = 1

    while q:
        temp = q.popleft()
        
        for i in graph[temp]:
            if not visited[i]:
                parent[i] = temp
                q.append(i)
                visited[i] = 1

n = int(sys.stdin.readline())
graph = [[] for _ in range(n+1)]
parent = [0]*(n+1)

for _ in range(n-1):
    u,v = map(int,sys.stdin.readline().strip().split())
    graph[u].append(v)
    graph[v].append(u)

solution()

for i in range (2,n+1):
    print(parent[i])


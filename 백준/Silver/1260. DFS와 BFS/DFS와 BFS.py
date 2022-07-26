from collections import deque

def dfs(start):
    print(start, end = " ")
    visited1[start] = 1

    for i in range(1, n+1):
        if visited1[i] == 0 and s[start][i] == 1:
            dfs(i)

def bfs(start):
    visited2[start] = 1
    deq = deque()
    deq.append(start)

    while deq:
        node = deq.popleft()
        print(node, end=" ")

        for i in range(1,n+1):
            if visited2[i] == 0 and s[node][i] == 1:
                visited2[i] = 1
                deq.append(i)


n,m,v = map(int, input().split())
visited1 = [0 for _ in range(n+1)]
visited2 = [0 for _ in range(n+1)]
s = [[0]*(n+1) for _ in range(n+1)]

for i in range(m):
    x,y = map(int, input().split())
    s[x][y] = 1
    s[y][x] = 1

dfs(v)
print()
bfs(v)

import sys
from collections import deque

def solution(i,j):
    q = deque()
    q.append([i,j])
    visited[i][j] = True
    cnt = 1

    while q:
        x,y = q.popleft()

        for dx,dy in [(-1,0),(1,0),(0,1),(0,-1)]:
            nxt_x, nxt_y = x + dx, y + dy

            if 0<=nxt_x<m and 0<=nxt_y<n and not visited[nxt_x][nxt_y]:
                if region[nxt_x][nxt_y] == 0:
                    q.append([nxt_x,nxt_y])
                    visited[nxt_x][nxt_y] = True
                    cnt += 1
    return cnt

m,n,k = map(int,sys.stdin.readline().strip().split())
region = [[0]*n for _ in range(m)]
res = []

for _ in range(k):
    x1,y1,x2,y2 = map(int,sys.stdin.readline().strip().split())

    for i in range(x1,x2):
        for j in range(y1,y2):
            region[j][i] = -1

visited = [[False]*n for _ in range(m)]

for i in range(m):
    for j in range(n):
        if region[i][j] == 0 and not visited[i][j]:
            res.append(solution(i,j))

print(len(res))
print(*sorted(res))
import sys
from collections import deque

def solution(i,j):
    q = deque()
    q.append([i,j])
    visited[i][j] = True
    cnt = 1

    while q:

        x,y= q.popleft()

        for dx,dy in [(-1,0),(1,0),(0,1),(0,-1)]:
            nxt_x, nxt_y = x + dx, y + dy

            if 0<=nxt_x<n and 0<=nxt_y<m and not visited[nxt_x][nxt_y]:
                if paper[nxt_x][nxt_y] > 0:
                    q.append([nxt_x,nxt_y])
                    visited[nxt_x][nxt_y] = True
                    cnt += 1
                    
    return cnt

n,m = map(int,sys.stdin.readline().strip().split())
paper = [list(map(int,sys.stdin.readline().strip().split())) for _ in range(n)]
visited = [[False]*m for _ in range(n)]
res = []

for i in range(n):
    for j in range(m):
        if paper[i][j] == 1 and not visited[i][j]:
            res.append(solution(i,j))

if res:      
    print(len(res))
    print(max(res))
else:
    print(0)
    print(0)

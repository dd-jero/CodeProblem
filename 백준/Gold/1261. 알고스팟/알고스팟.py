import sys
from collections import deque
INF = sys.maxsize

def solution():
    q=deque()
    q.append([0,0])

    visited[0][0] = 0

    while q:
        x,y= q.popleft()

        if x == n-1 and y == m-1:
            return
        
        for dx,dy in dxy:
            nxt_x = x + dx
            nxt_y = y + dy

            if 0<=nxt_x<n and 0<=nxt_y<m:
                if visited[x][y] + int(miro[nxt_x][nxt_y]) < visited[nxt_x][nxt_y]:
                    visited[nxt_x][nxt_y] = visited[x][y] + int(miro[nxt_x][nxt_y]) 
                    if miro[nxt_x][nxt_y] == '0':
                        q.appendleft([nxt_x,nxt_y])
                    if miro[nxt_x][nxt_y] == '1':
                        q.append([nxt_x,nxt_y])
                        
   
m,n = map(int,sys.stdin.readline().split())
miro = [list(map(str,sys.stdin.readline().strip())) for _ in range(n)]

dxy = [(0,1),(1,0),(0,-1),(-1,0)]
visited = [[INF]*m for _ in range(n)]

solution()
print(visited[n-1][m-1])
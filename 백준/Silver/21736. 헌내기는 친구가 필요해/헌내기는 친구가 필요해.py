from sys import stdin
from collections import deque

def solution(i,j):
    global res
    q= deque()
    q.append([i,j])
    visited[i][j] = 1

    while q:
        x,y = q.popleft()

        for dx, dy in dxy:
            nxt_x = x + dx
            nxt_y = y + dy

            if 0<=nxt_x<n and 0<=nxt_y<m and not visited[nxt_x][nxt_y]:
                visited[nxt_x][nxt_y] = 1
                if campus[nxt_x][nxt_y] == "O":
                    q.append([nxt_x,nxt_y])
                elif campus[nxt_x][nxt_y] == "P":
                    q.append([nxt_x,nxt_y])
                    res += 1

    if res != 0:
        return res
    else:
        return "TT"

n,m = map(int,stdin.readline().split())
campus = [list(str(stdin.readline().strip())) for _ in range(n)]
visited = [[0]*m for _ in range(n)]
dxy = [(0,1),(1,0),(-1,0),(0,-1)]
res = 0

for i in range(n):
    for j in range(m):
        if campus[i][j] == "I":
            print(solution(i,j))
            exit()

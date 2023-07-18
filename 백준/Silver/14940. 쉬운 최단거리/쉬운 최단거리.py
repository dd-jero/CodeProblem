import sys
from collections import deque

def solution(i,j):

    q = deque()
    q.append([i,j])
    visited[i][j] = 1

    while q:
        x,y = q.popleft()

        for dx, dy in dxy:
            nxt_x = x + dx
            nxt_y = y + dy

            if 0 <= nxt_x < n and 0 <= nxt_y < m and not visited[nxt_x][nxt_y]:
                if map[nxt_x][nxt_y] != 0:
                    q.append([nxt_x, nxt_y])
                    visited[nxt_x][nxt_y] = 1
                    map[nxt_x][nxt_y] = map[x][y] + 1

def main():
    global visited,dxy,n,m,map

    n,m = map(int,sys.stdin.readline().split())
    map = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]
    visited = [[0]*m for _ in range(n)]

    dxy = [(0,-1),(-1,0),(1,0),(0,1)]

    for i in range(n):
        for j in range(m):
            if map[i][j] == 2:
                solution(i,j)
                break

    for i in range(n):
        for j in range(m):
            if not visited[i][j]:
                if map[i][j] == 0:
                    print(0, end = " ")
                else: 
                    print(-1, end = " ") 
            else:
                print(map[i][j]-2, end= " ")
        
        print()

if __name__ == "__main__":
    main()
import sys
from collections import deque
def min_path(i,j):
    deq = deque()
    visited[i][j] = 1
    deq.append([i,j])

    while deq:
        x,y = deq.popleft()
    
        for dx, dy in dxy:
            next_x = x + dx
            next_y = y + dy

            if 0 <= next_x < n and 0 <= next_y < m and maze[next_x][next_y] == 1:
                maze[next_x][next_y] = maze[x][y] + 1
                visited[next_x][next_y] = 1
                deq.append([next_x, next_y])

n,m = map(int, sys.stdin.readline().split())

maze = []
for i in range(n):
    maze.append(list(map(int,sys.stdin.readline().rstrip())))

visited = [[0]*m for _ in range(n)]
dxy = [[-1,0], [1,0], [0,-1], [0,1]]

min_path(0,0)
print(maze[n-1][m-1])

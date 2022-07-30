import sys
from collections import deque

def min_path(i,j):
    deq = deque()
    visited[i][j] = 1                                                                   # 방문 체크
    deq.append([i,j])                                                                   # 해당 좌표 deque에 추가

    while deq:
        x,y = deq.popleft()                                                             # deque의 제일 왼쪽 좌표 추출
    
        for dx, dy in dxy:                                                              # 상하 좌우 인접 좌표 확인
            next_x = x + dx
            next_y = y + dy

            if 0 <= next_x < n and 0 <= next_y < m and maze[next_x][next_y] == 1:       # 인접 좌표가 범위 안에 속하고 요소가 1일 때
                maze[next_x][next_y] = maze[x][y] + 1                                   # 인접 좌표의 요소를 해당 좌표 + 1 의 값으로 업데이트 
                visited[next_x][next_y] = 1                                             # 방문 체크 
                deq.append([next_x, next_y])

n,m = map(int, sys.stdin.readline().split())

maze = []
for i in range(n):
    maze.append(list(map(int,sys.stdin.readline().rstrip())))

visited = [[0]*m for _ in range(n)]
dxy = [[-1,0], [1,0], [0,-1], [0,1]]

min_path(0,0)
print(maze[n-1][m-1])                                                                   # 문제 상에서 미로의 끝은 [N,M]이므로 [0,0]부터 시작하는 것을 고려

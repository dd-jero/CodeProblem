from collections import deque
import sys

def find_space(i,j):
    visited[i][j] = 1                                                                               # 시작 좌표 방문 체크
    deq = deque()
    deq.append([i, j])                                                                              # 시작 좌표 deque에 추가

    while deq:                                                                                      # deque에 요소 존재 동안

        x,y = deq.popleft()                                                                         

        for dx,dy in dxy:                                                                           # 해당 좌표의 상하좌우 좌표 확인
            next_x = dx + x
            next_y = dy + y

            if 0 <= next_x < n and 0 <= next_y < n:                                                 # 인접 좌표가 picture에 속할 때
                if visited[next_x][next_y] == 0 and picture[x][y] == picture[next_x][next_y]:       # 해당 좌표의 인접 좌표를 방문하지 않았고 해당 좌표의 요소와 인접 좌표의 요소가 동일 하면 
                    visited[next_x][next_y] = 1                                                     # 인접 좌표 방문 체크
                    deq.append([next_x, next_y])                                                    # 인접 좌표 deque에 추가

dxy = [[1,0],[-1,0], [0,1], [0,-1]]
res = [0,0]
n = int(sys.stdin.readline())

picture = []
for i in range(n):
    picture.append(list(map(str, sys.stdin.readline())))

visited = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            find_space(i,j)
            res[0] += 1                                                                             # 적록색약이 아닐 때 결과

for i in range(n):                                                                                  # G를 R로 교체
    for j in range(n):
        if picture[i][j] == 'G':
            picture[i][j] = 'R'


visited = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            find_space(i,j)
            res[1] += 1                                                                             # 적록색약일 떄 

print(res[0], res[1])

from collections import deque
import sys

def count_min():
    while deq:
        x,y = deq.popleft()

        for dx,dy in dxy:                                                               # 해당 좌표의 인접(상하좌우) 좌표 확인
            next_x = x + dx
            next_y = y + dy

            if 0 <= next_x < n and 0 <= next_y < m and box[next_x][next_y] == 0:        # 인접 좌표가 box에 존재하고 익지 않은 토마토이면 
                
                box[next_x][next_y] = box[x][y] + 1                                     # 해당 좌표의 요소에 1을 더해 인접 좌표의 요소 데이트
                deq.append([next_x, next_y])                                            # 인접 좌표를 deque에 추가 

dxy = [[1,0], [-1,0], [0,-1], [0,1]]
box = []
res = 0
deq = deque()
m,n = map(int,sys.stdin.readline().split())
box = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]

for i in range(n):                                                                      # 함수 실행 전 익은 토마토의 좌표를 deque에 추가 
    for j in range(m):
        if box[i][j] == 1:
            deq.append([i,j])

count_min()

for row in box:                                                                         # 함수 실행 후 
    for element in row:
        if element == 0:                                                                # box에 익지 않은 토마토가 있으면 -1 출력
            print(-1)
            exit(0)                                                                     # 이중 for문 강제 종료

    res = max(res, max(row))                                                            # box에 익지 않은 토마토 없으면 res를 가장 큰 값으로 업데이트 

print(res-1)                                                                            # 첫 시작이 1(익은 토마토가 1)이기 때문에 최종 출력을 위해 1을 빼줌


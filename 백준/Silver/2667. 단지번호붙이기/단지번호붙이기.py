import sys
from collections import deque

def find_home(i,j):
    count = 1                                                                               
    deq = deque()
    deq.append([i,j])
    home[i][j] = 0

    while deq:
        
        x,y = deq.popleft()                                                                 # 이용하는 좌표 제거

        for dx, dy in dxy:                                                                  # 상하좌우 인접 좌표 확인
            
            next_x = x + dx
            next_y = y + dy

            if 0 <= next_x < n and 0 <= next_y < n and home[next_x][next_y] == 1:           # 인접 좌표가 범위 안에 존재하고 좌표의 요소가 1일 때 
                deq.append([next_x,next_y])                                                 # deque에 추가 (인접 좌표의 인접 좌표가 1일 수도 있어서)
                home[next_x][next_y] = 0                                                    # 인접 좌표의 요소를 0으로 바꿈
                count += 1                                                                  # 개수 1 증가

    return count

n = int(sys.stdin.readline())
dxy = [[0,-1],[1,0],[-1,0],[0,1]]
home = []
for i in range(n):
    home.append(list(map(int,sys.stdin.readline().rstrip())))

cnt = []                                                                                    # 단지 개수와 단지의 home 개수를 위한 리스트

for i in range(n):                                                                          # 이중 for문 이용
    for j in range(n):
        if home[i][j] == 1:                                                                 # 좌표의 요소가 1일 때
            cnt.append(find_home(i,j))                                                      # BFS 이용하여 home 개수를 구하고 리스트에 추가 
            
cnt.sort()                                                                                  # 오름차순으로 정렬          
print(len(cnt))                                                                             # 단지 개수 

for i in cnt:                                                                               # 단지의 home 개수
    print(i)

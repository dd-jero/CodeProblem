from collections import deque
import sys

def solution(i,j):

    queue = deque()
    queue.append([i,j])
    union_country = []
    union_country.append([i,j])
    visited[i][j] = 1

    while queue:
        x,y = queue.popleft()
        
        for dx, dy in dxy: # 해당 좌표의 상하좌우 좌표
            next_x = x + dx
            next_y = y + dy
            
            if 0 <= next_x < N and 0 <= next_y < N and not visited[next_x][next_y]:

                # 두 나라의 인구 차이를 만족하면 
                if abs(country[next_x][next_y] - country[x][y]) >= L and\
                abs(country[next_x][next_y] - country[x][y]) <= R:

                    # 연합
                    queue.append([next_x, next_y])
                    visited[next_x][next_y] = 1
                    union_country.append([next_x, next_y])

    return union_country

N,L,R = map(int, sys.stdin.readline().split())
country = []
dxy = [(-1,0), (0,-1), (1,0), (0,1)] # 해당 좌표에서 상하좌우 좌표 확인 위함
ans = 0 # 인구이동 발생 일수 

for i in range(N):
    country.append(list(map(int, sys.stdin.readline().split())))

while 1:
    visited = [[0 for _ in range(N)] for _ in range(N)] # 해당 좌표 방문 여부 
    move = 0

    for i in range(N):
        for j in range(N):
            if not visited[i][j]: # 여러 연합이 생길 수 있기 때문에 모든 나라를 순회

                union_country = solution(i,j) # 연합 목록 
            
                if len(union_country) > 1: # 연합국이 2개 이상이면 
                    move = 1 # 인구 이동 
                    population = sum(country[x][y] for x,y in union_country) // len(union_country) 

                    for x,y in union_country: # 연합국의 인구이동 
                        country[x][y] = population 
    
    # 전체 나라를 확인한 이후 
    if not move: # 더 이상 인구 이동이 발생하지 않는 것으로 판단하여 무한 루프 종료
        break
    else: # 인구 이동이 발생하면 일수 1 증가 
        ans += 1

print(ans)

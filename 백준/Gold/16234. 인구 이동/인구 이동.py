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
        
        for dx, dy in dxy:
            next_x = x + dx
            next_y = y + dy
            
            if 0 <= next_x < N and 0 <= next_y < N and not visited[next_x][next_y]:

                if abs(country[next_x][next_y] - country[x][y]) >= L and\
                abs(country[next_x][next_y] - country[x][y]) <= R:

                    queue.append([next_x, next_y])
                    visited[next_x][next_y] = 1
                    union_country.append([next_x, next_y])

    return union_country

N,L,R = map(int, sys.stdin.readline().split())
country = []
dxy = [(-1,0), (0,-1), (1,0), (0,1)]
ans = 0

for i in range(N):
    country.append(list(map(int, sys.stdin.readline().split())))

while 1:
    visited = [[0 for _ in range(N)] for _ in range(N)]
    move = 0

    for i in range(N):
        for j in range(N):
            if not visited[i][j]:

                union_country = solution(i,j)
            
                if len(union_country) > 1:
                    move = 1
                    population = sum(country[x][y] for x,y in union_country) // len(union_country)

                    for x,y in union_country:
                        country[x][y] = population
    
    if not move:
        break
    else:
        ans += 1

print(ans)
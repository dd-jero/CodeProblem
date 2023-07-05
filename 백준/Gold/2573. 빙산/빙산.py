import sys
from collections import deque

def solution(i,j):
    stack = deque()
    stack.append([i,j])
    visited[i][j] = 1

    while stack:
        x,y = stack.pop()
        zero_cnt = 0

        for dx, dy in dxy:
            next_x = x + dx
            next_y = y + dy

            if 0 <= next_x < N and 0 <= next_y < M and not visited[next_x][next_y]:
                if north[next_x][next_y] > 0:
                    stack.append([next_x,next_y])
                    visited[next_x][next_y] = 1

                if north[next_x][next_y] == 0:
                    zero_cnt += 1

        zero[x][y] = zero_cnt

N,M = map(int, sys.stdin.readline().split())

dxy = [(0,-1),(-1,0),(0,1),(1,0)]
year = 0
check = 0

north =[list(map(int,sys.stdin.readline().split())) for _ in range(N)]

while 1:
    visited = [[0 for _ in range(M)] for _ in range(N)]
    zero = [[0 for _ in range(M)] for _ in range(N)]
    union_cnt = 0

    for i in range(1, N-1):
        for j in range(1, M-1):
            if north[i][j] != 0 and not visited[i][j]:
                solution(i,j)
                union_cnt += 1
    
    for x in range(1,N-1):
        for y in range(1, M-1):
            north[x][y] = max(0,north[x][y]-zero[x][y]) 
            
            if north[x][y] > 0:
                check = 1

    if check == 0:
        print(0)
        exit()

    if union_cnt > 1:
        print(year)
        exit()
    elif union_cnt < 1:
        print(0)
        exit()
        
    year += 1

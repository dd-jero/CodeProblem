import sys
from collections import deque

# 가장자리는 무조건 0임을 이용
def cheese(i,j):
    q = deque()
    q.append((i,j))
    visited[i][j] = True

    while q:
        x,y = q.popleft()

        for dx,dy in dxy:
            nxt_x = x + dx
            nxt_y = y + dy

            if 0 <= nxt_x < n and 0 <= nxt_y < m:

                if arr[nxt_x][nxt_y] == 0 and not visited[nxt_x][nxt_y]: # 0이고 방문하지 않았을 때
                    q.append((nxt_x,nxt_y))
                    visited[nxt_x][nxt_y] = True
                
                elif arr[nxt_x][nxt_y] >= 1: 
                    if  in_air == 1:         # cheese가 첫 호출이라면 (외부 공기라면) => 두 번째 호출 부터는 치즈 내 공기
                        arr[nxt_x][nxt_y] += 1 # 방문 여부에 상관 없이 1를 더해줌 
    
    
n,m = map(int,sys.stdin.readline().strip().split())
arr = [list(map(int,sys.stdin.readline().strip().split())) for _ in range(n)]

dxy = [(0,1),(1,0),(0,-1),(-1,0)]
res = 0

while 1:

    visited = [[False]*m for _ in range(n)]
    in_air = 0
    check = False
    
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and arr[i][j] == 0: # 0에 대한 BFS
                in_air += 1
                cheese(i,j)

    for i in range(n):
        for j in range(m):
            if arr[i][j] >= 3: # 2개 이상 외부 공기에 접촉되어 있으면 
                arr[i][j] = 0
                check = True
            elif arr[i][j] == 2: # 1개만 접촉되어 있을 시 다시 1로
                arr[i][j] = 1
                check =  True

    if not check: # 치즈가 남아 있지 않을 때 
        print(res)
        break

    res += 1
import sys
from collections import deque

def bfs():
    q = deque()
    # z가 0이면 벽 부수기 가능, 1이면 벽 부수기 불가능 
    visited = [[[0]*2 for _ in range(m)] for _ in range(n)] # 3차원 행렬 이용

    q.append([0,0,0])
    visited[0][0][0] = 1

    while q:
        # print(q)
        x,y,check = q.popleft()
       
        if x == n-1 and y == m-1:
            return visited[x][y][check] # 목적지 도달 
        
        for dx, dy in dxy:
            nxt_x = x + dx
            nxt_y = y + dy

            if 0 <= nxt_x < n and 0 <= nxt_y < m:

                if arr[nxt_x][nxt_y] == '1' and check == 0: # 벽 부수기 가능할 때 다음 위치가 벽이면 
                    visited[nxt_x][nxt_y][1] = visited[x][y][0] + 1 # 벽 부수기 기회 소진, 1칸 이동
                    q.append([nxt_x,nxt_y,1])
                elif arr[nxt_x][nxt_y] == '0' and visited[nxt_x][nxt_y][check] == 0: # 다음 위치가 0이고 한번도 방문 안했을 때
                    visited[nxt_x][nxt_y][check] = visited[x][y][check] + 1 # 이전부터 가져온 z 유지, 1칸 이동
                    q.append([nxt_x,nxt_y,check]) 
                
    return -1 # 목적지 도달 못하면 -1 출력 

n,m = map(int,sys.stdin.readline().split())
arr = [list(str(sys.stdin.readline().strip())) for _ in range(n)]
dxy = [(1,0),(0,1),(-1,0),(0,-1)]

print(bfs())
import sys
from collections import deque
INF = sys.maxsize

# 0-1 BFS 활용 => 가중치가 0 또는 1일 때만 활용가능
# visited는 다익스트라의 dist 같은 형태
def solution():
    q=deque()
    q.append([0,0])

    visited[0][0] = 0

    while q:
        x,y= q.popleft()

        if x == n-1 and y == m-1: # 마지막 위치이면 종료 -> 가중치 0일 때는 큐의 앞에 삽입하여 최소 갯수 출력
            return
        
        for dx,dy in dxy:
            nxt_x = x + dx
            nxt_y = y + dy

            if 0<=nxt_x<n and 0<=nxt_y<m:
                if visited[x][y] + int(miro[nxt_x][nxt_y]) < visited[nxt_x][nxt_y]:
                    visited[nxt_x][nxt_y] = visited[x][y] + int(miro[nxt_x][nxt_y]) 

                    if miro[nxt_x][nxt_y] == '0': # 가중치 0일 때는 큐의 앞에 삽입
                        q.appendleft([nxt_x,nxt_y])
                    if miro[nxt_x][nxt_y] == '1': # 가중치 1일 때는 큐의 뒤에 삽입
                        q.append([nxt_x,nxt_y])
                        
   
m,n = map(int,sys.stdin.readline().split())
miro = [list(map(str,sys.stdin.readline().strip())) for _ in range(n)]

dxy = [(0,1),(1,0),(0,-1),(-1,0)]
visited = [[INF]*m for _ in range(n)]

solution()
print(visited[n-1][m-1])

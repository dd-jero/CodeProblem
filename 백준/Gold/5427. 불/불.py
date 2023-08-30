import sys
from collections import deque

def bfs():

    while q:
        x,y = q.popleft()
        
        if visited[x][y] != "F":
            tmp = visited[x][y]
        else:
            tmp = 'F'
        
        for dx,dy in dxy:
            nxt_x = x + dx
            nxt_y = y + dy

            if 0<=nxt_x<h and 0<=nxt_y<w :
                if visited[nxt_x][nxt_y] == -1 and (building[nxt_x][nxt_y] == '.' or building[nxt_x][nxt_y] == '@'):

                    if tmp == 'F':
                        visited[nxt_x][nxt_y] = 'F'
                    else:
                        visited[nxt_x][nxt_y] = tmp + 1

                    q.append((nxt_x,nxt_y))
            else:
                if tmp != 'F':
                    return tmp + 1
                
    return 'IMPOSSIBLE'


t = int(sys.stdin.readline().strip())
dxy = [(-1,0),(0,-1),(1,0),(0,1)]

for _ in range(t):
    w,h = map(int,sys.stdin.readline().strip().split())
    building = []
    visited = [[-1]*w for _ in range(h)]
    q = deque()

    for i in range(h):
        building.append(list(sys.stdin.readline().strip()))
        for j in range(w):
            if building[i][j] == "@":
                visited[i][j] = 0
                start = (i, j)
            elif building[i][j] == "*":
                visited[i][j] = "F"
                q.append((i, j))

    q.append(start)
    print(bfs())
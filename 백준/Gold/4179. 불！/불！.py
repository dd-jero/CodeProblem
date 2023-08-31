import sys
from collections import deque

def bfs():

    while q:
        x,y = q.popleft()

        if visited[x][y] == 'fire':
            flag = 'fire'
        else:
            flag = visited[x][y]

        for dx,dy in dxy:
            nxt_x = x + dx
            nxt_y = y + dy

            if 0<=nxt_x<r and 0<=nxt_y<c:
                if visited[nxt_x][nxt_y] == 0 and (miro[nxt_x][nxt_y] == 'J' or miro[nxt_x][nxt_y] == '.'):
                    if flag == 'fire':
                        visited[nxt_x][nxt_y] = flag
                    else:
                        visited[nxt_x][nxt_y] = flag + 1
                    q.append((nxt_x,nxt_y))
            else:
                if flag != 'fire':
                    return flag
                
    return 'IMPOSSIBLE'

r,c = map(int,sys.stdin.readline().strip().split())

q = deque()
miro = []
visited = [[0]*c for _ in range(r)]
dxy = [(1,0),(0,1),(-1,0),(0,-1)]

for i in range(r):
    miro.append(list(sys.stdin.readline().strip()))

    for j in range(c):

        if miro[i][j] == 'F':
            q.append((i,j))
            visited[i][j] = 'fire'

        elif miro[i][j] == 'J':
            start = (i,j)
            visited[i][j] = 1

q.append(start)
print(bfs())
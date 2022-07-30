from collections import deque
import sys

def count_min():
    
    while deq:
        z,x,y = deq.popleft()
        visited[z][x][y] = 1

        for dz,dx,dy in dxyz:
            next_x = x + dx
            next_y = y + dy
            next_z = z + dz

            if 0 <= next_x < n and 0 <= next_y < m and 0 <= next_z < h and box[next_z][next_x][next_y] == 0 and visited[next_z][next_x][next_y] == 0:
                
                box[next_z][next_x][next_y] = box[z][x][y] + 1 
                deq.append([next_z, next_x, next_y])
                visited[next_z][next_x][next_y] = 1

box = []
res = 0
deq = deque()
m,n,h = map(int,sys.stdin.readline().split())
box = [[list(map(int,sys.stdin.readline().split())) for _ in range(n)] for _ in range(h)]
dxyz = [[1,0,0], [-1,0,0], [0,-1,0], [0,1,0], [0,0,1], [0,0,-1]]
visited = [[[0]*m for _ in range(n)] for _ in range(h)]

for i in range(h):
    for j in range(n):
        for k in range(m):
            if box[i][j][k] == 1:
                deq.append([i,j,k])

count_min()

for plane in box:
    for row in plane:
        for element in row:
            if element == 0:
                print(-1)
                exit(0)

        res = max(res, max(row))

    

print(res-1)


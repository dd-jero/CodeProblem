from collections import deque
import sys

def count_min():
    while deq:
        x,y = deq.popleft()

        for dx,dy in dxy:
            next_x = x + dx
            next_y = y + dy

            if 0 <= next_x < n and 0 <= next_y < m and box[next_x][next_y] == 0:
                
                box[next_x][next_y] = box[x][y] + 1 
                deq.append([next_x, next_y])

dxy = [[1,0], [-1,0], [0,-1], [0,1]]
box = []
res = 0
deq = deque()
m,n = map(int,sys.stdin.readline().split())
box = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]

for i in range(n):
    for j in range(m):
        if box[i][j] == 1:
            deq.append([i,j])

count_min()

for row in box:
    for element in row:
        if element == 0:
            print(-1)
            exit(0)

    res = max(res, max(row))

print(res-1)


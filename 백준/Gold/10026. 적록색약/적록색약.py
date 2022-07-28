from collections import deque
import sys

def find_space(i,j):
    visited[i][j] = 1
    deq = deque()
    deq.append([i, j])

    while deq:

        x,y = deq.popleft()

        for dx,dy in dxy:
            next_x = dx + x
            next_y = dy + y

            if 0 <= next_x < n and 0 <= next_y < n:
                if visited[next_x][next_y] == 0 and picture[x][y] == picture[next_x][next_y]:
                    visited[next_x][next_y] = 1
                    deq.append([next_x, next_y])

dxy = [[1,0],[-1,0], [0,1], [0,-1]]
res = [0,0]
n = int(sys.stdin.readline())

picture = []
for i in range(n):
    picture.append(list(map(str, sys.stdin.readline())))

visited = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            find_space(i,j)
            res[0] += 1

for i in range(n):
    for j in range(n):
        if picture[i][j] == 'G':
            picture[i][j] = 'R'


visited = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            find_space(i,j)
            res[1] += 1

print(res[0], res[1])
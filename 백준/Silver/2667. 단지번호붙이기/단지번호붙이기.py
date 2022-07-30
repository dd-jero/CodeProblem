import sys
from collections import deque

def find_home(i,j):
    count = 1
    deq = deque()
    deq.append([i,j])
    home[i][j] = 0

    while deq:
        
        x,y = deq.popleft()

        for dx, dy in dxy:
            
            next_x = x + dx
            next_y = y + dy

            if 0 <= next_x < n and 0 <= next_y < n and home[next_x][next_y] == 1:
                deq.append([next_x,next_y])
                home[next_x][next_y] = 0
                count += 1

    return count

n = int(sys.stdin.readline())
dxy = [[0,-1],[1,0],[-1,0],[0,1]]
home = []
for i in range(n):
    home.append(list(map(int,sys.stdin.readline().rstrip())))

cnt = []

for i in range(n):
    for j in range(n):
        if home[i][j] == 1:
            cnt.append(find_home(i,j))
            
cnt.sort()
print(len(cnt))

for i in cnt:
    print(i)

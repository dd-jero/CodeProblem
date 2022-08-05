from collections import deque

def find_min(i,j):
    count = 1
    deq = deque()
    deq.append([i,j])

    while deq:
        r,c = deq.popleft()

        for dx, dy in dxy:
            nx = r + dx
            ny = c + dy

            if 0 <= nx < n and 0 <= ny < m and ground[nx][ny] == 1:
                deq.append([nx,ny])
                ground[nx][ny] = 0
                count += 1
    return count

t = int(input())

dxy = [[1,0], [-1,0],[0,1],[0,-1]]

for _ in range(t):
    cnt = []

    m,n,k = map(int,input().split())
    ground = [[0]*m for _ in range(n)]

    for _ in range(k):
        y,x = map(int,input().rstrip().split())
        ground[x][y] = 1


    for i in range(n):
        for j in range(m):
            if ground[i][j] == 1:
                cnt.append(find_min(i,j))
                
    print(len(cnt))
        
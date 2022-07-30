import sys

def dfs(start):
    global count
    visited[start] = 1

    for i in range(1, num_com+1):
        if visited[i] == 0 and connect[start][i] == 1:
            count += 1
            dfs(i)
    

num_com = int(sys.stdin.readline())
pair_com = int(sys.stdin.readline())
connect = [[0]*(num_com+1) for _ in range(num_com+1)]
visited =  [0 for _ in range(num_com+1)]
count = 0

for i in range(pair_com):
    x,y = map(int,sys.stdin.readline().split())
    connect[x][y] = 1
    connect[y][x] = 1

dfs(1)
print(count)
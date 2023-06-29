from collections import deque

def dfs(number, start):
    print(start, end = " ")  
    visited[start] = 1

    for i in range(1,number+1):
        if connected[start][i] == 1 and not visited[i]:
            dfs(number,i) 

def bfs(number, start):
    queue = deque()
    queue.append(start)
    visited2[start] = 1

    while queue:
        temp = queue.popleft()
        print(temp, end = " ")

        for i in range(1, number+1):
            if connected[temp][i] == 1 and not visited2[i]:
                queue.append(i)
                visited2[i] = 1


n,m,v = map(int, input().split())

connected = [[0]*(n+1) for _ in range(n+1)]
visited = [0 for _ in range(n+1)]
visited2 = [0 for _ in range(n+1)]

for _ in range(m):
    x,y = map(int, input().split())
    connected[x][y] = 1
    connected[y][x] = 1

dfs(n,v)
print()
bfs(n,v)


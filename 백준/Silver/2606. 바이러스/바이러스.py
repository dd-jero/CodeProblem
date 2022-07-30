import sys

def dfs(start):
    global count
    visited[start] = 1                                                  # 시작 node 방문 체크

    for i in range(1, num_com+1):                                                               
        if visited[i] == 0 and connect[start][i] == 1:                  # 해당 노드를 방문하지 않았고 연결되어 있는 컴퓨터라면               
            count += 1                                                  # 1 증가 
            dfs(i)                                                      # 해당 노드를 이용한 재귀 
    

num_com = int(sys.stdin.readline())                                     
pair_com = int(sys.stdin.readline())
connect = [[0]*(num_com+1) for _ in range(num_com+1)]                   # 컴퓨터 연결 확인을 위한 리스트 
visited =  [0 for _ in range(num_com+1)]                                # 해당 노드를 방문했는지 확인 리스트
count = 0

for i in range(pair_com):
    x,y = map(int,sys.stdin.readline().split())
    connect[x][y] = 1                                                   # 컴퓨터 연결 체크 
    connect[y][x] = 1

dfs(1)
print(count)

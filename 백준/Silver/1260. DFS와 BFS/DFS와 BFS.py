from collections import deque                           # deque 라이브러리를 이용하는 것이 성능 UP

def dfs(start):                                         # 깊이 우선 탐색
    print(start, end = " ")                             # 첫 node 출력
    visited1[start] = 1                                 # 방문 체크

    for i in range(1, n+1):                             
        if visited1[i] == 0 and s[start][i] == 1:       # 방문하지 않고 연결되어 있다면
            dfs(i)                                      # 재귀

def bfs(start):                                         # 너비 우선 탐색
    visited2[start] = 1
    deq = deque()                                       # deque 정의
    deq.append(start)                                   # deque에 node 추가 

    while deq:                                          # deque에 node가 있을 동안 
        node = deq.popleft()                            # 제일 왼쪽의 node를 제거하고 추출 후 출력 
        print(node, end=" ")

        for i in range(1,n+1):
            if visited2[i] == 0 and s[node][i] == 1:
                visited2[i] = 1
                deq.append(i)


n,m,v = map(int, input().split())
visited1 = [0 for _ in range(n+1)]
visited2 = [0 for _ in range(n+1)]
s = [[0]*(n+1) for _ in range(n+1)]

for i in range(m):
    x,y = map(int, input().split())
    s[x][y] = 1                                             # 이중 리스트의 index를 이용하여 node 간의 연결 구성
    s[y][x] = 1

dfs(v)
print()
bfs(v)

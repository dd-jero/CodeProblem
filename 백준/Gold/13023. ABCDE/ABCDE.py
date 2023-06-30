import sys

def solution(n, depth):
    
    global ans
    
    if depth == 4: # depth가  4면 함수 종료 
        ans = 1
        return 
    
    visited[n] = 1 # 현재 정점인 n 방문 
    
    for next in adj[n]: # n의 인접 정접을 차례로 방문하기 위함
        if not visited[next]: # 인접 정점을 방문하지 않았으면 
            solution(next, depth+1) # 재귀 호출(인접 정점을 현재 정점으로 하고  depth 1 증가)
            visited[next] = 0 # 재귀 종료되었을 때 해당 정점의 방문 여부를 되돌려 놓아야 다시 방문가능 

n,m = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(n)] # 각 정점의 인정정점을 저장할 리스트
ans = 0 # 출력 결정

for _ in range(m):
    a,b = map(int, sys.stdin.readline().split())
    adj[a].append(b)
    adj[b].append(a)

for i in range(n):
    depth = 0
    visited= [0 for _ in range(n)] # 방문 여부
    
    solution(i, depth)
    
    if ans == 1:    # depth가 4면 1을 출력하고 프로그램 종료
        print(1)
        exit()

    
print(0)

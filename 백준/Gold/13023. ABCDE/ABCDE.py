import sys

def solution(n, depth):
    
    global ans
    
    if depth == 4:
        ans = 1
        return 
    
    visited[n] = 1
    
    for next in adj[n]:
        if not visited[next]:
            solution(next, depth+1)
            visited[next] = 0

n,m = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(n)]
ans = 0

for _ in range(m):
    a,b = map(int, sys.stdin.readline().split())
    adj[a].append(b)
    adj[b].append(a)

for i in range(n):
    depth = 0
    visited= [0 for _ in range(n)]
    
    solution(i, depth)
    
    if ans == 1:
        print(1)
        exit()

    
print(0)
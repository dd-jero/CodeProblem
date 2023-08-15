import sys
from collections import deque

def solution(k,v,graph,visited):
    cnt = 0
    q = deque()
    q.append(v)
    visited[v] = True

    while q:
        cur_v = q.popleft()

        for i in graph[cur_v]:
            if not visited[i[0]]:
                if i[1] >= k:
                    q.append(i[0])
                    visited[i[0]] = True
                    cnt += 1
    
    return cnt

def main():
    N, Q = map(int,sys.stdin.readline().rstrip().split())
    graph = {i: [] for i in range(1,N+1)}

    for _ in range(N-1):
        p, q, r = map(int,sys.stdin.readline().rstrip().split())
        graph[p].append((q,r)) # 일반 리스트를 이용하면 시간 초과, 딕셔너리 이용
        graph[q].append((p,r))

    for _ in range(Q):
        visited = [False]*(N+1)
        k, v = map(int,sys.stdin.readline().rstrip().split())
        print(solution(k,v,graph,visited))

if __name__ == "__main__":
    main()

import sys
from collections import deque

def solution(n,k):
    queue = deque()
    queue.append([n,0])

    while queue:
        pos,cnt = queue.popleft()

        if pos == k:
            return cnt

        for i in range(3):
            if i == 0:
                nxt_pos = pos * d[i]
                if  0 <= nxt_pos <= 100000 and not visited[nxt_pos]:
                    queue.append([nxt_pos,cnt])
                    visited[nxt_pos] = 1
            elif i == 1:
                nxt_pos = pos + d[i]
                if  0 <= nxt_pos  and not visited[nxt_pos]:
                    queue.append([nxt_pos,cnt+1])
                    visited[nxt_pos] = 1
            else:
                nxt_pos = pos + d[i]
                if nxt_pos <= k and not visited[nxt_pos]:
                    queue.append([nxt_pos,cnt+1])
                    visited[nxt_pos] = 1
                

n,k = map(int,sys.stdin.readline().split())
visited = [0]*100001
d = [2,-1,1]

print(solution(n,k))


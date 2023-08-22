import sys
from collections import deque

def solution(src, dest):

    q = deque()
    q.append(src)

    while q:
        x= q.popleft()
        
        if x == dest:   
            return 
        
        for nxt_x in (x+1,x-1,x*2):

            if 0 <= nxt_x < 100001 and dist[nxt_x] == 0:
                q.append(nxt_x)
                dist[nxt_x] = dist[x] + 1 
                move[nxt_x] = x

n,k = map(int,sys.stdin.readline().strip().split())

dist = [0]*100001
move = [0]*100001
solution(n,k)

res = [k,]

for i in range(dist[k]):
    res.append(move[k])
    k = move[k]


print(len(res)-1)
print(" ".join(map(str,reversed(res))))
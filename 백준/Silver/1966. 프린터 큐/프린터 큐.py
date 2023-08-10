import sys
from collections import deque

def solution(li):
    global res
    q = deque(li)

    while q: 
        cur_max = max(q,key=lambda x: x[1])
        cur_idx, cur_val = q.popleft()

        if cur_val < cur_max[1]:
            q.append((cur_idx,cur_val))

        elif cur_val == cur_max[1]:
            if cur_idx != m:
                res += 1
            else:   
                res += 1
                return res

t = int(sys.stdin.readline())

for _ in range(t):
    res = 0
    n,m = map(int,sys.stdin.readline().split())
    q = list(map(int,sys.stdin.readline().split()))

    re_q = []
    for idx, val in enumerate(q):
        re_q.append((idx,val))

    print(solution(re_q))
    
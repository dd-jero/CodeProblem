import sys
from collections import deque

def solution(cnt, a):
    q = deque()
    q.append([cnt,a])

    while q:
        cur_cnt, cur_a = q.popleft()

        if cur_a == b:
            print(cur_cnt)
            exit()
        elif cur_a > b:
            continue
        else:
            q.append([cur_cnt+1, cur_a*2])
            q.append([cur_cnt+1, int(str(cur_a)+ str(1))])

    print(-1)

a,b = map(int,sys.stdin.readline().split())
solution(1,a)

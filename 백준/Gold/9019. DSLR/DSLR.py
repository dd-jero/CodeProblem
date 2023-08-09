import sys
from collections import deque

def solution(initial,command):
    q = deque()

    q.append((initial,command))
    visited[initial] = True

    while q:
        cur_reg, cur_com = q.popleft()

        if cur_reg == final_reg:
            return cur_com
        
        nxt_reg = (cur_reg << 1) % 10000 # 비트연산: 곱하기 2
        if visited[nxt_reg] == False:
            q.append((nxt_reg, cur_com + 'D'))
            visited[nxt_reg] = True
        
        nxt_reg = (cur_reg - 1) % 10000 # -1 % 10000 = 9999 ==> 파이썬 나머지 연산은 음수가 되지 않게 조정
        if visited[nxt_reg] == False:
            q.append((nxt_reg, cur_com + 'S'))
            visited[nxt_reg] = True

        nxt_reg = (cur_reg % 1000)*10 + (cur_reg//1000)
        if visited[nxt_reg] == False:
            q.append((nxt_reg, cur_com + 'L'))
            visited[nxt_reg] = True

        nxt_reg = (cur_reg % 10)*1000 + (cur_reg//10)
        if visited[nxt_reg] == False:
            q.append((nxt_reg, cur_com + 'R'))
            visited[nxt_reg] = True

t = int(sys.stdin.readline())

for _ in range(t):
    visited = [False]*10000
    initial_reg, final_reg = map(int,sys.stdin.readline().split())

    print(solution(initial_reg, ""))
import sys
from collections import deque

def bfs():
    q = deque()
    q.append([1,0,0])
    visited[1][0]= True
    while q:
        cur_num, copy, time= q.popleft()
        
        if cur_num == s:
            return time
    
        for c in commands:
            if c == 2:
                if not visited[cur_num+copy][copy] and copy != 0:
                    q.append([cur_num+copy,copy,time+1])
                    visited[cur_num+copy][copy] = True
            elif c == -1:
                if cur_num+c >= 0:
                    if not visited[cur_num+c][copy]:
                        q.append([cur_num+c,copy,time+1])
                        visited[cur_num+c][copy] = True
            elif c == 1:
                tmp_copy = cur_num
                if not visited[cur_num][tmp_copy] and copy != cur_num:
                    q.append([cur_num,tmp_copy,time+1])
                    visited[cur_num][tmp_copy] = True
                    
s = int(sys.stdin.readline().strip())
commands = [2,1,-1]
visited = [[False]*10001 for _ in range(10001)]
print(bfs())
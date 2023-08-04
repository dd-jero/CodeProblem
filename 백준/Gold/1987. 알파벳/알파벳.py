import sys

def solution():
    global res

    queue = set()

    queue.add((0,0,al[0][0]))

    while queue:

        x,y,path = queue.pop()
        res = max(res,len(path))

        for i in range(4):
            nxt_x=x+dx[i]
            nxt_y=y+dy[i]

            if 0<=nxt_x<r and 0<=nxt_y<c and al[nxt_x][nxt_y] not in path:
                queue.add((nxt_x,nxt_y,path+al[nxt_x][nxt_y]))
                

r,c = map(int,sys.stdin.readline().split())
al = [list(sys.stdin.readline().strip()) for _ in range(r)]

dx = [0,0,1,-1]
dy = [-1,1,0,0]
res = 1

solution()

print(res)

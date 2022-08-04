from collections import deque
n,m = map(int, input().split())
board = [list(map(str,input())) for _ in range(n)]
res = []

for a in range(n-7):
    for b in range(m-7):
        w_count = 0
        b_count = 0
        for i in range(a,a+8):
            for j in range(b,b+8):
                if (i+j) % 2 == 0: 
                    if board[i][j] != 'W':
                        w_count += 1
                    elif board[i][j] != 'B':
                        b_count += 1
                else:
                    if board[i][j] != 'B':
                        w_count += 1
                    elif board[i][j] != 'W':
                        b_count += 1    

        res.append(min(w_count, b_count))

print(min(res))

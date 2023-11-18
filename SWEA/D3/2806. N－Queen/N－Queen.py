def dfs(row):
    global res

    if row == N:
        res += 1
        return

    for i in range(N):
        if v1[i] == v2[row+i] == v3[row-i] == 0:
            
            v1[i] = v2[row+i] = v3[row-i] = 1
            dfs(row+1)
            v1[i] = v2[row + i] = v3[row - i] = 0

T = int(input())

for tc in range(1, T+1):
    N = int(input())
    res = 0
    v1,v2,v3 = [[0]*(N*2) for _ in range(3)]

    dfs(0) # 행번호

    print(f"#{tc} {res}")

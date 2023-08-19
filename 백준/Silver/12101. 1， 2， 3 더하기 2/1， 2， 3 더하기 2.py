import sys

def solution(n,k):
    global cnt

    if sum(res) >= n:
        if sum(res) == n:
            cnt += 1
            if cnt == k:
                print("+".join(map(str,res)))
        return

    for i in range(1,4):
        res.append(i)
        solution(n,k)
        res.pop()

    if not res and cnt < k:
        print(-1)

n,k = map(int,sys.stdin.readline().strip().split())

res= [] 
cnt = 0
solution(n,k)

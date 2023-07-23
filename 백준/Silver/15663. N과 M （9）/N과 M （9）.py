import sys

def solution(cnt,n,m):
    if cnt == m:
        print(' '.join(map(str,res)))
        return
    
    tmp = 0

    for i in range(n):
        if not visited[i] and tmp != numbers[i]: # 중복 수열을 만들지 않게 하기 위해
            visited[i] = 1
            res.append(numbers[i])
            tmp = numbers[i]

            solution(cnt+1,n,m)
            visited[i] = 0
            res.pop()

n,m = map(int,sys.stdin.readline().split())
numbers = list(map(int,sys.stdin.readline().split()))
numbers = sorted(numbers)
visited = [0]*n
res = []

solution(0,n,m)

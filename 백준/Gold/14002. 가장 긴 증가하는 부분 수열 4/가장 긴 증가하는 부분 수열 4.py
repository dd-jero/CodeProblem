import sys
import bisect

def solution(numbers):
    dp = [1]*n
    for i in range(n):
        for j in range(i):
            if numbers[i] > numbers[j]:
                dp[i] = max(dp[j]+1,dp[i])
        
    max_len = max(dp)
    idx = dp.index(max_len)

    li = []

    for i in range(idx,-1,-1):
        if dp[i] == max_len:
            li.append(numbers[i])
            max_len-=1
    
    li.reverse()
    return li

n = int(sys.stdin.readline())
numbers = list(map(int, sys.stdin.readline().strip().split()))
res = solution(numbers)

print(len(res))
print(*res)
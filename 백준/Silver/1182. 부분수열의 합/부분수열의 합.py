import sys
from itertools import combinations                                          # 조합을 이용한 부분수열의 합을 구현

res = 0

n,s = map(int, sys.stdin.readline().rstrip().split())
li = list(map(int, sys.stdin.readline().rstrip().split()))

for i in range(1, n+1):                                                     # 1개부터 N개의 요소를 가진 부분수열을 구하기 위한 반복문
    for j in list(combinations(li,i)):                                      # 조합 이용
        if sum(j) == s:                                                     # 부분수열으 합이 S와 같으면 츨력 값 1 증가 
            res += 1

print(res)

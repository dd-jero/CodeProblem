import sys
from itertools import combinations

res = 0

n,s = map(int, sys.stdin.readline().rstrip().split())
li = list(map(int, sys.stdin.readline().rstrip().split()))

for i in range(1, n+1):
    for j in list(combinations(li,i)):
        if sum(j) == s:
            res += 1

print(res)
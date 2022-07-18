import sys
from itertools import combinations, permutations

n,m = map(int, sys.stdin.readline().split())

list_n = sorted(list(map(int, sys.stdin.readline().split())))

for p in combinations(list_n, m):
    print(*p)

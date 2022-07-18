import sys
from itertools import permutations

n,m = map(int, sys.stdin.readline().split())

list_n = sorted(list(map(int, sys.stdin.readline().split())))

for p in permutations(list_n, m):
    print(*p)

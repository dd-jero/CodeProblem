import sys
from itertools import combinations, permutations, product

n,m = map(int, sys.stdin.readline().split())

list_n = sorted(list(map(int, sys.stdin.readline().split())))

for p in product(list_n, repeat = m):
    print(*p)

import sys
from itertools import combinations, permutations, product, combinations_with_replacement

n,m = map(int, sys.stdin.readline().split())

list_n = sorted(list(map(int, sys.stdin.readline().split())))

for p in combinations_with_replacement(list_n, m):
    print(*p)

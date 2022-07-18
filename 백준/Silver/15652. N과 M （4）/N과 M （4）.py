import sys
import itertools

n,m = sys.stdin.readline().split()
n = int(n)
m = int(m)

list_n = [str(i) for i in range(1,n+1)]
res = (list(map(' '.join,itertools.combinations_with_replacement(list_n, m))))

for i in res:
    print(i)
import sys

n,m = map(int,sys.stdin.readline().strip().split())
A = {}
for _ in range(n):
   A[sys.stdin.readline().strip()] = 0

B = [str(sys.stdin.readline().strip()) for _ in range(m)]

res = 0
for i in B:
    if i in A:
        A[i] += 1

for i in A:
    res += A[i]

print(res)
import sys

n,m = map(int,sys.stdin.readline().split())
num = [0] + list(map(int,sys.stdin.readline().split()))
sum_list = [0] + [0]*n

for i in range(1, n+1):
    sum_list[i] = sum_list[i-1] + num[i]

for _ in range(m):
    start,end = map(int,sys.stdin.readline().split())

    print(sum_list[end] - sum_list[start-1])

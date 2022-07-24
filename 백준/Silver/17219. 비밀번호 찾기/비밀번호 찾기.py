import sys
n,m = map(int, sys.stdin.readline().split())
list_sp = {}
list_ans =[]


for i in range(n):
    site, password = sys.stdin.readline().split()
    list_sp[site] = password

for _ in range(m):
    list_ans.append(list_sp[input().rstrip()])

for i in list_ans:
    print(i)
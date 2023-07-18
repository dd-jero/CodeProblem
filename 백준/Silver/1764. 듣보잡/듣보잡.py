import sys 

n,m = map(int,sys.stdin.readline().split())
name = {}
not_list = []

for _ in range(n+m):
    n = str(input())

    if n in name:
        name[n] += 1
    else:
        name[n] = 1

for i in name:
    if name[i] == 2:
        not_list.append(i)

not_list.sort()

print(len(not_list))

for i in not_list:
    print(i)
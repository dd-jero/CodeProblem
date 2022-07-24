n = int(input())
list_time = list(map(int,input().split()))
list_time = sorted(list_time)
all_time = 0
res = 0
for i in range(n):
    all_time += list_time[i]
    res += all_time

print(res)
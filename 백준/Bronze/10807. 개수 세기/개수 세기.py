n = int(input())
list_n = list(map(int, input().split()))
v = int(input())
cnt = 0

for i in list_n:
    if i == v:
        cnt+=1

print(cnt)
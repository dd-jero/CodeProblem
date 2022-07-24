n = int(input())
list_time = list(map(int,input().split()))
list_time = sorted(list_time)                   # sorted를 통해 시간을 오름차순으로 정렬
all_time = 0                                    # 각 사람이 돈을 인출하는데 필요한 시간
res = 0                                         # 누적 합
for i in range(n):
    all_time += list_time[i]
    res += all_time

print(res)

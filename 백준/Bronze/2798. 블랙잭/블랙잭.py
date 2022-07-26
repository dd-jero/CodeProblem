from itertools import combinations
n,m = map(int, input().split())
list_num = list(map(int, input().split()))

res = 0
list_sum = []

for i in combinations(list_num, 3):
    sum_val = [*i]
    if sum(sum_val) <= m and res < sum(sum_val):
        res = sum(sum_val)

print(res)

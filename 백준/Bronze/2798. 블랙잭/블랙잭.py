from itertools import combinations                      # 조합을 이용한 간단한 문제
n,m = map(int, input().split())
list_num = list(map(int, input().split()))

res = 0

for i in combinations(list_num, 3):                     # i는 list_num에서의 3가지를 요소로 가지는 튜플 (조합)
    if sum(i) <= m and res < sum(i):                    # sum함수를 이용해서 각 조합의 합을 구하고 M보다 작으며 가장 근접한 값을 구함
        res = sum(i)

print(res)

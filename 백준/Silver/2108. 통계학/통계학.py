import sys

dic = {}
li = []
sum_num = 0

n = int(sys.stdin.readline())

for _ in range(n):
    number = int(sys.stdin.readline())
    li.append(number)
    if number in dic:
        dic[number] += 1
    else:
        dic[number] = 1

sorted_dic = sorted(dic)
li = sorted(li)

for k in sorted_dic:
    sum_num += k * dic[k]

print(round(sum_num/n)) # 두 번째 인자를 비워서 소수점 이하 첫째 자리에서 반올림
print(li[n//2]) # 중앙값

max_cnt = sorted([k for k,v in dic.items() if max(dic.values()) == v])
if len(max_cnt) == 1:
    num = max_cnt[0]
else:
    num = max_cnt[1]

print(num) # 최빈값
print(sorted_dic[-1] - sorted_dic[0]) # 범위 
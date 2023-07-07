import sys
N = int(sys.stdin.readline())
num = list(map(int, sys.stdin.readline().split()))
sorted_num = sorted(list(set(num))) # 중복 제거 후 오름차순 정렬 -> 해당 인덱스가 좌표 압축 결과임

dic_num = {}
for i in range(len(sorted_num)):
    dic_num[sorted_num[i]] = i

for i in range(len(num)):
    print(dic_num[num[i]], end=" ")
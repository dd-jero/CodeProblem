# 이중 for문을 이용하면 무조건 시간초과 -> 딕셔너리를 이용 (Key를 site, Value를 Password)
import sys
n,m = map(int, sys.stdin.readline().split())
list_sp = {}
list_ans =[]


for i in range(n):
    site, password = sys.stdin.readline().split()
    list_sp[site] = password

for _ in range(m):
    list_ans.append(list_sp[sys.stdin.readline().rstrip()]) # 입력 받을 때 입력 끝에 개행 문자가 포함되어 rstrip 함수로 제거

for i in list_ans:
    print(i)

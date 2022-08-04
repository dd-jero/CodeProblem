import sys

n = int(sys.stdin.readline())
own = list(map(int,sys.stdin.readline().split()))
m = int(sys.stdin.readline())
num = list(map(int,sys.stdin.readline().split()))

count = {}

for i in own:
    if i in count:
        count[i] += 1
    else:                                               # 딕셔너리에 없으면 value를 1로 가지는 key 값 생성
        count[i] = 1

for i in num:
    res = count.get(i)                                  # 출력하고자 하는 key의 value 값을 추출

    if res == None:                                     # num에 없으면 0 출력
        print(0, end = " ") 
    else:                                               # num에 있으면 value 출력
        print(res, end = " ")

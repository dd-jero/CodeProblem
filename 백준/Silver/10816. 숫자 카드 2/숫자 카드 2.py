import sys

n = int(sys.stdin.readline())
own = list(map(int,sys.stdin.readline().split()))
m = int(sys.stdin.readline())
num = list(map(int,sys.stdin.readline().split()))

count = {}

for i in own:
    if i in count:
        count[i] += 1
    else:
        count[i] = 1

for i in num:
    res = count.get(i)

    if res == None:
        print(0, end = " ")
    else:
        print(res, end = " ")

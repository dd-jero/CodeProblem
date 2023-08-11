import sys

n = int(sys.stdin.readline())
cnt = 0
tmp = 665

while n != cnt:

    tmp += 1

    if '666' in str(tmp):
        cnt += 1

print(tmp)
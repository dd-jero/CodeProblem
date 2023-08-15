import sys

word = str(sys.stdin.readline().strip())

if word == word[::-1]: # [시작:끝:규칙]
    print(1)
else:
    print(0)

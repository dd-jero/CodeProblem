import sys

N = int(sys.stdin.readline())

if N >= 6:
    num = N % 6

    if num == 1 or num == 3 or num == 5:
        sys.stdout.write("SK")
    else:
        sys.stdout.write("CY")

else:
    num = N % 2

    if num == 1:
        sys.stdout.write("SK")
    else:
        sys.stdout.write("CY")
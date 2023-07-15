import sys

def solution(a,b,c):
    if b == 1:
        return a % c
    else:
        temp = solution(a,b>>1,c)
        if b%2==0: return (temp*temp) % c
        else: return (temp*temp*a) % c

a,b,c = map(int,sys.stdin.readline().split())

sys.stdout.write(str(solution(a,b,c)))
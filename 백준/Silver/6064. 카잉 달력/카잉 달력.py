import sys

def calender(M,N,x,y):
    
    if(y == N):
        y = 0

    for i in range(M*N):
        result = -1

        if (((M*i+x) % N) == y):
            result = M*i+x
            break

        if (M*i+x) > (M*N):
            break

    return result

num = int(sys.stdin.readline())

for i in range(num):

    M, N, x, y = sys.stdin.readline().split(" ")
    M = int(M)
    N = int(N)
    x = int(x)
    y = int(y)
    print(calender(M,N,x,y))



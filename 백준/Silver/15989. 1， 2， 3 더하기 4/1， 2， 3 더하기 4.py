import sys

def dp():
    num = int(sys.stdin.readline())

    for _ in range(num):
        n = int(sys.stdin.readline())
        dp_list = [0,1,2,3] 
        
        for j in range(4, n+1):
            dp_list.append(dp_list[j-3] + j//2 + 1)

        print(dp_list[n])



dp()

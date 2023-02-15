def solution(n):
    answer = 0
    
    li = [0,1] + [0 for i in range(2,100000+1)]
    
    for i in range(100000-1):
        li[i+2] = li[i] + li[i+1]

    return (li[n]%1234567)
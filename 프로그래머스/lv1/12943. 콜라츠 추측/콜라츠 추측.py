def solution(num):
    cnt = 0
    while(1):
        if num == 1:
            return 0
        elif num % 2 == 0:
            num = num // 2
        else:
            num = num * 3 + 1
        
        cnt += 1
        
        if num == 1:
            return cnt
        
        if cnt == 500:
            return -1

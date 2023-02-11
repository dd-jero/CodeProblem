def solution(s):

    
    zero_cnt = 0
    iteration = 0
    
    
    while(1):
        re_len = len(s) - s.count('0')
        zero_cnt += s.count('0')
        s = str(bin(re_len)[2:])
        iteration += 1
        
        if s == '1':
            break
            
    return iteration, zero_cnt
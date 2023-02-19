def solution(n):
    answer = ''
    while(1):
        modulus = str(n % 3)
        n = n // 3
        
        answer += modulus
        
        if modulus == '0' and n == 0:
            break
    return int(answer[:-1],3)
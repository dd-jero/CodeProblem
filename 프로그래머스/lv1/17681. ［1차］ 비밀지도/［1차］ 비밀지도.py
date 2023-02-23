def binary(li, cnt):
    res = []
    
    for num in li:
        
        temp = ''
        while(1):
            t = num % 2
            num = num // 2
            temp += str(t)
        
            if num == 0:
                break
                
        if len(temp) < cnt:
            temp += '0'*(cnt-len(temp))
            res.append(temp[::-1])
        else:
            res.append(temp[::-1])
            
    return res

def solution(n, arr1, arr2):
    answer = []

    b1 = binary(arr1,n)
    b2 = binary(arr2,n)
    
    for n11, n12 in zip(b1,b2):
        t = ''
        for n21, n22 in zip(n11, n12):
            
            if n21 == '1' or n22 == '1':
                t += '#'
            elif n21 == '0' and n22 == '0':
                t += " "
        answer.append(t)        
            
    return answer


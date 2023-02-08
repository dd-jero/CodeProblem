def solution(arr):
    stack = []
    answer = [arr[0]]
    
    for num in arr:
        if stack:
            a = stack.pop()
            
            if a != num:
                answer.append(num)
                
        stack.append(num)
        
    return answer
            
    
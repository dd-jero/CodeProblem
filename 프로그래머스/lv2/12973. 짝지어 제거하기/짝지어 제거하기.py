def solution(s):
    
    stack = []
    
    for al in s:
        stack.append(al)
        if  len(stack) > 1:
            if  stack[-1] ==  stack[-2]:
                del stack[-2:]
                
    if stack:
        return 0
    else:
        return 1
            
            

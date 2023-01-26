def solution(citations):
    answer = 0
    
    for i, n in enumerate(sorted(citations, reverse=True)):
        
        if i >= n:
            return i
        
    return len(citations)

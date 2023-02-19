def solution(a, b):
    if a>b:
        big, small = a, b
    else:
        big, small = b, a
    answer = sum([i for i in range(small,big+1)])
    return answer
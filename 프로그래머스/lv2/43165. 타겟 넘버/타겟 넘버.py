def solution(numbers, target):
    if not numbers:
        if target == 0: return 1
        else: return 0
    
    answer = 0
    number = numbers.pop()
    answer += solution(numbers, target+number)
    answer += solution(numbers, target-number)
    numbers.append(number)

    return answer
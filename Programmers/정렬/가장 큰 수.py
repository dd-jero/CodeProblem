def solution(numbers):
    answer = ''
    
    numbers = list(map(str,numbers))
    
    for i in sorted(numbers,key=lambda x: x*4, reverse=True):
        answer += i
    
    return str(int(answer))   # int 변환 후 다시 str로 바꾸는 이유 이미 원소들이 str형이기 때문에 모든 원소가 0이면 "0000"으로 리턴됨 => "0"으로 리턴 되어야 하기 
  
# 0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.
# 예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.
# 0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.
# 제한 사항
# numbers의 길이는 1 이상 100,000 이하입니다.
# numbers의 원소는 0 이상 1,000 이하입니다.
# 정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.


# 

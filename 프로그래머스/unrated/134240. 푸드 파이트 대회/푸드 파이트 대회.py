def solution(food):
    answer = ''
    temp = ''
    food = [food[i]//2 for i in range(1,len(food))]
    
    for i in range(len(food)):
        if food[i] != 0:
            temp += str(i+1)*food[i]
            
    answer = temp + '0' + temp[::-1]
    return answer
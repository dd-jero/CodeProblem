def solution(clothes):
    answer = 1
    hash_clothes={}
    
    for i in clothes:                   # 종류에 따라 해시에 추가
        if i[1] not in hash_clothes:
            hash_clothes[i[1]] = 1
        else:
            hash_clothes[i[1]] += 1
    
    for i in hash_clothes.values():     # 안 입는 경우 1을 추가하여 곱하여 경우의 수 구함
        answer *= (i+1)
    
    answer -= 1                         # 모두 안 입는 경우는 없으므로 1을 뺌

    return answer

# 가장 많은 폰켓몬의 종류 번호의 개수를 return하는 함수 완성
# N 마리 중 최대 N/2 마리 가능


def solution(nums):
    answer = 0
    hash = {}

    for num in nums:                            # 해시 안에 폰켓몬의 종류 번호 존재 여부 확인 위함
        if num in hash:                         # 해시 안에 폰켓몬 종류 번호가 있다면
            hash[num] += 1                      # 해당 종류 번호(key)의 value값 1 증가
        else:                                   # 해시 안에 폰켓몬 종류 번호가 없다면
            hash[num] = 1                       # 새로운 key, value 쌍 생성

    if len(nums)//2 < len(list(hash.keys())):   # len(list(hash.keys())): 해시의 key 값으로만 구성한 list의 길이를 구함
        answer = len(nums) // 2                 # N/2보다 많을 때는 answer = N/2
    else:                                       # N/2 보다 적을 때는 answer = len(list(hash.keys()))
        answer = len(list(hash.keys()))
    
    return answer


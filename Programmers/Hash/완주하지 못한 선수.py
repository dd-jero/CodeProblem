def solution(participant, completion):
    answer = ''
    hash = {}
    
    for name in participant:    # 참가자 명단을 해시에 넣기
        if name in hash:        # 이름이 이미 있으면 해당 key(name)의 value 1 증가
            hash[name] += 1
        else:                   # 이름이 없으면 새로운 key(name), value(1) 쌍 생성 
            hash[name] = 1
    
    for name in completion:     # 완주자 명단을 확인
        if hash[name] == 1:     # 동명이인이 없으면 해당 key, value 쌍 삭제
            del hash[name]
        else:                   # 동명이인이 있을 경우
            hash[name] -= 1     # 해당 value 1 감소

    answer = list(hash.keys())[0] # 해시를 리스트로 변환 후 index 0을 answer에 저장

    return answer

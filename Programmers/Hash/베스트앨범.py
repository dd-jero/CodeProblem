def solution(genres, plays):
    answer = []
    dic1 = {}      # index와 플레이 수를 저장하기 위한 dic
    dic2 = {}      # 장르별 총 플레이 수를 저장하기 위한 dic
    
    for i, (g,p) in enumerate(zip(genres,plays)): # enumerate(): index에 접근 가능, zip(): 내부 인자를 튜플의 형태로 묶어서 차례로 접근할 수 있도록 함
        if g not in dic1:                         # 해당 장르가 없으면
            dic1[g] = [(i,p)]                     # 장르를 key로 추가하고 value로 (index, plays)를 넣어줌
        else:                   
            dic1[g].append((i,p))                 # 해당 장르가 이미 존재하면 (index, plays)를 추가해줌
            
        if g not in dic2:
            dic2[g] = p
        else:
            dic2[g] += p
    
    for g,p in sorted(dic2.items(), key=lambda x:x[1], reverse=True):         # dic2의 [key, value]을 x라 할 때, x[1]에 해당하는 value를 내림차순 정렬
        for i, p2 in sorted(dic1[g], key=lambda x:x[1], reverse=True)[:2]:    # 총 play 수가 큰 장르 부터 돌게 되며 해당 장르의 (index, plays)로 plays를 내림차순 정렬하고 두번만 
            answer.append(i)

    return answer

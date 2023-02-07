from itertools import combinations

def solution(relation):
    answer = 0
    row = len(relation)
    col = len(relation[0])

    com = []

    for i in range(1, col+1):
        com.extend(combinations(range(col),i))                              # 가능한 속성의 모든 index 조합을 com 배열에 추가
    print(com)

    uni = []

    for i in com:
        temp = [tuple([item[key] for key in i]) for item in relation]

        if len(set(temp)) == row:                                           # 유일성에 대한 판단
            u = True

            for x in uni:
                if set(x).issubset(set(i)):                                 # 최소성에 대한 
                    u = False
                    break
            if u:
                uni.append(i)

    return len(uni)

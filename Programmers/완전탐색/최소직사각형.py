def solution(sizes):
    temp = []
    m1 = 0
    m2 = 0
    
    for li in sizes:    # sizes는 2차원배열이고 sizes의 내부의 1차원 배열을 정렬하고 이를 temp 리스트에 저장
        li.sort()
        temp.append(li)
    
    for t1, t2 in temp: # 내부의 배열 간 index 0 끼리, index 1 끼리 크기 비교
        if t1 > m1:
            m1 = t1
        
        if t2 > m2:
            m2 = t2
    
     
    return m1*m2

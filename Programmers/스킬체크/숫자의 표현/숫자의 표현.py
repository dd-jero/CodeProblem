from collections import deque

def solution(n):
    answer = 0
    li = [i for i in range(1,n+1)]    # 1 ~ n 까지의 배열 생성

    while(li):                        # li가 비어 있게되면 종료
        deq = deque()                 # 큐 활용
        for i in li:                  
            deq.append(i)
            if sum(deq) == n:         # 큐에 li의 요소를 하나씩 추가하면서 큐의 합이 n과 동일하면 경우의 수 1 증가, for 문 종료
                answer += 1
                break
            elif sum(deq) > n:        # 큐의 합이 n보다 크면 for문 종료
                break

        del li[0]                     # for문이 종료되면 li 배열의 맨 앞 요소를 

    return answer

number = int(input())

def cal(num):

    global count # 경우의 수 카운트

    for i in list: # 1,2,3 이용
        result_list.append(i)   # 처음에 res에 1부터 추가

        if sum(result_list) == num: # res의 합이 주어진 숫자와 같으면
            count += 1 # 하나의 경우의 수로 적립
            result_list.pop() # 마지막 요소 제거
            break # for문 종료
        
        cal(num) # 재귀
        
        result_list.pop() # res의 마지막 요소 제거

    return count # 경우의 수 리턴


for i in range (number):
    
    list = [1,2,3]
    result_list = []
    count = 0

    num = int(input())
    print(cal(num))

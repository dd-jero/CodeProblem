import sys                                                  # 입출력 방식 시간 줄이기
a = [False, False] + [True]* 999999                         # 아리스토테네스의 체 이용 => 처음에 한 번만 소수 구하기
odd = []                                                    # (element가 True이면, 해당 index는 소수)

for i in range(2,1000001):                                  # 2부터 문제 상의 최대 짝수 정수 1000000 까지
    if a[i]:                                                # True면 소수 => 새로운 소수 리스트에 추가 
        odd.append(i)
        for j in range(2*i, 1000001, i):                    # 추가 후 해당 소수를 이용한 소수 아닌 수들 False 
            a[j] = False

odd.remove(2)                                               # 문제 상에서 두 홀수 소수의 합이라고 했으니 2를 제거하여 홀수 소수 리스트 만듦 

while(1):
    
    count = 1

    n = int(sys.stdin.readline())

    if n != 0:                                              # 입력된 수가 0이 아니면 진행
        
        for i in odd:                                       # 소수 리스트의 요소들 이용하여 loop문
            
            if a[n-i]:                                      # 원래는 in 키워드를 이용해서 (n-i)가 odd에 있는 지 확인하는 코드를 작성했으나 odd의 모든 요소를 확인하기 때문에 시간 초과
                print("{} = {} + {}".format(n,i, (n-i)))    # format 함수 이용하여 출력 
                count = 0
                break
            
        if count == 1:                                      # 한 번이라도 위의 for문 안의 if문을 만족하지 못하면 count는 1로 유지됨을 이용
            print("Goldbach's conjecture is wrong.")
    
    else:                                                   # 입력된 수가 0이면 종료   
        break

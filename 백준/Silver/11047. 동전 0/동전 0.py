def greedy(list_coin, coin):
    count = 0                                       # 필요한 동전 개수의 최소값
    list_coin = [int(i) for i in list_coin]         # 리스트의 요소를 int형 변환
    list_coin.sort(reverse=True)                    # 리스트의 요소를 내림차순으로 정렬 => 최소 값을 구하기 위함 

    for i in list_coin:
        if i <= coin:                               
            count += coin//i                        # K원과 동일하거나 작으면서 가장 K원에 근접한 값으로 K원을 나누어 몫(개수) 구함 
            coin %= i                               # 나눈 나머지로 값 업데이트 

    return count                                    


n, k = map(int, input().split())
list_c = []

for i in range(n):
    list_c.append(input())

print(greedy(list_c,k))

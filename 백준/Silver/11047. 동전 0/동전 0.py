def greedy(list_coin, coin):
    count = 0
    list_coin = [int(i) for i in list_coin]
    list_coin.sort(reverse=True)

    for i in list_coin:
        if i <= coin:
            count += coin//i
            coin %= i

    return count


n, k = map(int, input().split())
list_c = []

for i in range(n):
    list_c.append(input())

print(greedy(list_c,k))
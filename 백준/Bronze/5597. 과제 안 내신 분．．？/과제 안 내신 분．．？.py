list_n = []
for i in range(28):
    list_n.append(int(input()))

list_n = sorted(list_n)

for i in range(1, 31):
    if i not in list_n:
        print(i)

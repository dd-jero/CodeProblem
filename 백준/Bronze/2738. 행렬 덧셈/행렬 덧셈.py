n,m = map(int, input().split())
list1 = []
list2 = []

for i in range(n):
    list1.append(list(map(int, input().split())))

for i in range(n):
    list2.append(list(map(int, input().split()))) 

list3 = [[x+y for x,y in zip(l1,l2)] for l1,l2 in zip(list1, list2)]

for i in range(n):
    for j in range(m):
        print(list3[i][j], end = " ")

    print()
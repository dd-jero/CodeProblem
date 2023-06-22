import sys
list_a = list(map(int,sys.stdin.readline().split()))

if list_a == sorted(list_a):
    print('ascending')

elif list_a == sorted(list_a, reverse = True):
    print('descending')

else:
    print('mixed')
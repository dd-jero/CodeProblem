def solution(n):
    num = n

    while(1):
        num += 1
        if str(bin(n)).count("1") == str(bin(num)).count("1"):
            return num

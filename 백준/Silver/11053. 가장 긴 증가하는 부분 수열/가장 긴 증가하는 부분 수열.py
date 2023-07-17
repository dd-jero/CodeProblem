import sys

def solution(n, numbers):

    dp = [1]*n

    for i in range(n):
        for j in range(i):
            if numbers[i] > numbers[j]:
                dp[i] = max(dp[i],dp[j]+1)

    return max(dp)

def main():
    n = int(sys.stdin.readline())
    numbers = list(map(int,sys.stdin.readline().split()))
    print(solution(n,numbers))

if __name__ == "__main__":
    main()
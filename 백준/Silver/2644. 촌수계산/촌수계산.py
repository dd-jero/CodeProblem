import sys

def solution(a):
    visited[a] = 1

    for i in range(1, N+1):

        if adjacency[a][i] == 1 and not visited[i]:
            cousin.append(i)
            solution(i)

            if cousin[-1] == b:
                return
            else:
                del cousin[-1]

def main():
    global b, N, visited, adjacency, cousin

    N = int(sys.stdin.readline())
    a,b = map(int, sys.stdin.readline().split())
    m = int(sys.stdin.readline())

    adjacency = [[0 for _ in range(N+1)] for _ in range(N+1)]
    cousin = []
    visited = [0 for _ in range(N+1)]

    for _ in range(m):
        x,y = map(int, sys.stdin.readline().split())
        adjacency[x][y] = 1
        adjacency[y][x] = 1

    solution(a)
    if b in cousin:
        print(cousin.index(b)+1)
    else:
        print(-1)

if __name__ == "__main__":
    main()
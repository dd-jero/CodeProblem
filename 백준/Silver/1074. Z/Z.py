import sys

def solution(size,x,y):

    global count

    if not ((x <= r < (x + size)) and (y <= c < (y + size))):
        count += (size*size)
        return
    
    if x == r and y == c:
        print(int(count))
        exit()

    if size == 1:
        count += 1
        return
    
    solution(size/2,x,y)
    solution(size/2,x,y+size/2)
    solution(size/2,x+size/2,y)
    solution(size/2,x+size/2,y+size/2)

def main():
    global r,c
    global count
    n,r,c = map(int,sys.stdin.readline().split())

    count = 0

    solution(2**n,0,0)

if __name__ == "__main__":
    main()


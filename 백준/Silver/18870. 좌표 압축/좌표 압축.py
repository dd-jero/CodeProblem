import sys
N = int(sys.stdin.readline())
num = list(map(int, sys.stdin.readline().split()))
sorted_num = sorted(list(set(num))) # 중복 제거 후 오름차순 정렬 -> 해당 인덱스가 좌표 압축 결과임

# 첫 시도 index() 함수 활용하여 출력 => 이 함수는 모든 값을 찾다가 나오는 형식이다. 
# list.index(N) -> O(N), for 문 내에서 list.index() -> O(N^2)
# ==> 해시 테이블 이용

dic_num = {}
for i in range(len(sorted_num)):
    dic_num[sorted_num[i]] = i # 정렬된 요소를 Key, 요소의 인덱스를 value로 하여 저장

for i in range(len(num)):
    print(dic_num[num[i]], end=" ")

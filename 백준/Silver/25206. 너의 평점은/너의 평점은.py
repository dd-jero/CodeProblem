import sys

dic = {"A+":4.5, "A0":4.0, "B+":3.5, "B0":3.0, "C+":2.5, "C0":2.0, "D+":1.5, "D0":1.0, "F":0.0} # 과목 평점 해시 테이블 

information = [list(sys.stdin.readline().split()) for _ in range(20)] # 20줄 입력
res = 0 # 학점 x 과목 평점 합
sum_num = 0 # 학점의 총합 

for i in range(20):
    grade = information[i][2] # 과목 평점
    
    if grade in dic:
        num = float(information[i][1]) # 학점
        res += dic[grade] * num
        sum_num += num

result = res/(sum_num)
print('%.6f'%result) # 예시처럼 소수점 아래 6자리까지 출력
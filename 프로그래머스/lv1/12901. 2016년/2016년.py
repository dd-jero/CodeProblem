def solution(a, b):
    year = {1:31, 2:29, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
    day = ['FRI','SAT','SUN','MON','TUE','WED','THU']
    
    temp = 0
    for i in range(1,a):
        temp += year[i]


    temp = (temp + b) % 7

    return day[temp-1]

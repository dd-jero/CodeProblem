def solution(s):
    answer = True
    dic = {'p': 0, 'y': 0}
    
    for i in s.lower():
        if i == 'p':
            dic['p'] += 1
        elif i == 'y':
            dic['y'] += 1
    
    if dic['p'] == dic['y']:
        return True
    else:
        return False


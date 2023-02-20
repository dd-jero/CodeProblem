def solution(s, n):
    answer = ''
    
    for al in s:
        if al != " ":
            if al == al.upper():
                if ord(al) + n > 90:
                    answer += chr(ord(al) + n - 26)
                else:
                    answer += chr(ord(al) + n)
            else:
                if ord(al) + n > 122:
                    answer += chr(ord(al) + n - 26)
                else:
                    answer += chr(ord(al) + n)    
        else:
            answer += " "
    return answer
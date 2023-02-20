def solution(s):
    answer = []
    index = 0
    s = list(s)

    for i in range(len(s)):
        
        
        if s[i] == " ":
            index = 0
            answer.append(" ")
        else:
            if index % 2 == 0:
                answer.append(s[i].upper())
                index += 1
            else:
                answer.append(s[i].lower())
                index += 1

        
    return "".join(answer)
def solution(phone_book):
    hash = {}
    
    for num in phone_book:  # 해시에 전화번호 추가
        hash[num] = 1
    
    for num2 in phone_book: # 
        temp =""

        for num3 in num2:
            temp += num3
            
            if temp!=num2 and temp in hash: 
                return False
              
    return True

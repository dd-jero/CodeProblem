T = int(input())
# bin : 이진수로, oct : 8진수로, hex: 16진수로
# ord : 문자를 아스키로, chr : 아스키(숫자)를 문자로
# int : 십진수로 변환 ex) int('101', 2) ==> '101'은 이진수 이기 때문에 뒤에 2 추가로 넣어준것

# 인덱스를 활용
dict = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
      'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
      '0','1','2','3','4','5','6','7','8','9','+','/']

for test_case in range(1, T + 1):
    chars = list(str(input()))
    val = ''
    res = ''

    for c in range(len(chars)):
        num = dict.index(chars[c]) # 표에 해당하는 값으로 변환
        bin_num = str(bin(num)[2:]) # 값을 이진수로 변환하고 0b 제거

        if len(bin_num) != 6: # 해당 이진수가 6자리가 아니면
            bin_num = (6-len(bin_num))*'0' + bin_num # 앞에 0을 붙여 6자리 맞춤
        val += bin_num

    for i in range(len(chars)*6 // 8): # 각 문자는 6bits의 이진수로 변환되었고 이를 8bits씩 변환
        number = int(val[i*8:i*8+8], 2) # 8bits씩 끊어서 십진수로 변환
        res += chr(number) # 해당 십진수를 다시 문자로 변환 (아스키코드) 

    print(f"#{test_case} {res}")

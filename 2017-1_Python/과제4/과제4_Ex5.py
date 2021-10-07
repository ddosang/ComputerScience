#4장 연습문제 5
#2017년 3월 28일


symbol_list = []
symbol = input("기호를 입력하시오 : ")
symbol_list.append(symbol) #기호의 리스트를 만든다

letter = input("중간에 삽입할 문자열을 입력하시오 : ")
print(symbol[0] + letter + symbol[1])

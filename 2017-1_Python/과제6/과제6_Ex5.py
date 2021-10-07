#과제6 연습문제5
#2017년 4월 24일

sum = 0

while True:  #무한루프 생성
    a = int(input("정수를 입력하시오: "))
    sum = sum + a

    if a == 0: #a == 0 일때 무한루프에서 빠져나옴
        break

print("합은", sum,"입니다.")


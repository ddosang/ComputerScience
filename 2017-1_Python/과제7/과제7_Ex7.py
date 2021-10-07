#과제7 연습문제7
#2017년 5월 15일


def circleArea(radius):
    global area
    area = PI*radius*radius
    return
#면적 구하는 함수 생성


def circleCircumference(radius):
    global circumference
    circumference = 2*PI*radius
    return
#둘레 구하는 함수 생성


PI = 3.14
#파이를 전역변수로 지정



r = int(input("원의 반지름:"))

circleArea(r)
circleCircumference(r)
print("반지름이", r, "인 원의 면적:", area)
print("반지름이", r, "인 원의 둘레:", circumference)
#반지름 입력 후 미리 정의한 함수를 이용해 면적과 둘레 출력

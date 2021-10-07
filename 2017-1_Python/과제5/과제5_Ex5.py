#과제 5 연습문제 5
#2017년 4월 4일

import random
x = random.randint(1,100) 
y = random.randint(1,100) #1~100 사이의 임의의 수

answer = int(input(str(x) + "-" + str(y)  + "=")) #str로 숫자열을 문자열로 변환

if answer == x-y :
    print("맞았습니다.")

else :
    print("틀렸습니다.") #if else 문 사용

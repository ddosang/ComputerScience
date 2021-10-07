#과제 5 연습문제 8
#2017년 4월 4일

import turtle
t = turtle.Turtle()
t.shape("turtle")


x1 = int(input("큰 원의 중심좌표 x1:"))
y1 = int(input("큰 원의 중심좌표 y1:"))
R = int(input("큰 원의 반지름:")) #첫번째 원에 대한 정보 입력


x2 = int(input("작은 원의 중심좌표 x1:"))
y2 = int(input("작은 원의 중심좌표 y1:"))
r = int(input("작은 원의 반지름:")) #두번째 원에 대한 정보 입력

d=( (x2-x1)**2 + (y2-y1)**2 )**(1/2)

    
t.up()
t.goto(x1,y1-R)
t.down()
t.circle(R) #첫번째 원 그림

t.up()
t.goto(x2,y2-r)
t.down()
t.circle(r) #두번째 원 그림

if (R-r)>d:  
    t.write("두번째 원이 첫번째 원의 내부에 있습니다.")

elif R-r==d or R+r==d:
    t.write("두 원이 겹칩니다.")

elif (R-r)< d <R+r:
    t.write("두 원이 두 점에서 만납니다.")
    
else :
    t.write("두 원이 만나지 않습니다.")

#두 원의 위치관계 식을 활용하여 경우를 나눈다.

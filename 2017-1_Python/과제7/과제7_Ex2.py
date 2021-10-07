#과제7 연습문제2
#2017년 5월 15일


import turtle
t = turtle.Turtle()
t.shape("turtle")
t.speed(0)


def hexagon():
    for i in range(6):
        t.forward(100)
        t.left(360/6)

    #육각형 그리는 함수 만든다


for i in range(6):
    hexagon()
    t.fd(100)
    t.right(60)

    #육각형을 돌면서 여섯번 그린다.

    
    
    
    

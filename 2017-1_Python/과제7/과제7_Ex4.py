#과제7 연습문제4
#2017년 5월 15일

import turtle
t = turtle.Turtle()
t.shape("turtle")
t.speed(0)


def draw_line():
    t.forward(100)
    t.backward(100)

    #길이 100짜리 선을 그리고 돌아오는 함수를 만든다.

for i in range(12):
    draw_line()
    t.left(360/12)
    #12번 360/12씩 돌아가면서 반복한다.
    
    

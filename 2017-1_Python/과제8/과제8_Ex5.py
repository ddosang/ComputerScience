#과제8 연습문제5
#2017년 5월 26일


import random
import turtle

def draw_shape(t, c, length, sides, x, y):
    
    t.speed(0)
    t.shape("turtle")
    t.color(c)
    t.up()
    t.goto(x,y)
    t.down()
    t.begin_fill()
    for i in range(sides):
        t.fd(length)
        t.right(360/sides)
        #다각형 그리기
    t.end_fill()
    #그리고 색칠하기
    

color = ['white', 'yellow', 'blue', 'skyblue', 'orange', 'green']

for i in range(10):
    t = turtle.Turtle()
    c = random.choice(color)
    length = random.randint(1,100)
    sides = random.randint(3,10)
    x = random.randint(-200,200)
    y = random.randint(-200,200)
    draw_shape(t, c, length, sides, x, y)

    #랜덤을 이용하여 함수의 변수 뽑기





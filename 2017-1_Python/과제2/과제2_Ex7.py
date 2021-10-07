#과제2 연습문제7
#날짜 : 2017년 3월 14일

import turtle
t = turtle.Turtle()
t.shape("turtle")

side = int(input("side : "))
angle = int(input("angle : "))

t.fd(side)
t.rt(angle)
t.fd(side)
t.rt(angle)
t.fd(side)
t.rt(angle)
t.fd(side)

t.fd(side)
t.rt(angle)
t.fd(side)
t.rt(angle)
t.fd(side) #정사각형 두개 완성

t.rt(angle)
t.fd(side)

t.fd(side)
t.rt(angle)
t.fd(side)
t.rt(angle)
t.fd(side)
t.rt(angle)
t.fd(side)

t.fd(side)
t.rt(angle)
t.fd(side)
t.rt(angle)
t.fd(side) #정사각형 네개 완성

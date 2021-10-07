#과제6 연습문제9
#2017년 4월 24일



import turtle
t = turtle.Turtle()
t.shape("turtle")






for i in range(10):
    
    import random
    r = random.randint(1,100)
    x = random.randint(-100,100)
    y = random.randint(-100,100)
    #난수를 () 범위 내에서 생성한다.
    
    t.up()
    t.goto(x,y)
    t.down()
    t.circle(r)
    #터틀이 (x,y)로 이동 후 반지름 r인 원을 그린다.

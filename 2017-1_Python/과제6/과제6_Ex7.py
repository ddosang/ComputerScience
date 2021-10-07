#과제6 연습문제7
#이름 : 임은지
#2017년 4월 24일



import turtle
t = turtle.Turtle()
t.shape("turtle")

t.left(90)

for i in range(6):
    t.forward(100)
    t.forward(-30)
    t.left(60)
    t.forward(30)
    t.forward(-30) #왼쪽 날개
    t.right(120)
    t.forward(30)
    t.forward(-30) #오른쪽 날개
    t.left(60)
    t.forward(-70)  #패턴 하나 그리고
    t.right(60)   #두번째 패턴을 그리기 위해 돌려준다
    

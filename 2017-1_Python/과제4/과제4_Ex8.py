#4장 연습문제 8
#2017년 3월 28일



import turtle
t = turtle.Turtle()
t.shape("turtle")


x_y_list = []

x_y = int(input("x1 : "))
x_y_list.append(x_y)
x_y = int(input("y1 : "))
x_y_list.append(x_y) #(x1, y1) 입력 후 저장

x_y = int(input("x2 : "))
x_y_list.append(x_y)
x_y = int(input("y2 : "))
x_y_list.append(x_y) #(x2, y2) 입력 후 저장

x_y = int(input("x3 : "))
x_y_list.append(x_y)
x_y = int(input("y3 : "))
x_y_list.append(x_y) #(x3, y3) 입력 후 저장


t.goto(x_y_list[0], x_y_list[1])
t.goto(x_y_list[2], x_y_list[3])
t.goto(x_y_list[4], x_y_list[5]) #입력받은 좌표에 따라 터틀 이동

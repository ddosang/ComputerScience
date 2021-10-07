#과제8 연습문제2
#2017년 5월 26일


import random

outfile = open("result2.txt", "w")
#아웃파일 오픈

counters=[0,0,0,0,0,0]

while True:
    value = random.randint(0,5)
    counters[value] = counters[value]+1
    if counters[value]>=200:
        break

#주사위를 랜덤하게 굴린다.

for i in range(6):
    outfile.write("주사위가 "+ str(i+1) +"인 경우는 "+ str(counters[i])+"\n")

outfile.close()

#아웃파일에 저장


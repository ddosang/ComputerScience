#과제8 연습문제 11-5
#2017년 5월 26일


infile = open("data6.txt", "r")
outfile = open("result6.txt", "w")
#인파일 아웃파일 오픈

total = 0.0
count = 0



for line in infile:
    line = line.rstrip()
    value = float(line)
    total += value
    count += 1


#for 문을 이용해 infile을 한줄씩 읽는다
    
avg = total/count

outfile.write("합계="+str(total)+"\n")
outfile.write("평균="+str(avg)+"\n")
#평균 계산 후 출력

infile.close()
outfile.close()


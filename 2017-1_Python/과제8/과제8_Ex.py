#과제8 1번문제
#2017년 5월 26

infile = open("data1.txt","r+")
#텍스트 파일 오픈


total = 0
count = 0

line_list=[]
print("====점수====")
line = infile.readline().rstrip()
#한줄 한줄씩 데이터를 읽음

while line:
    line_list.append(line)
    print("점수", count+1, ":", line)
    value = float(line)
    total += value
    count += 1
    line = infile.readline().rstrip()
#라인을 읽으면서 카운트와 값 누적

print("============")
print("평균=", total/count)
print("============")

    
infile.close()

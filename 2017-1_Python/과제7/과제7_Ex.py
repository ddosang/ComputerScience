#총 5번의 시험을 보는 과목이 있다. 5개의 시험 점수의 평균이 60점 이상일 경우
#Pass, 60점 미만일 경우 Fail이다.
#각 시험에서 받은 점수로 이루어진 리스트 score가 [90, 80, 70, 60, 50]일 때,
#점수 평균, 가장 높은 점수와 가장 낮은 점수의 차이, Pass/Fail 여부를 출력해 주는
#프로그램을 작성하시오. 단, numlist 를 정수 리스트라고 할 때,
#아래 함수를 정의하여 사용하여야 한다.
#평균 구하는 함수 list_avg ( numlist )
#Pass Fail 구하는 함수 PassFail ( numlist )
#가장 높은 점수와 가장 낮은 점수 구하는 함수 gap_score( numlist )
#과제7 자체문제
#2017년 5월 15일





def list_avg(numlist):
    numlist = score_list
    avg = (score_list[0] + score_list[1] + score_list[2] + score_list[3] + score_list[4])/5
    return avg
    
score_list = [90,80,70,60,50]
avg = list_avg(score_list)
#리스트의 평균 구하는 함수 작성





        
def PassFail(numlist):
    numlist = score_list
    avg = (score_list[0] + score_list[1] + score_list[2] + score_list[3] + score_list[4])/5
    
    if avg >=60:
         print("You Pass the class")
    else:
         print("Fail")
#리스트의 평균을 판단하는 함수 작성
         



def gap_score(numlist):
    numlist = score_list
    gap = max(score_list) - min(score_list)
#리스트의 최대값과 최솟값 사의 갭을 나타내는 함수 작성

gap = gap_score(score_list)



print("평균 =", avg)
print("최대점수와 최소점수차이 =", gap)
PassFail(score_list)

    


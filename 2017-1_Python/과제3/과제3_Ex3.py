#과제3 연습문제3
#2017년 3월 21일


x = int(input("정수를 입력하시오 : "))



sum_of_cipher = x//1000 + x%1000//100 + x%100//10 + x%10

#x를 1000 100 10 1로 나눈 몫과 나머지 이용


print("자리수의 합 :", sum_of_cipher)

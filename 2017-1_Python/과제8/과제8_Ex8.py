#과제8 연습문제8
#2017년 5월 26일


problems = {"파이썬":"최근에 가장 떠오르는 프로그래밍 언어",
            "변수":"데이터를 저장하는 메모리 공간",
            "함수":"작업을 수행하는 문장들의 집합에 이름을 붙인것",
            "리스트":"서로 관련이 없는 항목들의 모임"}

#딕셔너리 만든다

for word in problems.keys():
    print("다음은 어떤 단어에 대한 설명일까요?")
    print(problems[word])
    print("(1)파이썬", "(2)변수", "(3)함수", "(4)리스트")
    #하나씩 꺼내서 사용자에게 제시
    
    answer = input("")
    #사용자가 정답 입력
    
    if answer == word:
        print("정답입니다.\n")
    else:
        print("오답입니다.\n")
    #정답판단
        

    
   
    

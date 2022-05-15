## 1.3
<hr>
<br>

### 1번
<hr>
명확성  

(a) 최대 값은 2인가? 라는 말이 모호함.
(b) 10번 명령문이 뭔지 모름  

<br>

### 2번
<hr>
다항식 계산 - Horner 의 법칙 이용  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-02.c)


<br>

### 3번
<hr>

n개의 Boolean 가능한 tuple 전부 출력  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-03.c)


<br>

### 4번
<hr>

x, y, z 를 오름차순으로 출력  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-04.c)


<br>

### 5번
<hr>

비둘기의 집 원칙 - 입력 값이 다른데 결과 값은 같은 a, b 를 찾는 프로그램을 작성하라.  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-05.c)


<br>

### 6번
<hr>

어떤 양의 정수 n의 약수의 합이 n과 같은지를 알아보는 프로그램을 작성하라.  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-06.c)


<br>

### 7번
<hr>

반복, 재귀로 팩토리얼 함수 구현  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-07.c)


<br>

### 8번
<hr>

반복, 재귀로 피보나치 함수 구현  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-08.c)


<br>

### 9번
<hr>

반복, 재귀로 이항계수 nCm 구현  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-09.c)


<br>

### 10번
<hr>

반복, 재귀로 Ackermann 함수 A(m, n) 구현  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-10.c)

<br>

### 11번
<hr>

하노이의 탑 옮기는 횟수 구하는 재귀 함수  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-11.c)

<br>

### 12번
<hr>

부분 집합의 모든 경우의 집합인 멱집합을 구하는 재귀 함수  

[코드](https://github.com/ddosang/ComputerScience/tree/main/C로%20쓴%20자료구조론/CH01/1-3-12.c)

<br><br>


## 1.5
<hr>
<br>

### 1번
<hr>
NaturalNumber ADT 에 Predecessor, IsGreater, Multiply, Divide 연산자 추가

```c
Predecessor(x) :== if (x > 0) return x - 1
IsGreater(x, y) :== if (x < 0) return error
                    if (y < 0) return error
                    if (x > y) return TRUE
                    return FALSE
Multiply(x, y) :== if (x < 0) return error
                   if (y < 0) return error
                   if (x * y <= INT_MAX) return x * y
                   return INT_MAX
Divide(x, y) :== if (x < 0) return error
                 if (y =< 0) return error
                 return x / y
```

<br>

### 2번
<hr>
```c
ADT Set
objects: 0과 INT_MAX 사이에 있는 정수.


Create() :== {}
IsEmpty(s) :== if (s == {}) return TRUE
               else return FALSE
Insert(x, s) :== if (!IsIn(x, s)) s = s + x
Remove(x, s) :== if (IsIn(x, s)) s = s - x
IsIn(x, s) :== if (x in s) return TRUE
               else return FALSE
Union(s1, s2) :== s1 + s2 - Intersection (s1, s2)
Intersection(s1, s2) :== if (IsIn(tail(x), s1) and (IsIn(tail(x), s2))) s + x
                         return x
Difference(s1, s2) :== s1 - Intersection(s1, s2)
```


<br>

### 3번
<hr>
```c
ADT Bag
objects: 0과 INT_MAX 사이에 있는 정수.


Create() :== {}
IsEmpty(s) :== if (s == {}) return TRUE
               else return FALSE
Insert(x, s) :==  s = s + x
Remove(x, s) :== if (IsIn(x, s)) s = s - x
IsIn(x, s) :== if (x in s) return TRUE
               else return FALSE
```



<br>

### 4번

```c
ADT Boolean
objects: TRUE, FALSE


And(x, y) :== if (not x) return FALSE
              if (not y) return FALSE
              return TRUE
Or(x, y) :== if (x) return TRUE
             if (y) return TRUE
             return FALSE
Not(x) :== if (x) return FALSE
           else return TRUE
Xor(x, y) :== if (x == y) return FALSE
              else return TRUE
```



<br><br>

## 1.5 - 공간복잡도
<hr>
<br>

### 1번
<hr>
1-3-07 팩토리얼 공간 복잡도 계산  

반복 : 0


<br>

### 2번
<hr>
1-3-08 피보나치 공간 복잡도 계산  

반복  
- n 1개, fact 1개, i 1개 
- S(n) = 3 * sizeof int (고정)

재귀  
- n 1개, 재귀 복귀 주소 1개
- S(n) = 2 * sizeof int * n (가변)

<br>

### 3번
<hr>
1-3-09 이항계수 공간 복잡도 계산  

반복  
- first 1개, second 1개, res 1개, i 1개
- S(n) = 4 * sizeof int (고정)

재귀  
- n 1개, 재귀 복귀 주소 1개 를 2번씩 호출
- S(n) = 2 * 2 * sizeof int * n (가변)


<br>

### 4번
<hr>
1-3-05 비둘기 집 원칙 공간 복잡도 계산  

- inputs, ouputs MAX_COUNT 개, num 1개, result 1개, i 1개
- S(n) = (2 * MAX_COUNT + 3) * sizeof int (고정)

<br>

### 5번
<hr>
1-3-12 멱집합 공간 복잡도 계산  

- n, N, check[MAX_COUNT], 재귀 주소 2^n 개
- S(n) = (2 + MAX_COUNT + (2^n)) * sizeof int (고정 + 가변)


<br>



#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 101
typedef struct {
	int degree;
	int coef[MAX_DEGREE];
}polynomial;

//주어진 두개의 다항식 p(x)와 q(x)에 대해서 두 다항식을 더한 다항식 r(x)를 구하고, 주어진 x값에 대해 p(x)값, q(x)값 및 r(x)의 값을 구하는 프로그램을 작성한다
polynomial poly_add(polynomial A, polynomial B) {
	polynomial C;
	int Ai = 0, Bi = 0, Ci;
	int degree_a = A.degree;
	int degree_b = B.degree;

	C.degree = MAX(A.degree, B.degree);
	Ci = C.degree;

	if (A.degree > B.degree) {
		for (int i = 0; i <= B.degree; i++)
			C.coef[i] = A.coef[i] + B.coef[i];
		for (int i = B.degree + 1; i <= A.degree; i++)
			C.coef[i] = A.coef[i];
	}else if (A.degree == B.degree) {
		for (int i = 0; i <= B.degree; i++)
			C.coef[i] = A.coef[i] + B.coef[i];
	}else {
		for (int i = 0; i <= A.degree; i++)
			C.coef[i] = A.coef[i] + B.coef[i];
		for (int i = A.degree + 1; i <= B.degree; i++)
			C.coef[i] = B.coef[i];
	}
		
	return C;
}

int poly_sub(polynomial p, int x) {
	int xpower = 1;
	int p1 = p.coef[0];
	for (int i = 1; i <= p.degree; i++) {
		xpower *= x;
		p1 += p.coef[i] * xpower;
	}
	return p1;
}

int main(void) {
	polynomial p, q, r;
	int n1, n2;

	scanf_s("%d", &p.degree);

	for (int i = p.degree; i >= 0; i--)
		scanf_s("%d ", &p.coef[i]); //p(x) 다항식 차수와 계수 입력받음

	scanf_s("%d", &q.degree);

	for (int i = q.degree; i >= 0; i--)
		scanf_s("%d ", &q.coef[i]); //q(x) 다항식 차수와 계수 입력받음

	printf("p(x) = ");
	for (int i = p.degree; i >= 0; i--) {
		printf("%dx^%d ", p.coef[i], i);
		if (i >= 1) {
			printf("+ ");
		}
	}printf("\n"); //p(x) 출력

	printf("q(x) = ");
	for (int i = q.degree; i >= 0; i--) {
		printf("%dx^%d ", q.coef[i], i);
		if (i >= 1) {
			printf("+ ");
		}
	}printf("\n"); //q(x) 출력
	printf("\n");
	
	r = poly_add(p, q); //r(x) = p(x) + q(x)

	scanf_s("%d %d", &n1, &n2);
	
	printf("r(x) = ");
	for (int i = r.degree; i >= 0; i--) {
		printf("%dx^%d ", r.coef[i], i);
		if (i >= 1) {
			printf("+ ");
		}
	}printf("\n"); //r(x) 출력


	printf("p(%d) = %d  q(%d) = %d  r(%d)=%d\n", n1, poly_sub(p, n1), n1, poly_sub(q,n1), n1, poly_sub(r, n1));
	printf("p(%d) = %d  q(%d) = %d  r(%d)=%d\n", n2, poly_sub(p, n2), n2, poly_sub(q, n2), n2, poly_sub(r, n2));
	//대입하여 값 출력
}

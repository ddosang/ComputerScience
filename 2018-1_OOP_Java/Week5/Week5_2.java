import java.util.Scanner;

class Facto{
	static int result; //클래스 변수 result 선언
	
	static int facto_sum(int x){
		int fac = 1; //지역변수 fac은 초기화 필요
		for(int i = 1; i <= x ; i++){
			fac *= i;
		} // 반복문 for문을 이용해 x! 계산.
		return fac; //fac값을 반환한다.
	}//정수형 인자 1개를 가지는 static 메서드 facto_sum
}

class Week5_2 {
	public static void main(String[] args){

		int n1, n2, fac_n1, fac_n2; // 정수형 변수 5개 선언.
		Scanner kb = new Scanner(System.in); // 입력을 위해
		
		System.out.printf("첫번째 원소 입력:"); 
		n1 = kb.nextInt();
		System.out.printf("두번째 원소 입력:");
		n2 = kb.nextInt();
		//정수 두개를 입력받는다.
		
		fac_n1 = Facto.facto_sum(n1);
		fac_n2 = Facto.facto_sum(n2);
		//Facto 클래스 안의 facto_sum 클래서 메서드를 이용하여 n1!, n2! 계산.
		
		Facto.result = fac_n1 - fac_n2;
		//두 팩토리얼 값의 차이를 클래스 변수 result에 저장.
		
		System.out.println("Factorial(" + n1 + ") - Factorial(" + n2 + ") = "+Facto.result );
		//Factorial(n1) - Factorial(n2) = Facto.result 형태로 출력.
	}
}

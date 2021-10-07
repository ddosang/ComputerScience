import java.util.Scanner;
public class Week1_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner keyb = new Scanner(System.in); //스캔을 위해 써준다.
		
		int a,b,c; //정수형 변수 a,b,c 선언
		double avg;//실수형 변수 avg 선언
		
		System.out.printf("정수 세 개 입력\n");
		a = keyb.nextInt();
		b = keyb.nextInt();
		c = keyb.nextInt();
		//정수 세개를 입력받는다.
		
		avg = ((double)a+(double)b+(double)c)/3;
		//소숫점까지 출력하기 위해 a,b,c를 double형으로 변환하고 3으로 나눈다.
		System.out.printf("평균: %.2f",avg);
		//평균값을 소숫점 둘째자리까지 출력한다.	
	}
}

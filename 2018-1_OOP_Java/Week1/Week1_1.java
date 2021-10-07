
import java.util.Scanner;
public class Week1_1 {
	public static void main(String[] args){
		
		System.out.printf("Input base:");
		//Input base: 출력
		
		int base, height;//base, height라는 정수형 변수 선언
		double area;//area 라는 실수형 변수 선언
		
		Scanner keyboard = new Scanner(System.in);//스캔을 위해 써준다.
		base = keyboard.nextInt();// base 입력받음
		
		System.out.printf("Input height:");
		height = keyboard.nextInt();
		//Input height: 를 출력하고 height를 입력받음
		
		area = (double)base*(double)height/2;
		//base와 height를 double로 형변환 한 뒤 삼각형 넓이 공식
		
		System.out.println("The area:"+area);
		//The area: 와 area값 출력
	}
}

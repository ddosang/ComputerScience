import java.util.Scanner;
public class Week1_3 {
	public static void main(String[] args){
		
		Scanner keyb = new Scanner(System.in); //스캔을 위해 써준다.
		
		int Ff; //정수형 변수 Ff선언
		double Cc; //실수형 변수 Cc선언
		
		System.out.printf("화씨온도 입력: "); 
		Ff = keyb.nextInt();
		//화씨온도를 입력 받는다.
		
		System.out.printf("\n화씨온도: %d\n",Ff);
		//입력받은 화씨온도를 한줄 띄고 출력한다.
		
		Cc = 5*((double)Ff-32)/9;
		//형변환을 하고, 화씨 온도를 섭씨 온도로 바꾸는 식을 이용.
		System.out.printf("섭씨온도: %.1f\n",Cc);
		//섭씨온도 Cc를 출력한다.
		
	}

}

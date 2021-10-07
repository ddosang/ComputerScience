import java.util.Scanner;
public class Week3_2 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in); //입력을 위해
		int score, score2;//정수형 변수 score, score2 선언
		char grade = 'A',ch; //문자형 변수 grade, ch 선언
		String ss; //문자열 ss
		do{
			System.out.printf("점수입력:");
			score = kb.nextInt(); //점수를 입력받는다.
			score2 = score/10; // switch문을 사용하기 위해 10으로 나눈다.
			
			if(score >= 0 && score <= 100){
			switch(score2){
			case 10:
			case 9: grade = 'A'; break;
			case 8: grade = 'B'; break;
			case 7: grade = 'C'; break;
			case 6: grade = 'D'; break;//break 필수!
			default: grade = 'F';}
			System.out.println("점수는 "+score+"점이고 "+"grade는 "+grade+"입니다.");}
			// 점수가 0~100 사이 일때 점수에 따라 grade를 확정한 뒤 점수와 grade를 출력한다.
			
			else{
				System.out.println("점수는 0~100사이입니다.");
			}//범위를 벗어난 점수를 입력하면 나오는 문구
			
			
			
			System.out.println("반복하시겠습니까?(y/n)");
			ss = kb.next();
			ch = ss.charAt(0);
		}while(ch == 'y'||ch=='Y');
		//do while문을 사용하여 입력받은 ss의 맨앞글자인 ch가 y나 Y일때 반복
		System.out.println("종료");
	}
}

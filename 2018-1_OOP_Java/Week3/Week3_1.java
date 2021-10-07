import java.util.Scanner;
public class Week3_1 {

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		System.out.printf("월 입력:");
		int month, date = 0;//정수형 변수 month, date 선언
		month = kb.nextInt();//month를 입력받는다.
		
		switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			date = 31; break;
			// 1 3 5 7 8 10 12 월은 31일
			//break를 만날때까지 내려오는 속성을 이용 : case stacking
			
		case 2:
			date = 28; break;
			//2월은 28일
			
		case 4:
		case 6:
		case 9:
		case 11:
			date = 30; break;
			// 4 6 9 11  월은 30일
		default:
			System.out.println("입력 오류"); break;
			//switch문을 이용하여 31일 28일 30일 인 달을 나눈다.
		}
		System.out.println(month + "월에는 "+date+"일이 있습니다.");
		//입력받은 월과 그에 해당되는 일 수를 출력.
	}
}

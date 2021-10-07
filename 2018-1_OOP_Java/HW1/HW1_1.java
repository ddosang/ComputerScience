package fallinlovewithyou;

import java.util.Scanner;
class Time{
	private int hour;
	private int minute; 
	//private 인스턴스 변수 hour와 minute 선언
	
	private boolean isValid(int hour, int minute) {
		if(0<=hour && hour <= 23 && 0 <= minute && minute <= 59){
			return true;
		}//hour와 minute이 범위 안에 있을때 true값 반환
		else {
			System.out.println("Wrong Input");
			return false;}
		//범위 밖에 있을때 잘못된 입력이라고 알려주기
	}//private method isValid return값은 boolean형
	
	public void setTime(int hour,int minute) {
		if(isValid(hour, minute) == true) {
			this.hour = hour;
			this.minute = minute;
			//a.setTime(hour,minute)일때 a의 hour, minute에
			//인자로 전달받은 hour, minute 넣는다.
		}
	}//int형 인자 2개를 받는 setTime method : return값 없음

	public int getTime(char ch) {
		if (ch == 'H' || ch == 'h') {
			return hour;
		}
		else if(ch == 'M' || ch == 'm') {
			return minute;
		}
		else {
			return 0;
		}
	}//ch 가 H,h이면 hour M,m이면 minute을 반환. 둘 다 아니면 0 반환.
}
public class HW1_1 {
public static void main(String[] args) {
	
	Scanner kb = new Scanner(System.in);
	
	int hour, minute;//정수형 변수 hour, minute 선언
	
	System.out.println("Hour:");
	hour = kb.nextInt();
	System.out.println("Minute:");
	minute = kb.nextInt();
	//hour와 minute 입력받음
	
	Time t = new Time();
	//Time class 의 객체 t 생성.
	
	t.setTime(hour, minute);
	//setTime method를 이용해 입력받은 값으로 t의 시간과 분 설정.
	
	System.out.println(t.getTime('h')+":"+t.getTime('m'));
	//getTime method를 이용해 t의 hour와 minute을 출력
}
}

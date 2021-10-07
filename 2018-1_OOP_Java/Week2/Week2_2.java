package fallinlovewithyou;
import java.util.Scanner;

public class Week2_2 {
	public static void main(String[] args) {
	
		Scanner keyb = new Scanner(System.in);
		//입력 받기 위해 입력
		String s1, s2, s3, s4, s5;//문자열
		int leng; //정수형 변수 leng 선언
		
		System.out.println("Enter a line of text.");
		s1 = keyb.nextLine(); //s1을 한 줄 입력 받는다.
		
		System.out.println("Your text is \"" + s1 + "\".");
		//정해진 문구와 함께 s1을 출력한다.
		System.out.println("Input a word to replace.");
		s2 = keyb.next(); //원래 문장에서 바꾸고 싶은 단어를 입력 받는다.
		System.out.println("Input a word to insert.");
		s3 = keyb.next(); //앞에서 입력한 단어 자리에 들어갈 단어를 입력 받는다.
		
		s4 = s1.replace(s2,s3); //s1에 있던 s2를 s3으로 바꾼다.
		System.out.println("New sentence is \"" + s4 + "\".");
		//문구와 함께 s4를 출력한다.
		
		leng = s4.length(); //s4의 길이를 leng에 대입한다.
		s5 = s4.toUpperCase(); // s4의 모든 문자를 대문자로 바꾼다
		System.out.println("The length of \"" + s5 + "\" is " + leng + ".");
		//s4의 길이인 leng을 출력한다.
		
	}

}

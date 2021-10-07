package fallinlovewithyou;

import java.util.Scanner;
class DiceGame{
	Scanner kb = new Scanner(System.in);
	
	private int diceFace;
	private int userGuess;
	//private 인스턴스 변수 diceFace, userGuess 선언
	
	DiceGame(int diceFace){
	}//int 인자를 하나 가지는 생성자 선언
	
	private int rollDice() {
		int diceFace = (int)(Math.random()*6) + 1;
		System.out.println("Dice is rolled!");
		return diceFace;
	}//private 인스턴스 메서드 rollDice()
	 //Math.random()을 이용해 diceFace에 1~6 사이의 난수를 저장
	
	private int getUserInput() {
		
		System.out.println("Guess the number! What do you think?");
		userGuess = kb.nextInt();
		
		while(1>userGuess || userGuess>6){
			System.out.println("Input the number between 1~6.");
			userGuess = kb.nextInt();
		}
		return userGuess;
	}//private 인스턴스 메서드 getUserInput()
	//값을 넣으면 범위 안에 있는지 판단하고 범위 안에 없으면 계속 입력 받음
	
	private void checkUserGuess(int diceFace) {
		userGuess = getUserInput();
		if(userGuess == diceFace) {
			System.out.println("Bingo!");
		}
		else {
			System.out.println("Wrong!");
			System.out.println("The Face was "+diceFace);
		}
	}//diceFace를 입력받아 userGuess와 비교
	//userGuess는 getUserInput()을 호출하여 얻는다
	
	public void startPlaying() {
		diceFace = rollDice();
		checkUserGuess(diceFace);
	}//rollDice()와 checkUserGuess()를 호출하여 주사위를 던지고 입력받은 값과 비교.
	
}
public class HW1_2 {
public static void main(String[] args) {
	
	char ch = 'y';
	String s = new String("");
	DiceGame d = new DiceGame(0);
	//0은 생성자에 int 인자가 있어서 초기값으로 넣어줌
	//문자형 변수 ch, 문자열 s, Dicegame class의 객체 d 생성.
	
	Scanner kb = new Scanner(System.in);
	
	while(ch == 'y'||ch =='Y') {
		System.out.println("<< GAME START >>");
		d.startPlaying();
		System.out.println("Try agrain?(y/n)");
		s = kb.next();
		ch = s.charAt(0);//문자열의 첫글자 땀
		System.out.println("");
	}//ch 가 y나 Y이면 반복한다.
	
	System.out.println("Game finished.");//반복문을 나오면 출력
}
}

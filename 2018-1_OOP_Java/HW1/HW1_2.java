package fallinlovewithyou;

import java.util.Scanner;
class DiceGame{
	Scanner kb = new Scanner(System.in);
	
	private int diceFace;
	private int userGuess;
	//private �ν��Ͻ� ���� diceFace, userGuess ����
	
	DiceGame(int diceFace){
	}//int ���ڸ� �ϳ� ������ ������ ����
	
	private int rollDice() {
		int diceFace = (int)(Math.random()*6) + 1;
		System.out.println("Dice is rolled!");
		return diceFace;
	}//private �ν��Ͻ� �޼��� rollDice()
	 //Math.random()�� �̿��� diceFace�� 1~6 ������ ������ ����
	
	private int getUserInput() {
		
		System.out.println("Guess the number! What do you think?");
		userGuess = kb.nextInt();
		
		while(1>userGuess || userGuess>6){
			System.out.println("Input the number between 1~6.");
			userGuess = kb.nextInt();
		}
		return userGuess;
	}//private �ν��Ͻ� �޼��� getUserInput()
	//���� ������ ���� �ȿ� �ִ��� �Ǵ��ϰ� ���� �ȿ� ������ ��� �Է� ����
	
	private void checkUserGuess(int diceFace) {
		userGuess = getUserInput();
		if(userGuess == diceFace) {
			System.out.println("Bingo!");
		}
		else {
			System.out.println("Wrong!");
			System.out.println("The Face was "+diceFace);
		}
	}//diceFace�� �Է¹޾� userGuess�� ��
	//userGuess�� getUserInput()�� ȣ���Ͽ� ��´�
	
	public void startPlaying() {
		diceFace = rollDice();
		checkUserGuess(diceFace);
	}//rollDice()�� checkUserGuess()�� ȣ���Ͽ� �ֻ����� ������ �Է¹��� ���� ��.
	
}
public class HW1_2 {
public static void main(String[] args) {
	
	char ch = 'y';
	String s = new String("");
	DiceGame d = new DiceGame(0);
	//0�� �����ڿ� int ���ڰ� �־ �ʱⰪ���� �־���
	//������ ���� ch, ���ڿ� s, Dicegame class�� ��ü d ����.
	
	Scanner kb = new Scanner(System.in);
	
	while(ch == 'y'||ch =='Y') {
		System.out.println("<< GAME START >>");
		d.startPlaying();
		System.out.println("Try agrain?(y/n)");
		s = kb.next();
		ch = s.charAt(0);//���ڿ��� ù���� ��
		System.out.println("");
	}//ch �� y�� Y�̸� �ݺ��Ѵ�.
	
	System.out.println("Game finished.");//�ݺ����� ������ ���
}
}

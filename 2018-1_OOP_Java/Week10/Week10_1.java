import java.util.Scanner;
class Dice{
	private int diceNum;
	public void setDiceNum() {
		diceNum = (int)(6*Math.random()) + 1;
	}//랜덤한 숫자 넣는다.
	public int GetDiceNum() {
		return diceNum;
	}
}//Dice class
class Person{
	Scanner kb = new Scanner(System.in);
	private char ID;
	private int guessNum;
	
	Person(char ID){
		this.ID = ID;
	}
	public void inputGuess() {
		do{
		try{
			System.out.println("Person "+ID+" - Guess the number:");
			guessNum = kb.nextInt();
			if(guessNum < 1 || guessNum > 6)
				throw new OutOfBoundaryException("Number should be between 1~6");
			else
				break;
		}catch(OutOfBoundaryException oe){
			System.out.println(oe.getMessage());
			System.out.println("Try Again!");
			continue;
		}//guessNum이 범위를 벗어나면 오류 메세지를 출력
		}while(!(1<=guessNum && guessNum<=6));//범위가 아닐때 반복해서 입력받는다
	}
	public int getGuessNum() {
		return guessNum;
	}
	public char getID(){
		return ID;
	}//ID를 리턴값으로 받음
}//Person class

public class Week10_1 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		Dice d = new Dice();
		Person p1 = new Person('1');
		Person p2 = new Person('2'); //ID값 넣어준다
		//Dice, Person 인스턴스 생성
		char ch = 'y';
		int g1=0, g2=0;
		
		while(ch == 'y') {	
			System.out.println("Dice is rolled");
			d.setDiceNum();
			
			p1.inputGuess();
			p2.inputGuess();
			//p1, p2 각각 inputGuess 실행
						
			System.out.println("Dice Number: "+d.GetDiceNum());
				
			int n1 = (p1.getGuessNum()-d.GetDiceNum())>=0?(p1.getGuessNum()-d.GetDiceNum()):-(p1.getGuessNum()-d.GetDiceNum());
			int n2 = (p2.getGuessNum()-d.GetDiceNum())>=0?(p2.getGuessNum()-d.GetDiceNum()):-(p2.getGuessNum()-d.GetDiceNum());
			//추측값과 실제 주사위 눈금의 차 n1 n2 에 저장
			if( n1 < n2 )
				System.out.println("Person"+p1.getID()+" won!");
			else if(n1 == n2)
				System.out.println("Tie");
			else
				System.out.println("Person"+p2.getID()+" won!");
			//n1과 n2를 비교해서 결과 출력
			
			System.out.println("Repeat?(y/n)");
			String s = kb.nextLine();
			ch = s.charAt(0);
			//반복 여부 입력받는다.
			System.out.println();
			System.out.println();
		}
	}
}
class OutOfBoundaryException extends Exception{
	OutOfBoundaryException(String msg) {
		super(msg);
	}
}//범위를 벗어난 예외 정의

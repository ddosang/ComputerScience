import java.util.Scanner;
class Dice{
	private int diceNum;
	public void setDiceNum() {
		diceNum = (int)(6*Math.random()) + 1;
	}//������ ���� �ִ´�.
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
		}//guessNum�� ������ ����� ���� �޼����� ���
		}while(!(1<=guessNum && guessNum<=6));//������ �ƴҶ� �ݺ��ؼ� �Է¹޴´�
	}
	public int getGuessNum() {
		return guessNum;
	}
	public char getID(){
		return ID;
	}//ID�� ���ϰ����� ����
}//Person class

public class Week10_1 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		Dice d = new Dice();
		Person p1 = new Person('1');
		Person p2 = new Person('2'); //ID�� �־��ش�
		//Dice, Person �ν��Ͻ� ����
		char ch = 'y';
		int g1=0, g2=0;
		
		while(ch == 'y') {	
			System.out.println("Dice is rolled");
			d.setDiceNum();
			
			p1.inputGuess();
			p2.inputGuess();
			//p1, p2 ���� inputGuess ����
						
			System.out.println("Dice Number: "+d.GetDiceNum());
				
			int n1 = (p1.getGuessNum()-d.GetDiceNum())>=0?(p1.getGuessNum()-d.GetDiceNum()):-(p1.getGuessNum()-d.GetDiceNum());
			int n2 = (p2.getGuessNum()-d.GetDiceNum())>=0?(p2.getGuessNum()-d.GetDiceNum()):-(p2.getGuessNum()-d.GetDiceNum());
			//�������� ���� �ֻ��� ������ �� n1 n2 �� ����
			if( n1 < n2 )
				System.out.println("Person"+p1.getID()+" won!");
			else if(n1 == n2)
				System.out.println("Tie");
			else
				System.out.println("Person"+p2.getID()+" won!");
			//n1�� n2�� ���ؼ� ��� ���
			
			System.out.println("Repeat?(y/n)");
			String s = kb.nextLine();
			ch = s.charAt(0);
			//�ݺ� ���� �Է¹޴´�.
			System.out.println();
			System.out.println();
		}
	}
}
class OutOfBoundaryException extends Exception{
	OutOfBoundaryException(String msg) {
		super(msg);
	}
}//������ ��� ���� ����

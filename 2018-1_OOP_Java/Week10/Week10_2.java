import java.util.Scanner;

class Game{
	Scanner kb = new Scanner(System.in);
	private int input, com;
	public void start() {
		System.out.println("���������������� �����մϴ�.");
	}//���� ����
	public void input() {
		try{
			System.out.println("����� ������?");
			System.out.println("����(1) ����(2) ��(3)");
			input = kb.nextInt();
			if(input < 1 || input > 3)
				throw new OutOfBoundaryException("������ �߸��Ǿ����ϴ�.");
			
			com = (int)(Math.random()*3)+1;
			if(com == 1)
				System.out.println("��ǻ�ʹ� ������ �½��ϴ�.");
			else if(com == 2)
				System.out.println("��ǻ�ʹ� ������ �½��ϴ�.");
			else if(com == 3)
				System.out.println("��ǻ�ʹ� ���� �½��ϴ�.");
		}catch(OutOfBoundaryException oe){
			System.out.println(oe.getMessage());
			System.out.println("");
		}
	}//����ڿ��Լ� ���� ���� ���� �Է¹ް� ������ ����� ���� ó��
	//��ǻ�Ͱ� �� ���� ������.
	public int compare() {
		int a = 0;
		if(1<=input && input<=3){
		if(input == com)
			a = 1;
		else if(input+1 == com) //��ǻ��  �̱�
			a = 2;
		else if(input-2 == com) //��ǻ�� �̱�
			a = 2;
		else if(input-1 == com) //��� �̱�
			a = 3;
		else if(input+2 == com) //��� �̱�
			a = 3;
		}		return a;
	}
	public void writeOutput() {
		if(compare()==1){
			System.out.println("���");
			System.out.println("");}
		else if(compare()==2){
			System.out.println("��ǻ�� ��");
			System.out.println("");}
		else if(compare()==3){
			System.out.println("��� ��");
			System.out.println("");}
	}//���� ����� �����ͼ� 1�̸� ��� 2�� ��ǻ�� �� 3�̸� ��� ���� ������ش�.
}
public class Week10_2 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		Game g = new Game();
		int i = 0, j = 0;
		
		g.start();
		while(i<3 && j<3){
			g.input();
			if(g.compare()==3) i++; //����ڰ� �̱�� i ����
			else if(g.compare()==2) j++;//��ǻ�Ͱ� �̱�� j ����
			g.writeOutput();	
		}//���� �ϳ��� 3�� �Ǹ� �ߴ�.
		if(i==3)
			System.out.println("����� �̰���ϴ�.");
		if(j==3)
			System.out.println("��ǻ�Ͱ� �̰���ϴ�.");
		System.out.println("������ �����մϴ�.");
	}
}
class OutOfBoundaryException extends Exception{
	OutOfBoundaryException(String msg) {
		super(msg);
	}
}//������ ��� ���� ����� ����
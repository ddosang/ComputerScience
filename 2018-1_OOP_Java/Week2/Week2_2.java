package fallinlovewithyou;
import java.util.Scanner;

public class Week2_2 {
	public static void main(String[] args) {
	
		Scanner keyb = new Scanner(System.in);
		//�Է� �ޱ� ���� �Է�
		String s1, s2, s3, s4, s5;//���ڿ�
		int leng; //������ ���� leng ����
		
		System.out.println("Enter a line of text.");
		s1 = keyb.nextLine(); //s1�� �� �� �Է� �޴´�.
		
		System.out.println("Your text is \"" + s1 + "\".");
		//������ ������ �Բ� s1�� ����Ѵ�.
		System.out.println("Input a word to replace.");
		s2 = keyb.next(); //���� ���忡�� �ٲٰ� ���� �ܾ �Է� �޴´�.
		System.out.println("Input a word to insert.");
		s3 = keyb.next(); //�տ��� �Է��� �ܾ� �ڸ��� �� �ܾ �Է� �޴´�.
		
		s4 = s1.replace(s2,s3); //s1�� �ִ� s2�� s3���� �ٲ۴�.
		System.out.println("New sentence is \"" + s4 + "\".");
		//������ �Բ� s4�� ����Ѵ�.
		
		leng = s4.length(); //s4�� ���̸� leng�� �����Ѵ�.
		s5 = s4.toUpperCase(); // s4�� ��� ���ڸ� �빮�ڷ� �ٲ۴�
		System.out.println("The length of \"" + s5 + "\" is " + leng + ".");
		//s4�� ������ leng�� ����Ѵ�.
		
	}

}

import java.util.Scanner;
public class Week3_2 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in); //�Է��� ����
		int score, score2;//������ ���� score, score2 ����
		char grade = 'A',ch; //������ ���� grade, ch ����
		String ss; //���ڿ� ss
		do{
			System.out.printf("�����Է�:");
			score = kb.nextInt(); //������ �Է¹޴´�.
			score2 = score/10; // switch���� ����ϱ� ���� 10���� ������.
			
			if(score >= 0 && score <= 100){
			switch(score2){
			case 10:
			case 9: grade = 'A'; break;
			case 8: grade = 'B'; break;
			case 7: grade = 'C'; break;
			case 6: grade = 'D'; break;//break �ʼ�!
			default: grade = 'F';}
			System.out.println("������ "+score+"���̰� "+"grade�� "+grade+"�Դϴ�.");}
			// ������ 0~100 ���� �϶� ������ ���� grade�� Ȯ���� �� ������ grade�� ����Ѵ�.
			
			else{
				System.out.println("������ 0~100�����Դϴ�.");
			}//������ ��� ������ �Է��ϸ� ������ ����
			
			
			
			System.out.println("�ݺ��Ͻðڽ��ϱ�?(y/n)");
			ss = kb.next();
			ch = ss.charAt(0);
		}while(ch == 'y'||ch=='Y');
		//do while���� ����Ͽ� �Է¹��� ss�� �Ǿձ����� ch�� y�� Y�϶� �ݺ�
		System.out.println("����");
	}
}

import java.util.Scanner;
public class Week1_3 {
	public static void main(String[] args){
		
		Scanner keyb = new Scanner(System.in); //��ĵ�� ���� ���ش�.
		
		int Ff; //������ ���� Ff����
		double Cc; //�Ǽ��� ���� Cc����
		
		System.out.printf("ȭ���µ� �Է�: "); 
		Ff = keyb.nextInt();
		//ȭ���µ��� �Է� �޴´�.
		
		System.out.printf("\nȭ���µ�: %d\n",Ff);
		//�Է¹��� ȭ���µ��� ���� ��� ����Ѵ�.
		
		Cc = 5*((double)Ff-32)/9;
		//����ȯ�� �ϰ�, ȭ�� �µ��� ���� �µ��� �ٲٴ� ���� �̿�.
		System.out.printf("�����µ�: %.1f\n",Cc);
		//�����µ� Cc�� ����Ѵ�.
		
	}

}

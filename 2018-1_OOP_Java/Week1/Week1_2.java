import java.util.Scanner;
public class Week1_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner keyb = new Scanner(System.in); //��ĵ�� ���� ���ش�.
		
		int a,b,c; //������ ���� a,b,c ����
		double avg;//�Ǽ��� ���� avg ����
		
		System.out.printf("���� �� �� �Է�\n");
		a = keyb.nextInt();
		b = keyb.nextInt();
		c = keyb.nextInt();
		//���� ������ �Է¹޴´�.
		
		avg = ((double)a+(double)b+(double)c)/3;
		//�Ҽ������� ����ϱ� ���� a,b,c�� double������ ��ȯ�ϰ� 3���� ������.
		System.out.printf("���: %.2f",avg);
		//��հ��� �Ҽ��� ��°�ڸ����� ����Ѵ�.	
	}
}

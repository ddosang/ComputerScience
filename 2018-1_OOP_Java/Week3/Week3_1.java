import java.util.Scanner;
public class Week3_1 {

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		System.out.printf("�� �Է�:");
		int month, date = 0;//������ ���� month, date ����
		month = kb.nextInt();//month�� �Է¹޴´�.
		
		switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			date = 31; break;
			// 1 3 5 7 8 10 12 ���� 31��
			//break�� ���������� �������� �Ӽ��� �̿� : case stacking
			
		case 2:
			date = 28; break;
			//2���� 28��
			
		case 4:
		case 6:
		case 9:
		case 11:
			date = 30; break;
			// 4 6 9 11  ���� 30��
		default:
			System.out.println("�Է� ����"); break;
			//switch���� �̿��Ͽ� 31�� 28�� 30�� �� ���� ������.
		}
		System.out.println(month + "������ "+date+"���� �ֽ��ϴ�.");
		//�Է¹��� ���� �׿� �ش�Ǵ� �� ���� ���.
	}
}

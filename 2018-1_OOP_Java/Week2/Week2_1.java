import java.util.Scanner;
public class Week2_1 {
	public static void main(String[] args){

		int money,bill1,bill2,bill3,bill4,coin1,coin2,coin3,coin4,trash;
		//������ ���� ����
		Scanner keyboard = new Scanner(System.in);
		//�Է� �ޱ� ���� �Է�
		
		System.out.printf("Input the amount of money(0~1000000):");
		money = keyboard.nextInt();
		//�ݾ��� �Է��Ѵ�.
		
		bill1 = money / 50000;
		bill2 = money % 50000 / 10000;
		bill3 = money % 50000 % 10000 / 5000;
		bill4 = money % 50000 % 10000 % 5000 / 1000;
		coin1 = money % 50000 % 10000 % 5000 % 1000 / 500;
		coin2 = money % 50000 % 10000 % 5000 % 1000 % 500 / 100;
		coin3 = money % 50000 % 10000 % 5000 % 1000 % 500 % 100 / 50;
		coin4 = money % 50000 % 10000 % 5000 % 1000 % 500 % 100 % 50 / 10;
		trash = money % 50000 % 10000 % 5000 % 1000 % 500 % 100 % 50 % 10;
		//�Է¹��� ������ ������ 50000�� �ϸ� 50000���� �� ���̳� ���� ���� ������
		//�� �������� ���� �ܰ��� 10000���� ������ 10000���� �� ���̳� ������ �� ���´�. 
		//���� ���� ������ŭ �ݺ����ش�.
		
		
		System.out.println("The output will be");
		System.out.printf("50000 won : %d\n",bill1);
		System.out.printf("10000 won : %d\n",bill2);
		System.out.printf("5000 won : %d\n",bill3);
		System.out.printf("1000 won : %d\n",bill4);
		System.out.printf("500 won : %d\n",coin1);
		System.out.printf("100 won : %d\n",coin2);
		System.out.printf("50 won : %d\n",coin3);
		System.out.printf("10 won : %d\n",coin4);
		System.out.printf("Remainder: %d\n",trash);
		// _____ won : ���� �� �� �������� ����Ѵ�.
	}
}


import java.util.Scanner;
public class Week1_1 {
	public static void main(String[] args){
		
		System.out.printf("Input base:");
		//Input base: ���
		
		int base, height;//base, height��� ������ ���� ����
		double area;//area ��� �Ǽ��� ���� ����
		
		Scanner keyboard = new Scanner(System.in);//��ĵ�� ���� ���ش�.
		base = keyboard.nextInt();// base �Է¹���
		
		System.out.printf("Input height:");
		height = keyboard.nextInt();
		//Input height: �� ����ϰ� height�� �Է¹���
		
		area = (double)base*(double)height/2;
		//base�� height�� double�� ����ȯ �� �� �ﰢ�� ���� ����
		
		System.out.println("The area:"+area);
		//The area: �� area�� ���
	}
}

package fallinlovewithyou;

import java.util.Scanner;
public class Week3_3 {

	public static void main(String[] args) {
		
		int inte,fac=1;
		Scanner kb = new Scanner(System.in);
		
		System.out.println("Factorial�� ����� ���� �Է�");
		inte = kb.nextInt();
		
		while(inte>10||inte<=0){
			System.out.println("���� ���Է�(1~10):");
			inte = kb.nextInt();
			}
		//while ���� �̿��ؼ� inte�� ������ ����� �ݺ��ؼ� ���Է� �޴´�.
		
		if(inte>0 && inte<=10){
			System.out.printf("%d! = ",inte);
			for(int i = inte; i>0; i--){
				fac = fac*i;
			} //inte�� ���� �ȿ� ������ fac �� ����Ѵ�.
		
			for(int i = inte; i>0;i--){
				if(i>1){
					System.out.printf("%d X ",i);}
				else
					System.out.printf("%d = %d",i,fac);
			}//inte = 5��� 5! = 5 X 4 X 3 X 2 X 1 = 120 ���·� ����� �ش�.
		}
	}
}


import java.util.Scanner;

public class HW1_3 {
	public static void main(String[] args){
		
		Scanner kb = new Scanner(System.in);
		char Arr[] = new char[100];
		String s1 = "y";

		while(s1.equalsIgnoreCase("y")){
			System.out.println("Input a word");
			String str = kb.next();
			Arr = str.toCharArray();
			//�ܾ string���� �Է¹޾� chararray���·� ��ȯ�Ѵ�.
		
			boolean tf = check(Arr);
			//tf��� boolean�� ������ �����ϰ�, check(Arr)�� ���� ����
		
			if(tf == true){
				System.out.println("symmetry\n");
			}
			else{
				System.out.println("Asymmetry\n");
			}//tf���� true �̸� symmetry false�̸� asymmetry ���
			
			System.out.printf("Try again?(y/n)");
			s1 = kb.next();
			System.out.println("");
			//�Է� ���� ���� y�� Y�̸� �ݺ�
		}	
	}
	
	//char array�� input������ �ް� boolean type�� return�ϴ� �޼��� check
	public static boolean check(char[] Arr){
		String a = new String(Arr); // input������ ���� array�� string���� ��ȯ�Ͽ� a�� ����
		boolean c = false; //boolean�� ���� c ����, �ʱ�ȭ
		for(int i = 0; i < a.length()/2; i++){
			if(Arr[i] == Arr[a.length()-i-1]){
				 c = true;
			}//���ؼ� ��Ī�̸� c���� true
			else{
				c = false;
				break;//��Ī�� �ƴϸ� c���� false�� ������ �ݺ����� �������´�.
			}
		}
		return c;//c���� return �Ѵ�
	}
}

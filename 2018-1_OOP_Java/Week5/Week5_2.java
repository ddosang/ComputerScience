import java.util.Scanner;

class Facto{
	static int result; //Ŭ���� ���� result ����
	
	static int facto_sum(int x){
		int fac = 1; //�������� fac�� �ʱ�ȭ �ʿ�
		for(int i = 1; i <= x ; i++){
			fac *= i;
		} // �ݺ��� for���� �̿��� x! ���.
		return fac; //fac���� ��ȯ�Ѵ�.
	}//������ ���� 1���� ������ static �޼��� facto_sum
}

class Week5_2 {
	public static void main(String[] args){

		int n1, n2, fac_n1, fac_n2; // ������ ���� 5�� ����.
		Scanner kb = new Scanner(System.in); // �Է��� ����
		
		System.out.printf("ù��° ���� �Է�:"); 
		n1 = kb.nextInt();
		System.out.printf("�ι�° ���� �Է�:");
		n2 = kb.nextInt();
		//���� �ΰ��� �Է¹޴´�.
		
		fac_n1 = Facto.facto_sum(n1);
		fac_n2 = Facto.facto_sum(n2);
		//Facto Ŭ���� ���� facto_sum Ŭ���� �޼��带 �̿��Ͽ� n1!, n2! ���.
		
		Facto.result = fac_n1 - fac_n2;
		//�� ���丮�� ���� ���̸� Ŭ���� ���� result�� ����.
		
		System.out.println("Factorial(" + n1 + ") - Factorial(" + n2 + ") = "+Facto.result );
		//Factorial(n1) - Factorial(n2) = Facto.result ���·� ���.
	}
}

import java.util.Scanner;
public class Week3_4 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		int height;
		char ch = ' ';
		
		System.out.printf("Enter the height of the triange : ");
		height = kb.nextInt();
		//���̸� �Է¹޴´�.
		
		for(int i = 1; i<=height;i++){
			for(int m =10; m >=1 ; m--)
				if(m>i)
					System.out.printf(" ");
			//���⸦ m�� (m-1)�� (m-2)�� . . . 0�� �̷��� �����Ѵ�.
				for(int j = 1; j <= 2*height; j ++){
					if(j<2*i){
						System.out.printf("*");
						//*�� 1�� 3�� ... 2n-1�� ����Ѵ�.
						}
			}
			System.out.printf("\n");
		}
	}
}

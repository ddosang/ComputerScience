import java.util.Scanner;
public class Week3_4 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		int height;
		char ch = ' ';
		
		System.out.printf("Enter the height of the triange : ");
		height = kb.nextInt();
		//높이를 입력받는다.
		
		for(int i = 1; i<=height;i++){
			for(int m =10; m >=1 ; m--)
				if(m>i)
					System.out.printf(" ");
			//띄어쓰기를 m번 (m-1)번 (m-2)번 . . . 0번 이렇게 진행한다.
				for(int j = 1; j <= 2*height; j ++){
					if(j<2*i){
						System.out.printf("*");
						//*을 1개 3개 ... 2n-1개 출력한다.
						}
			}
			System.out.printf("\n");
		}
	}
}

package fallinlovewithyou;

import java.util.Scanner;
public class Week3_3 {

	public static void main(String[] args) {
		
		int inte,fac=1;
		Scanner kb = new Scanner(System.in);
		
		System.out.println("Factorial을 계산할 정수 입력");
		inte = kb.nextInt();
		
		while(inte>10||inte<=0){
			System.out.println("정수 재입력(1~10):");
			inte = kb.nextInt();
			}
		//while 문을 이용해서 inte가 범위를 벗어날때 반복해서 재입력 받는다.
		
		if(inte>0 && inte<=10){
			System.out.printf("%d! = ",inte);
			for(int i = inte; i>0; i--){
				fac = fac*i;
			} //inte가 범위 안에 있을때 fac 을 계산한다.
		
			for(int i = inte; i>0;i--){
				if(i>1){
					System.out.printf("%d X ",i);}
				else
					System.out.printf("%d = %d",i,fac);
			}//inte = 5라면 5! = 5 X 4 X 3 X 2 X 1 = 120 형태로 출력해 준다.
		}
	}
}

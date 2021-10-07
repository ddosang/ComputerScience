import java.util.Scanner;
public class Week2_1 {
	public static void main(String[] args){

		int money,bill1,bill2,bill3,bill4,coin1,coin2,coin3,coin4,trash;
		//정수형 변수 선언
		Scanner keyboard = new Scanner(System.in);
		//입력 받기 위해 입력
		
		System.out.printf("Input the amount of money(0~1000000):");
		money = keyboard.nextInt();
		//금액을 입력한다.
		
		bill1 = money / 50000;
		bill2 = money % 50000 / 10000;
		bill3 = money % 50000 % 10000 / 5000;
		bill4 = money % 50000 % 10000 % 5000 / 1000;
		coin1 = money % 50000 % 10000 % 5000 % 1000 / 500;
		coin2 = money % 50000 % 10000 % 5000 % 1000 % 500 / 100;
		coin3 = money % 50000 % 10000 % 5000 % 1000 % 500 % 100 / 50;
		coin4 = money % 50000 % 10000 % 5000 % 1000 % 500 % 100 % 50 / 10;
		trash = money % 50000 % 10000 % 5000 % 1000 % 500 % 100 % 50 % 10;
		//입력받은 돈에서 나누기 50000을 하면 50000원을 몇 장이나 내야 할지 나오고
		//그 나머지를 다음 단계인 10000으로 나누면 10000원을 몇 장이나 내야할 지 나온다. 
		//따라서 돈의 종류만큼 반복해준다.
		
		
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
		// _____ won : 돈을 몇 장 내야할지 출력한다.
	}
}

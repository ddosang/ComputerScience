
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
			//단어를 string으로 입력받아 chararray형태로 변환한다.
		
			boolean tf = check(Arr);
			//tf라는 boolean형 변수를 선언하고, check(Arr)의 값을 대입
		
			if(tf == true){
				System.out.println("symmetry\n");
			}
			else{
				System.out.println("Asymmetry\n");
			}//tf값이 true 이면 symmetry false이면 asymmetry 출력
			
			System.out.printf("Try again?(y/n)");
			s1 = kb.next();
			System.out.println("");
			//입력 받은 값이 y나 Y이면 반복
		}	
	}
	
	//char array를 input값으로 받고 boolean type을 return하는 메서드 check
	public static boolean check(char[] Arr){
		String a = new String(Arr); // input값으로 받은 array를 string으로 변환하여 a에 대입
		boolean c = false; //boolean형 변수 c 선언, 초기화
		for(int i = 0; i < a.length()/2; i++){
			if(Arr[i] == Arr[a.length()-i-1]){
				 c = true;
			}//비교해서 대칭이면 c값이 true
			else{
				c = false;
				break;//대칭이 아니면 c값이 false가 나오고 반복문을 빠져나온다.
			}
		}
		return c;//c값을 return 한다
	}
}

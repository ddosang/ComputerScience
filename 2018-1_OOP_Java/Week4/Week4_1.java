import java.util.Scanner;

class Song{
	String title,singer;
	int price;
	//문자열 변수 title, singer, 정수형 변수 price 선언
	
	void play(){
		System.out.println("노래들어요 : \"" + title +"\" by "+ singer);
	}//화면에 정해진 문장을 출력하는 메서드 play를 만든다.
	void price(){
		System.out.println(price+"원입니다.");
	}//화면에 정해진 문장을 출력하는 메서드 price를 만든다.
} // song 클래스 생성

public class Week4_1 {
	public static void main(String[] args){
	
	int input; //정수형 변수 input 선언
	Scanner kb = new Scanner(System.in); //입력을 위해

	Song song1 = new Song();
	Song song2 = new Song();
	//Song 오브젝트를 두 개 생성한다.
	
	System.out.println("*Song 1*");
	System.out.printf("곡명입력:");
	song1.title = kb.nextLine();
	System.out.printf("가수명입력:");
	song1.singer = kb.nextLine();
	System.out.printf("가격입력:");
	song1.price = kb.nextInt();
	kb.nextLine();
	System.out.println("");
	//song1의 곡명, 가수명, 가격을 입력받는다.
	
	System.out.println("*Song 2*");
	System.out.printf("곡명입력:");
	song2.title = kb.nextLine();
	System.out.printf("가수명입력:");
	song2.singer = kb.nextLine();
	System.out.printf("가격입력:");
	song2.price = kb.nextInt();
	System.out.println("");
	//song2의 곡명, 가수명, 가격을 입력받는다.
	
	System.out.println("노래를 고르세요");
	System.out.println("1:"+song1.title+" 2:"+song2.title);
	input = kb.nextInt(); //노래 번호를 입력받는다.
	if(input == 1){
	song1.play();
	song1.price();
	System.out.println("감사합니다.");
	}//1번이면 song1 play, price
	else if(input == 2){
		song2.play();
		song2.price();
		System.out.println("감사합니다.");
	}//2번이면 song2 play, price
	}
}

import java.util.Scanner;

class Song{
	String title,singer;
	int price;
	//문자열 변수 title, singer, 정수형 변수 price 선언
	
	Song(){}//생성자 default 정의
	
	Song(String title, int price){
		this(title, "모름", price);
	}// 인자가 String title, int price 인 생성자
	
	Song(String title, String singer, int price){
		set(title, singer, price);
	}// 인자가 String title, String singer, int price 인 생성자
	
	public void play(int n){
		for(int i=1 ; i<=n ; i++){
			System.out.println(title + " by " + singer);}
		}//화면에 "제목 by 가수" 를 출력하는 메서드 play를 만든다.
	
	void price(int n){
		System.out.println("총 " + n*price+"원입니다.");	
	}//화면에 n번 반복한 후 가격을 출력하는 메서드 price를 만든다.	
	
	private void set(String nextTitle, String nextSinger, int nextPrice){
		title = nextTitle;
		singer = nextSinger;
		price = nextPrice;
	}//set 안의 인자로 title, singer, price를 정해주는 private 메서드
	
} // song 클래스 생성

public class Week5_1 {
	public static void main(String[] args){
	
	String title, singer;//문자열 title, singer 선언
	int input, n, price; //정수형 변수 input, n 선언
	Scanner kb = new Scanner(System.in); //입력을 위해

	Song song;
	//Song 타입 참조변수 song 선언.
	
	
	System.out.println("*Song 정보*");
	System.out.printf("곡명:");
	title = kb.nextLine();
	// title을 입력받은 뒤, title에 대입

	while(title.equals("")){
		System.out.println("곡명은 반드시 필요합니다.");
		System.out.printf("곡명:");
		title = kb.nextLine();
	}//곡명이 없는 경우 반복 질문해서 받음
	
	System.out.printf("가수명:");
	singer = kb.nextLine();
	
	System.out.printf("가격:");
	price = kb.nextInt();
	kb.nextLine();
	//가수와 가격 정보 입력 받은 뒤, 각각 singer, price에 대입
	
	
	if(singer.equals("")){
		song = new Song(title, price);
	}
	else{
		song = new Song(title, singer, price);
	}//가수 정보가 없을 시 인자가 2개인 Song 생성자를 이용해 객체를 생성한다.
	//가수 정보가 있을 시 인자가 3개인 Song 생성자를 이용해 객체를 생성한다.
	
	System.out.println("몇번 들으시겠습니까?");
	n = kb.nextInt();
	song.play(n);
	song.price(n);
	//song1의 곡명, 가수명, 가격을 입력받는다.
	}
}


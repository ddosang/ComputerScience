import java.util.Scanner;
class Production{// Production class
	private String title, director, writer;
	
	public String getTitle(){
		return title;
	}
	public String getDirector(){
		return director;
	}
	public String getWriter(){
		return writer;
	}//getter method
	public void setTitle(String title){
		this.title = title;
	}
	public void setDirector(String director){
		this.director = director;
	}
	public void setWriter(String writer){
		this.writer = writer;
	}//setter method
	public void display(){
		System.out.printf("title:%s\n", title);
		System.out.printf("director:%s\n", director);
		System.out.printf("writer:%s\n", writer);
	}//제목 감독 작가를 출력해주는 메서드 display
	
	Production(){
		this(null, null, null);
	}//생성자에 아무것도 입력되지 않으면 null값 전송
	Production(String title, String director, String writer){
		this.setTitle(title);
		this.setDirector(director);
		this.setWriter(writer);
	}//Production 생성자 만든다.
}

class Play extends Production{ //Production 상속받은 Play class
	private int performanceCost;
	
	public int getPerformanceCost(){
		return performanceCost;
	} //getter method
	public void setPerformanceCost(int performanceCost){
		this.performanceCost = performanceCost;
	} //setter method
	public void display(){
		System.out.printf("title:%s\n", super.getTitle());
		System.out.printf("director:%s\n", super.getDirector());
		System.out.printf("writer:%s\n", super.getWriter());
		System.out.println("performance cost:"+performanceCost);
	} //display method overriding
	Play(){
		this(0);
	}
	Play(int performanceCost){
		super();
		this.setPerformanceCost(performanceCost);
	} //play method overroading 
	//Production의 생성자 부르고 performanceCost set
}

class Film extends Production{ //Production 상속받은 Film class
private int boxOfficeGross;
	
	public int getboxOfficeGross(){
		return boxOfficeGross;
	}//getter
	public void setboxOfficeGross(int boxOfficeGross){
		this.boxOfficeGross = boxOfficeGross;
	}//setter
	public void display(){
		System.out.printf("title:%s\n", super.getTitle());
		System.out.printf("director:%s\n", super.getDirector());
		System.out.printf("writer:%s\n", super.getWriter());
		System.out.println("boxOfficeGross:"+boxOfficeGross);
	}//display method overriding
	Film(){
		this(0);
	}
	Film(int boxOfficeGross){
		super();
		this.setboxOfficeGross(boxOfficeGross);
	}//Film method overroading
	//Production의 생성자 부르고 boxOfficeGross set
}
public class Week6_1 {
	public static void main(String[] args){
		
		Scanner kb = new Scanner(System.in);
		
		Play p = new Play();
		Film f = new Film();
		// 자식 클래스 Play, Film의 인스턴스 생성
		
		System.out.println("Input Title for Play");
		p.setTitle(kb.nextLine());
		System.out.println("Input Director for Play");
		p.setDirector(kb.nextLine());
		System.out.println("Input Writer for Play");
		p.setWriter(kb.nextLine());
		//부모 클래스의 method를 이용해 p의 title, director. writer 설정
		
		System.out.println("Input Title for Play");
		f.setTitle(kb.nextLine());
		System.out.println("Input Director for Play");
		f.setDirector(kb.nextLine());
		System.out.println("Input Writer for Play");
		f.setWriter(kb.nextLine());
		//부모 클래스의 method를 이용해 f의 title, director. writer 설정
		
		System.out.println("Input Performance Cost for Play");
		p.setPerformanceCost(kb.nextInt());
		//Play의 method를 이용해 p의 performanceCost 설정
		
		System.out.println("Input Performance for Film");
		f.setboxOfficeGross(kb.nextInt());
		//Film의 method를 이용해 f의 boxOfficeGross 설정
		
		p.display(); //p안의 정보들을 출력
		System.out.println("");
		f.display(); //f안의 정보들을 출력
	}
}

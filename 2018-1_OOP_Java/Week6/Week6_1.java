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
	}//���� ���� �۰��� ������ִ� �޼��� display
	
	Production(){
		this(null, null, null);
	}//�����ڿ� �ƹ��͵� �Էµ��� ������ null�� ����
	Production(String title, String director, String writer){
		this.setTitle(title);
		this.setDirector(director);
		this.setWriter(writer);
	}//Production ������ �����.
}

class Play extends Production{ //Production ��ӹ��� Play class
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
	//Production�� ������ �θ��� performanceCost set
}

class Film extends Production{ //Production ��ӹ��� Film class
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
	//Production�� ������ �θ��� boxOfficeGross set
}
public class Week6_1 {
	public static void main(String[] args){
		
		Scanner kb = new Scanner(System.in);
		
		Play p = new Play();
		Film f = new Film();
		// �ڽ� Ŭ���� Play, Film�� �ν��Ͻ� ����
		
		System.out.println("Input Title for Play");
		p.setTitle(kb.nextLine());
		System.out.println("Input Director for Play");
		p.setDirector(kb.nextLine());
		System.out.println("Input Writer for Play");
		p.setWriter(kb.nextLine());
		//�θ� Ŭ������ method�� �̿��� p�� title, director. writer ����
		
		System.out.println("Input Title for Play");
		f.setTitle(kb.nextLine());
		System.out.println("Input Director for Play");
		f.setDirector(kb.nextLine());
		System.out.println("Input Writer for Play");
		f.setWriter(kb.nextLine());
		//�θ� Ŭ������ method�� �̿��� f�� title, director. writer ����
		
		System.out.println("Input Performance Cost for Play");
		p.setPerformanceCost(kb.nextInt());
		//Play�� method�� �̿��� p�� performanceCost ����
		
		System.out.println("Input Performance for Film");
		f.setboxOfficeGross(kb.nextInt());
		//Film�� method�� �̿��� f�� boxOfficeGross ����
		
		p.display(); //p���� �������� ���
		System.out.println("");
		f.display(); //f���� �������� ���
	}
}

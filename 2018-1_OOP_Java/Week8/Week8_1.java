import java.util.Scanner;

class Product{
	int price;
	int bonusPoint;
	Product(int price){
		this.price = price;
		bonusPoint = (int)(price/10.0);
	}
}//Product class 생성
class Tv extends Product{
	int price;
	int bonusPoint;
	Tv(){
		super(100);
	}
	public String toString() {
		return "Tv";
	}
}//Product class를 상속받는 Tv class 생성
class Computer extends Product{
	int price;
	int bonusPoint;
	Computer(){
		super(200);
	}
	public String toString() {
		return "Computer";
	}
}//Product class를 상속받는 Computer class 생성
class Video extends Product{
	int price;
	int bonusPoint;
	Video(){
		super(110);
	}
	public String toString() {
		return "Video";
	}
}//Product class를 상속받는 Video class 생성
class Audio extends Product{
	int price;
	int bonusPoint;
	Audio(){
		super(50);
	}
	public String toString() {
		return "Audio";
	}
}//Product class를 상속받는 Audio class 생성
class NoteBook extends Product{
	int price;
	int bonusPoint;
	NoteBook(){
		super(300);
	}
	public String toString() {
		return "NoteBook";
	}
}//Product class를 상속받는 Notebook class 생성


class Buyer{
	int money = 0, i;
	int bonusPoint = 0;
	Product item[] = new Product[10];
	
	void buy(Product p) {
		if(p.price>money) {
			System.out.println("\nMoney is not enough.\n");
			summary();
			System.exit(0);
		}
		System.out.println("You bought" + p + "(" + p.price +")");
		money -= p.price;
		bonusPoint += p.bonusPoint;
		item[i++] = p;
	}//Product 인스턴스를  input값으로 하고 산 물건과 값을 말해주고
	//잔고와 포인트를 정리하고 product배열에 산 물건 목록을 저장하는 메서드 buy
	void summary() {
		System.out.printf("SHOPPING LIST: ");
		for(int j = 0; j < i ; j++)
			System.out.print(item[j]+" ");
		System.out.println("\n"+"MONEY LEFT: "+money);
		System.out.println("CURRENT BONUS POINT: "+bonusPoint);
	}//쇼핑한 목록과 남은 돈 쌓인 포인트를 알려주는 메서드 summary
}//Buyer class 생성

public class Week8_1 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		Buyer b = new Buyer();
		int saveChoice[] = new int[10];
		Product p[] = new Product[5];
		//Buyer class 의 인스턴스 choice를 저장하기 위한 int 배열 saveChoice Product 배열 생성
		
		Tv t = new Tv();
		Computer c = new Computer();
		Video v = new Video();
		Audio a = new Audio();
		NoteBook n = new NoteBook();
		//class 별 인스턴스 생성
				
		int money=0, bonusPoint=0, choice=1, i=0;
		
		System.out.println("How much do you have?");
		money = kb.nextInt();
		
		b.money = money;
		b.bonusPoint = bonusPoint;
		
		while(true){
			System.out.println("What do you want to but? Input 0 to quit.");
			System.out.printf("1. Tv(100)\t 2.Computer(200)\t 3.Video(110)\t 4.Audio(50)\t 5.NoteBook(300)\n");
			choice = kb.nextInt();
			saveChoice[i++] = choice; //choice를 입력받고 i를 1 증가시킨다
			
			if(choice == 0){
				break;
			} //choice 가 0 일때 반복문을 빠져나간다
			else if(choice == 1) {
				b.buy(t);
			}
			else if(choice == 2) {
				b.buy(c);
			}
			else if(choice == 3) {
				b.buy(v);
			}
			else if(choice == 4) {
				b.buy(a);
			}
			else if(choice == 5) {
				b.buy(n);
			}//choice가 1~5이면 숫자와 맞는 class를 buy 메서드에 input 값으로 넣는다.
			else {
				System.out.println("No such item.");
			} //choice가 그 밖의 것이면 No such item.을 출력한다.
		}
		b.summary();
	}
}

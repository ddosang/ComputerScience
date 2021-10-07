import java.util.Scanner;

class Product{
	int price;
	int bonusPoint;
	Product(int price){
		this.price = price;
		bonusPoint = (int)(price/10.0);
	}
}//Product class ����
class Tv extends Product{
	int price;
	int bonusPoint;
	Tv(){
		super(100);
	}
	public String toString() {
		return "Tv";
	}
}//Product class�� ��ӹ޴� Tv class ����
class Computer extends Product{
	int price;
	int bonusPoint;
	Computer(){
		super(200);
	}
	public String toString() {
		return "Computer";
	}
}//Product class�� ��ӹ޴� Computer class ����
class Video extends Product{
	int price;
	int bonusPoint;
	Video(){
		super(110);
	}
	public String toString() {
		return "Video";
	}
}//Product class�� ��ӹ޴� Video class ����
class Audio extends Product{
	int price;
	int bonusPoint;
	Audio(){
		super(50);
	}
	public String toString() {
		return "Audio";
	}
}//Product class�� ��ӹ޴� Audio class ����
class NoteBook extends Product{
	int price;
	int bonusPoint;
	NoteBook(){
		super(300);
	}
	public String toString() {
		return "NoteBook";
	}
}//Product class�� ��ӹ޴� Notebook class ����


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
	}//Product �ν��Ͻ���  input������ �ϰ� �� ���ǰ� ���� �����ְ�
	//�ܰ�� ����Ʈ�� �����ϰ� product�迭�� �� ���� ����� �����ϴ� �޼��� buy
	void summary() {
		System.out.printf("SHOPPING LIST: ");
		for(int j = 0; j < i ; j++)
			System.out.print(item[j]+" ");
		System.out.println("\n"+"MONEY LEFT: "+money);
		System.out.println("CURRENT BONUS POINT: "+bonusPoint);
	}//������ ��ϰ� ���� �� ���� ����Ʈ�� �˷��ִ� �޼��� summary
}//Buyer class ����

public class Week8_1 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		Buyer b = new Buyer();
		int saveChoice[] = new int[10];
		Product p[] = new Product[5];
		//Buyer class �� �ν��Ͻ� choice�� �����ϱ� ���� int �迭 saveChoice Product �迭 ����
		
		Tv t = new Tv();
		Computer c = new Computer();
		Video v = new Video();
		Audio a = new Audio();
		NoteBook n = new NoteBook();
		//class �� �ν��Ͻ� ����
				
		int money=0, bonusPoint=0, choice=1, i=0;
		
		System.out.println("How much do you have?");
		money = kb.nextInt();
		
		b.money = money;
		b.bonusPoint = bonusPoint;
		
		while(true){
			System.out.println("What do you want to but? Input 0 to quit.");
			System.out.printf("1. Tv(100)\t 2.Computer(200)\t 3.Video(110)\t 4.Audio(50)\t 5.NoteBook(300)\n");
			choice = kb.nextInt();
			saveChoice[i++] = choice; //choice�� �Է¹ް� i�� 1 ������Ų��
			
			if(choice == 0){
				break;
			} //choice �� 0 �϶� �ݺ����� ����������
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
			}//choice�� 1~5�̸� ���ڿ� �´� class�� buy �޼��忡 input ������ �ִ´�.
			else {
				System.out.println("No such item.");
			} //choice�� �� ���� ���̸� No such item.�� ����Ѵ�.
		}
		b.summary();
	}
}

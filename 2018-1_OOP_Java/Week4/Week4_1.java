import java.util.Scanner;

class Song{
	String title,singer;
	int price;
	//���ڿ� ���� title, singer, ������ ���� price ����
	
	void play(){
		System.out.println("�뷡���� : \"" + title +"\" by "+ singer);
	}//ȭ�鿡 ������ ������ ����ϴ� �޼��� play�� �����.
	void price(){
		System.out.println(price+"���Դϴ�.");
	}//ȭ�鿡 ������ ������ ����ϴ� �޼��� price�� �����.
} // song Ŭ���� ����

public class Week4_1 {
	public static void main(String[] args){
	
	int input; //������ ���� input ����
	Scanner kb = new Scanner(System.in); //�Է��� ����

	Song song1 = new Song();
	Song song2 = new Song();
	//Song ������Ʈ�� �� �� �����Ѵ�.
	
	System.out.println("*Song 1*");
	System.out.printf("����Է�:");
	song1.title = kb.nextLine();
	System.out.printf("�������Է�:");
	song1.singer = kb.nextLine();
	System.out.printf("�����Է�:");
	song1.price = kb.nextInt();
	kb.nextLine();
	System.out.println("");
	//song1�� ���, ������, ������ �Է¹޴´�.
	
	System.out.println("*Song 2*");
	System.out.printf("����Է�:");
	song2.title = kb.nextLine();
	System.out.printf("�������Է�:");
	song2.singer = kb.nextLine();
	System.out.printf("�����Է�:");
	song2.price = kb.nextInt();
	System.out.println("");
	//song2�� ���, ������, ������ �Է¹޴´�.
	
	System.out.println("�뷡�� ������");
	System.out.println("1:"+song1.title+" 2:"+song2.title);
	input = kb.nextInt(); //�뷡 ��ȣ�� �Է¹޴´�.
	if(input == 1){
	song1.play();
	song1.price();
	System.out.println("�����մϴ�.");
	}//1���̸� song1 play, price
	else if(input == 2){
		song2.play();
		song2.price();
		System.out.println("�����մϴ�.");
	}//2���̸� song2 play, price
	}
}

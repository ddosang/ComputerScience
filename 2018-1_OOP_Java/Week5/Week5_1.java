import java.util.Scanner;

class Song{
	String title,singer;
	int price;
	//���ڿ� ���� title, singer, ������ ���� price ����
	
	Song(){}//������ default ����
	
	Song(String title, int price){
		this(title, "��", price);
	}// ���ڰ� String title, int price �� ������
	
	Song(String title, String singer, int price){
		set(title, singer, price);
	}// ���ڰ� String title, String singer, int price �� ������
	
	public void play(int n){
		for(int i=1 ; i<=n ; i++){
			System.out.println(title + " by " + singer);}
		}//ȭ�鿡 "���� by ����" �� ����ϴ� �޼��� play�� �����.
	
	void price(int n){
		System.out.println("�� " + n*price+"���Դϴ�.");	
	}//ȭ�鿡 n�� �ݺ��� �� ������ ����ϴ� �޼��� price�� �����.	
	
	private void set(String nextTitle, String nextSinger, int nextPrice){
		title = nextTitle;
		singer = nextSinger;
		price = nextPrice;
	}//set ���� ���ڷ� title, singer, price�� �����ִ� private �޼���
	
} // song Ŭ���� ����

public class Week5_1 {
	public static void main(String[] args){
	
	String title, singer;//���ڿ� title, singer ����
	int input, n, price; //������ ���� input, n ����
	Scanner kb = new Scanner(System.in); //�Է��� ����

	Song song;
	//Song Ÿ�� �������� song ����.
	
	
	System.out.println("*Song ����*");
	System.out.printf("���:");
	title = kb.nextLine();
	// title�� �Է¹��� ��, title�� ����

	while(title.equals("")){
		System.out.println("����� �ݵ�� �ʿ��մϴ�.");
		System.out.printf("���:");
		title = kb.nextLine();
	}//����� ���� ��� �ݺ� �����ؼ� ����
	
	System.out.printf("������:");
	singer = kb.nextLine();
	
	System.out.printf("����:");
	price = kb.nextInt();
	kb.nextLine();
	//������ ���� ���� �Է� ���� ��, ���� singer, price�� ����
	
	
	if(singer.equals("")){
		song = new Song(title, price);
	}
	else{
		song = new Song(title, singer, price);
	}//���� ������ ���� �� ���ڰ� 2���� Song �����ڸ� �̿��� ��ü�� �����Ѵ�.
	//���� ������ ���� �� ���ڰ� 3���� Song �����ڸ� �̿��� ��ü�� �����Ѵ�.
	
	System.out.println("��� �����ðڽ��ϱ�?");
	n = kb.nextInt();
	song.play(n);
	song.price(n);
	//song1�� ���, ������, ������ �Է¹޴´�.
	}
}


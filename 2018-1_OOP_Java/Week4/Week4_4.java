import java.util.Scanner;
class MenuOrder{
	private int cokePrice, lemonadePrice, coffeePrice, inputMoney; //�ν��Ͻ� ���� ����
	private String drinkSelected; //�ν��Ͻ� ���� string ����
	
	public void setPrice(String drinkSelected, int price){
		if(drinkSelected =="1")
			cokePrice = price;
		else if(drinkSelected =="2")
			lemonadePrice = price;
		else if(drinkSelected =="3")	
			coffeePrice = price;
	} // drinkSelected �� ���� ���� � ��ǰ ���ݿ� ������ ����.
	
	public void showMenu(){
		System.out.println("1. Coke: " + cokePrice);
		System.out.println("2. Lemonade: " + lemonadePrice);
		System.out.println("3. Coffee: " + coffeePrice);
	}//�޴��� ������
	
	public void money(int money) {
		inputMoney = money;
	}//money�� inputMoney�� ����.
	
	public void showResult(int input){
		
		if(input == 1){
			System.out.println("Coke�� �����ϼ̽��ϴ�.");
			if(inputMoney-cokePrice>0)
				System.out.println("�ܵ��� "+(inputMoney-cokePrice)+"���Դϴ�.");
			else if(inputMoney-cokePrice==0)
				System.out.println("�ܵ��� �����ϴ�.");
			else
				System.out.println((cokePrice-inputMoney)+"�� �� �־��ּ���.");
		}//1���̸� coke ���ݿ� ���߾� ����� ����Ѵ�.
		else if(input == 2){
			System.out.println("Lemonade�� �����ϼ̽��ϴ�.");
			if(inputMoney-lemonadePrice>0)
				System.out.println("�ܵ���"+(inputMoney-lemonadePrice)+"�Դϴ�.");
			else if(inputMoney-lemonadePrice==0)
				System.out.println("�ܵ��� �����ϴ�.");
			else
				System.out.println((lemonadePrice-inputMoney)+"�� �� �־��ּ���.");
		}//2���̸� coke ���ݿ� ���߾� ����� ����Ѵ�.
		else if(input == 3){
			System.out.println("Coffee�� �����ϼ̽��ϴ�.");
			if((inputMoney-coffeePrice)>0)
				System.out.println("�ܵ���"+(inputMoney-coffeePrice)+"�Դϴ�.");
			else if(inputMoney-coffeePrice==0)
				System.out.println("�ܵ��� �����ϴ�.");
			else
				System.out.println((coffeePrice-inputMoney)+"�� �� �־��ּ���.");
			
		}//3���̸� coke ���ݿ� ���߾� ����� ����Ѵ�.
		else{
			System.out.println("���� �޴��� �����ϼ̽��ϴ�.");
		}//1 2 3 ���� �ƴϸ� ���� �޴��� �����ߴٰ� �˷��ش�.
	}
}
public class Week4_1 {
	public static void main(String[] args){
		
		Scanner kb = new Scanner(System.in);
		
		MenuOrder mo = new MenuOrder(); //�޴����� ������Ʈ mo ����.
		
		String s = "y";
		
		System.out.println("--- ���ᰡ�� ���� ---");
		System.out.printf("Coke����:");
		mo.setPrice("1", kb.nextInt()); 
		System.out.printf("Lemonade����:");
		mo.setPrice("2", kb.nextInt());
		System.out.printf("Coffee����:");
		mo.setPrice("3", kb.nextInt());
		System.out.println("");
		//������ ��� ȭ���� ���� ��, string�� �Է¹��� �ʿ䰡 �����Ƿ� ������� �������ְ�,
		//������ ������ �Է¹޴´�.
		
		
		
		while(s.equalsIgnoreCase("y")||s.equalsIgnoreCase("Y")){
		System.out.println("--- ���� �������� ---");
		mo.money(kb.nextInt());
		//�ִ� ���� �Է¹޾� �ν��Ͻ� ������ �ִ´�.
		
		System.out.println("--- ���Ḧ �����ϼ��� ---");
		mo.showMenu(); //�޴��� �����ش�.
		
		mo.showResult(kb.nextInt()); //�޴��� ���� (���ڷ� �Է� �޴´�)
		
		System.out.println("��� �Ͻðڽ��ϱ�?(y/n)");
		s = kb.next(); // s�� �ձ��ڰ� y�϶� �ݺ�.
		System.out.println("");
		}
	}
}

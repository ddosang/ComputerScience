import java.util.Scanner;
class MenuOrder{
	private int cokePrice, lemonadePrice, coffeePrice, inputMoney; //인스턴스 변수 선언
	private String drinkSelected; //인스턴스 변수 string 선언
	
	public void setPrice(String drinkSelected, int price){
		if(drinkSelected =="1")
			cokePrice = price;
		else if(drinkSelected =="2")
			lemonadePrice = price;
		else if(drinkSelected =="3")	
			coffeePrice = price;
	} // drinkSelected 의 값에 따라 어떤 제품 가격에 넣을지 결정.
	
	public void showMenu(){
		System.out.println("1. Coke: " + cokePrice);
		System.out.println("2. Lemonade: " + lemonadePrice);
		System.out.println("3. Coffee: " + coffeePrice);
	}//메뉴를 보여줌
	
	public void money(int money) {
		inputMoney = money;
	}//money를 inputMoney에 대입.
	
	public void showResult(int input){
		
		if(input == 1){
			System.out.println("Coke를 선택하셨습니다.");
			if(inputMoney-cokePrice>0)
				System.out.println("잔돈은 "+(inputMoney-cokePrice)+"원입니다.");
			else if(inputMoney-cokePrice==0)
				System.out.println("잔돈은 없습니다.");
			else
				System.out.println((cokePrice-inputMoney)+"원 더 넣어주세요.");
		}//1번이면 coke 가격에 맞추어 결과를 출력한다.
		else if(input == 2){
			System.out.println("Lemonade를 선택하셨습니다.");
			if(inputMoney-lemonadePrice>0)
				System.out.println("잔돈은"+(inputMoney-lemonadePrice)+"입니다.");
			else if(inputMoney-lemonadePrice==0)
				System.out.println("잔돈은 없습니다.");
			else
				System.out.println((lemonadePrice-inputMoney)+"원 더 넣어주세요.");
		}//2번이면 coke 가격에 맞추어 결과를 출력한다.
		else if(input == 3){
			System.out.println("Coffee를 선택하셨습니다.");
			if((inputMoney-coffeePrice)>0)
				System.out.println("잔돈은"+(inputMoney-coffeePrice)+"입니다.");
			else if(inputMoney-coffeePrice==0)
				System.out.println("잔돈은 없습니다.");
			else
				System.out.println((coffeePrice-inputMoney)+"원 더 넣어주세요.");
			
		}//3번이면 coke 가격에 맞추어 결과를 출력한다.
		else{
			System.out.println("없는 메뉴를 선택하셨습니다.");
		}//1 2 3 번이 아니면 없는 메뉴를 선택했다고 알려준다.
	}
}
public class Week4_1 {
	public static void main(String[] args){
		
		Scanner kb = new Scanner(System.in);
		
		MenuOrder mo = new MenuOrder(); //메뉴오더 오브젝트 mo 생성.
		
		String s = "y";
		
		System.out.println("--- 음료가격 설정 ---");
		System.out.printf("Coke가격:");
		mo.setPrice("1", kb.nextInt()); 
		System.out.printf("Lemonade가격:");
		mo.setPrice("2", kb.nextInt());
		System.out.printf("Coffee가격:");
		mo.setPrice("3", kb.nextInt());
		System.out.println("");
		//문제의 결과 화면을 봤을 때, string은 입력받을 필요가 없으므로 순서대로 대입해주고,
		//가격인 정수를 입력받는다.
		
		
		
		while(s.equalsIgnoreCase("y")||s.equalsIgnoreCase("Y")){
		System.out.println("--- 돈을 넣으세요 ---");
		mo.money(kb.nextInt());
		//넣는 돈을 입력받아 인스턴스 변수에 넣는다.
		
		System.out.println("--- 음료를 선택하세요 ---");
		mo.showMenu(); //메뉴를 보여준다.
		
		mo.showResult(kb.nextInt()); //메뉴를 고른다 (숫자로 입력 받는다)
		
		System.out.println("계속 하시겠습니까?(y/n)");
		s = kb.next(); // s의 앞글자가 y일때 반복.
		System.out.println("");
		}
	}
}

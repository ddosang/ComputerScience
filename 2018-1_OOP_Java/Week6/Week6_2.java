package fallinlovewithyou;

import java.util.Scanner;
class Pet{ //Pet class
	private String name;
	private int age;
	private double weight;
	
	public void writeOutput(){
		System.out.println("Name: "+name);
		System.out.println("Age: "+age);
		System.out.println("Weight: "+weight);
	} //name, age, weight 출력
	public void setPet(String name, int age, double weight){
		this.name = name;
		this.age = age;
		this.weight = weight;
	}
	public void setName(String name){
		this.name = name;
	}
	public void setAge(int age){
		this.age = age;
	}
	public void setWeight(double weight){
		this.weight = weight;
	}//setter
	public String getName(){
		return name;
	}
	public int getAge(){
		return age;
	}
	public double getWeight(){
		return weight;
	}//getter
	public void move(){
		System.out.println(name+" moves");
	}//정해진 문구를 출력하는 move method
}

class Dog extends Pet{ //Pet class를 상속받은  Dog class
	private boolean boosterShot;
	
	public void writeOutput(){
		char boosterShot1 = 'O';
		if(boosterShot == true) boosterShot1 = 'O';
		else  boosterShot1 = 'X';
		
		System.out.println("Name: " + super.getName());
		System.out.println("Age: "+ super.getAge());
		System.out.println("Weight: " + super.getWeight());
		System.out.println("BoosterShot(y/n): " + boosterShot1);
	}// writeOutput method overriding
	public void setBoosterShot(boolean boosterShot){
		this.boosterShot = boosterShot;
	}//setter
	public boolean getBoosterShot(){
		return boosterShot;
	}//getter
	public void move(){
		System.out.println(super.getName()+" walks and runs.");
	}//move method overriding
}

class Cat extends Pet{ //Pet class를 상속받은  Cat class
	private String color;
	
	public void writeOutput(){
		System.out.println("Name: " + super.getName());
		System.out.println("Age: "+ super.getAge());
		System.out.println("Weight: " + super.getWeight());
		System.out.println("Color: "+color);
	}// writeOutput method overriding
	public void setColor(String color){
		this.color = color;
	}//setter
	public String getColor(){
		return color;
	}//getter
	public void move(){
		System.out.println(super.getName()+" creeps and jumps.");
	}//move method overriding
}

public class Week6_2 {
	public static void main(String[] args){
		
		Scanner kb = new Scanner(System.in);
		boolean boosterShot;
		char boosterShot1 = 'y';
		//논리형 변수 boolean 선언, 문자형 변수 boosterShot1 선언과 초기화

		Dog[] d = new Dog[3];
		Cat[] c = new Cat[3];
		//Dog, Cat 배열에 각각 3개의 element
		
		for(int i = 0; i < 3; i++){
			System.out.println("<<Dog "+(i+1)+">>");
			d[i] = new Dog();
			System.out.print("Name :");
			d[i].setName(kb.nextLine());
			System.out.print("Age :");
			d[i].setAge(kb.nextInt());
			kb.nextLine();
			System.out.print("Weight :");
			d[i].setWeight(kb.nextDouble());
			kb.nextLine();
			System.out.print("BoosterShot(y/n) :");
			boosterShot1 = kb.nextLine().charAt(0);
			if(boosterShot1 == 'y') boosterShot = true;
			else  boosterShot = false; //입력받은 문자가 y/n일때 각각  true false 로
			d[i].setBoosterShot(boosterShot);
			System.out.println("");
		}//Dog 인스턴스의 정보를 반복문을 이용하여 3개 입력
		
		for(int i = 0; i < 3; i++){
			System.out.println("<<Cat "+(i+1)+">>");
			c[i] = new Cat();
			System.out.print("Name :");
			c[i].setName(kb.nextLine());
			System.out.print("Age :");
			c[i].setAge(kb.nextInt());
			kb.nextLine();
			System.out.print("Weight :");
			c[i].setWeight(kb.nextDouble());
			kb.nextLine();
			System.out.print("Color :");
			c[i].setColor(kb.nextLine());
			System.out.println("");
		}//Cat 인스턴스의 정보를 반복문을 이용하여 3개 입력
		
		System.out.println("<<Dog List>>");
		for(int i = 0; i < 3; i++){
			d[i].writeOutput();
			d[i].move();
			System.out.println("");
		}// Dog 인스턴스의 정보 출력
		
		System.out.println("<<Cat List>>");
		for(int i = 0; i < 3; i++){
			c[i].writeOutput();
			c[i].move();
			System.out.println("");
		}// Cat 인스턴스의 정보 출력
		
		System.out.println("* Dogs older than 2 years and no boostershot are...");
		for(int i = 0; i < 3; i++){
			if((d[i].getAge() >= 2) && d[i].getBoosterShot() == false){
				System.out.printf("%s\t", d[i].getName());
			}//두살 '이상'이고 예방접종하지 않은  dog 이름 출력
			//문제에서 주어진 예시는  more than 이라 초과로 해석한것 같음.
			//그래서 결과가 주어진 것은 A만 나오지만 두살 이상이라고 했으므로 A,B 모두 출력
		}
		System.out.println("");
		
		System.out.println("* Black cats weighs more than 3Kg are...");
		for(int i = 0; i < 3; i++){
			if(c[i].getColor().equalsIgnoreCase("black") && (c[i].getWeight() >= 3)){
				System.out.printf("%s\t", c[i].getName());
			}//black이고 3kg '이상'인  cat이름 출력
			//문제에서 주어진 예시는  more than 이라 초과로 해석한것 같음.
		}
	}
}
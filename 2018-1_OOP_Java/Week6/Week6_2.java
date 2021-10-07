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
	} //name, age, weight ���
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
	}//������ ������ ����ϴ� move method
}

class Dog extends Pet{ //Pet class�� ��ӹ���  Dog class
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

class Cat extends Pet{ //Pet class�� ��ӹ���  Cat class
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
		//���� ���� boolean ����, ������ ���� boosterShot1 ����� �ʱ�ȭ

		Dog[] d = new Dog[3];
		Cat[] c = new Cat[3];
		//Dog, Cat �迭�� ���� 3���� element
		
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
			else  boosterShot = false; //�Է¹��� ���ڰ� y/n�϶� ����  true false ��
			d[i].setBoosterShot(boosterShot);
			System.out.println("");
		}//Dog �ν��Ͻ��� ������ �ݺ����� �̿��Ͽ� 3�� �Է�
		
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
		}//Cat �ν��Ͻ��� ������ �ݺ����� �̿��Ͽ� 3�� �Է�
		
		System.out.println("<<Dog List>>");
		for(int i = 0; i < 3; i++){
			d[i].writeOutput();
			d[i].move();
			System.out.println("");
		}// Dog �ν��Ͻ��� ���� ���
		
		System.out.println("<<Cat List>>");
		for(int i = 0; i < 3; i++){
			c[i].writeOutput();
			c[i].move();
			System.out.println("");
		}// Cat �ν��Ͻ��� ���� ���
		
		System.out.println("* Dogs older than 2 years and no boostershot are...");
		for(int i = 0; i < 3; i++){
			if((d[i].getAge() >= 2) && d[i].getBoosterShot() == false){
				System.out.printf("%s\t", d[i].getName());
			}//�λ� '�̻�'�̰� ������������ ����  dog �̸� ���
			//�������� �־��� ���ô�  more than �̶� �ʰ��� �ؼ��Ѱ� ����.
			//�׷��� ����� �־��� ���� A�� �������� �λ� �̻��̶�� �����Ƿ� A,B ��� ���
		}
		System.out.println("");
		
		System.out.println("* Black cats weighs more than 3Kg are...");
		for(int i = 0; i < 3; i++){
			if(c[i].getColor().equalsIgnoreCase("black") && (c[i].getWeight() >= 3)){
				System.out.printf("%s\t", c[i].getName());
			}//black�̰� 3kg '�̻�'��  cat�̸� ���
			//�������� �־��� ���ô�  more than �̶� �ʰ��� �ؼ��Ѱ� ����.
		}
	}
}
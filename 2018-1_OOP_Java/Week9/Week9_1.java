import java.util.Scanner;

abstract class Pet{
	String species;
	String name;
	int age;
	
	public abstract void move(); //�߻� �޼��� move
}//�߻� Ŭ���� Pet

class Bird extends Pet{
	Bird(String name, int age){
		this.species = "Bird";
		this.name = name;
		this.age = age;
	}//������ ������ ����
	public void move() {
		System.out.println("fly");
	}//move class overriding
}//Pet�� �����ϴ� Bird class
class Dog extends Pet{
	Dog(String name, int age){
		this.species = "Dog";
		this.name = name;
		this.age = age;
	}
	public void move() {
		System.out.println("run");
	}//move class overriding
}//Pet�� �����ϴ� Dog class
class Cat extends Pet{
	Cat(String name, int age){
		this.species = "Cat";
		this.name = name;
		this.age = age;
	}
	public void move() {
		System.out.println("jump");
	}//move class overriding
}//Pet�� �����ϴ� Cat class

public class Week9_1 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		int input1 = 1, input2, age, i=0;
		String name;
		Pet[] p = new Pet[10]; //Pet class �迭 ������ ���̷�
		
		while(input1 >= 0) {
			System.out.println("���ϴ� �۾��� �����Դϱ�?");
			System.out.println("1. New input  2. Output  3. Exit");
			input1 = kb.nextInt();
			
			if(input1 == 1) {
				System.out.println("���� �����Դϱ�?");
				System.out.println("1. Dog  2. Cat  3. Bird");
				input2 = kb.nextInt();
				System.out.printf("Name:");
				name = kb.next();
				System.out.printf("Age:");
				age = kb.nextInt();
				System.out.println("");
				
				switch(input2) {
				case 1 : p[i++] = new Dog(name, age); break;
				case 2 : p[i++] = new Cat(name, age); break;
				case 3 : p[i++] = new Bird(name, age); break;
				default : break;
				}
			}//input1�� 1 �϶� input2�� ���� �ν��Ͻ� �����Ͽ� �迭�� �����Ѵ�
			else if(input1 == 2) {
				System.out.printf("\nSpecies\tName\tAge\tMovement\n");
				for(int j = 0; j < i; j++) {
					System.out.printf("%s\t%s\t%d\t", p[j].species, p[j].name, p[j].age);
					p[j].move();
				}
				System.out.println("");
			}//input1�� 2�϶� ���ݱ��� ������ ����� ���.
			else if (input1 == 3) {
				System.out.println("����");
				break;
			}//input1�� 3�� �� �ݺ����� �������� ������.
		}	
	}
}

import java.util.Scanner;

abstract class Pet{
	String species;
	String name;
	int age;
	
	public abstract void move(); //추상 메서드 move
}//추상 클래스 Pet

class Bird extends Pet{
	Bird(String name, int age){
		this.species = "Bird";
		this.name = name;
		this.age = age;
	}//생성자 적절히 정의
	public void move() {
		System.out.println("fly");
	}//move class overriding
}//Pet을 구현하는 Bird class
class Dog extends Pet{
	Dog(String name, int age){
		this.species = "Dog";
		this.name = name;
		this.age = age;
	}
	public void move() {
		System.out.println("run");
	}//move class overriding
}//Pet을 구현하는 Dog class
class Cat extends Pet{
	Cat(String name, int age){
		this.species = "Cat";
		this.name = name;
		this.age = age;
	}
	public void move() {
		System.out.println("jump");
	}//move class overriding
}//Pet을 구현하는 Cat class

public class Week9_1 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		int input1 = 1, input2, age, i=0;
		String name;
		Pet[] p = new Pet[10]; //Pet class 배열 적당한 길이로
		
		while(input1 >= 0) {
			System.out.println("원하는 작업은 무엇입니까?");
			System.out.println("1. New input  2. Output  3. Exit");
			input1 = kb.nextInt();
			
			if(input1 == 1) {
				System.out.println("종은 무엇입니까?");
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
			}//input1이 1 일땐 input2에 따라 인스턴스 생성하여 배열에 저장한다
			else if(input1 == 2) {
				System.out.printf("\nSpecies\tName\tAge\tMovement\n");
				for(int j = 0; j < i; j++) {
					System.out.printf("%s\t%s\t%d\t", p[j].species, p[j].name, p[j].age);
					p[j].move();
				}
				System.out.println("");
			}//input1이 2일땐 지금까지 저장한 결과를 출력.
			else if (input1 == 3) {
				System.out.println("종료");
				break;
			}//input1이 3일 땐 반복문을 빠져나와 끝낸다.
		}	
	}
}

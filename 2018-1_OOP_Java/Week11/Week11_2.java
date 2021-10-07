import java.io.Serializable;
import java.util.Scanner;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

class Pet implements Serializable{
	String name;
	int age;
	double weight;
	
	public void setPet(String newName, int newAge, double newWeight) {
		name = newName;
		age = newAge;
		weight = newWeight;
	}
	public void setName(String newName){
		name = newName;
	}
	public void setAge(int newAge) {
		age = newAge;
	}
	public void setWeight(double newWeight) {
		weight = newWeight;
	}// set method
	public String getName() {
		return name;
	}
	public int getAge() {
		return age;
	}
	public double getWeight() {
		return weight;
	}// get method
}//Pet class

class Dog extends Pet implements Serializable{
	String breed;
	boolean boosterShot;
	
	Dog(String name, int age, double weight, String breed, boolean boosterShot){
		this.name = name;
		this.age = age;
		this.weight = weight;
		this.breed = breed;
		this.boosterShot = boosterShot;
	}//Dog ������
	
	public void setBreed(String breed) {
		this.breed = breed;
	}
	public void setBoosterShot(boolean boosterShot) {
		this.boosterShot = boosterShot;
	}//set method
	public String getBreed() {
		return breed;
	}
	public boolean getBoosterShot() {
		return boosterShot;
	}// get method
	public String toString() {
		String boosterShot2;
		if(boosterShot == true)  boosterShot2 = "O";
		else  boosterShot2 ="X";
		return (name + "\t" + age + "\t" + weight + "\t" + breed + "\t\t" + boosterShot2);
	}// toString method overriding
}//Dog class
public class Week11_2 {
	public static void main(String args[]) {

		Scanner kb = new Scanner(System.in);
		Dog[] myDog = new Dog[10];	
		myDog[0] = new Dog("Merry", 3, 2.5, "Bulldog", false);
		myDog[1] = new Dog("JJong", 5, 5.5, "Mix", false);
		myDog[2] = new Dog("Kong", 4, 3, "Poodle", true);
		myDog[3] = new Dog("Apple", 2, 2.5, "Collie", true);
		myDog[4] = new Dog("Candy", 5, 5.5, "Coca", false);
		myDog[5] = new Dog("Cutie", 7, 2.5, "Chiwawa", true);
		myDog[6] = new Dog("Peace", 3, 2.5, "Huskey", false);
		myDog[7] = new Dog("Lion", 9, 1.5, "Shepard", true);
		myDog[8] = new Dog("Windy", 2, 9, "Jindo", true);
		myDog[9] = new Dog("Sweetie", 1, 2.5, "Maltiz", false);
		//myDog �迭�� ���� �Է�
		
		System.out.println("Input File name to write Dog data");
		String fileName = kb.next();
		//���� �̸� �Է� ����
		try {
			ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(fileName));
			outputStream.writeObject(myDog);
			outputStream.close();
		}
		catch(IOException e) {
			System.out.println("ERROR writing to file "+fileName+".");
			System.exit(0);
		}//ù��° try block : ���� �̸��� �Է¹޾� �� ���Ͽ� myDog �迭 �ν��Ͻ��� �Է��Ѵ�.
		
		Dog[] anotherDog = null; //���ο� Dog �迭 ����
		try {
			ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(fileName));
			anotherDog = (Dog[])inputStream.readObject(); //����ȯ
			System.out.printf("Name\tAge\tWeight\tBreed\t\tBoosterShot\t\n");
			for(int i = 0; i<10 ;i++)
				System.out.println(anotherDog[i].toString()); //�迭 �ν��Ͻ� ��� ���
			System.out.println("");
			
			System.out.println("Dogs older that 2 years and did no get the boosterShot.");
			for(int i = 0; i<10 ;i++) {
				if(anotherDog[i].getAge()>=2 && anotherDog[i].getBoosterShot() == false)
					System.out.println(anotherDog[i].getName()+"\t\t"+anotherDog[i].getBreed());
			}//���ǿ� �´� �ν��Ͻ��� ���
			System.out.println("");
			
			inputStream.close();
		}
		catch(EOFException e) {
			System.out.println("End of File Exception.");
		}
		catch(FileNotFoundException e) {
			System.out.println("File not found Exciption.");
		}
		catch(IOException e) {
			System.out.println("IO Exception.");
		}
		catch(Exception e) {
			System.out.println("Exception.");
		}//�ι�° try block
		
		System.out.println("Program finished");
	}
}

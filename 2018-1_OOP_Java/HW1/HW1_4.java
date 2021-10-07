import java.util.Scanner;

class StudentInformation{
	private String name, id;
	Scanner kb = new Scanner(System.in);
	
	public void display(){
		System.out.printf("ID: %s",id);
		System.out.printf("Name: %s",name);
	}//id�� name�� ����ϴ� �޼��� display
	
	public void setId(String id){
		this.id = id;
	}
	public void setName(String name){
		this.name = name;
	}
	//input ������ id�� name�� �����ϴ� setter�޼���
	public String getId(){
		return id;
	}
	public String getName(){
		return name;
	}
	//id�� name ���� ��ȯ�ϴ� getter �޼���
	
}//private String�� ���� id�� name�� ���� StudentInformation class ����

class StudentScore extends StudentInformation{
	private int korean, math, english;
	
	public void display(){
		System.out.printf("ID: %s\n",getId());
		System.out.printf("Name: %s\n", getName());
		System.out.printf("Korean: %d\n", korean);
		System.out.printf("Math: %d\n", math);
		System.out.printf("English: %d\n", english);
	}//display method overriding
	public void setKorean(int korean){
		this.korean = korean;
	}
	public void setMath(int math){
		this.math = math;
	}
	public void setEnglish(int english){
		this.english = english;
	}
	//input ������ korean, math, english�� �����ϴ� setter�޼���
	public int getKorean(){
		return korean;
	}
	public int getMath(){
		return math;
	}
	public int getEnglish(){
		return english;
	}
	//korean, math, english�� ��ȯ�ϴ� getter�޼���
}//StudentInformation�� ��ӹ��� StudentScore class ����.

public class HW1_4 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		
		int numberOfStudents, sum = 0, ksum = 0, msum = 0, esum = 0;
		double avg = 0, kavg=0, mavg=0, eavg=0;
		System.out.println("How many students are there?");
		numberOfStudents = kb.nextInt();
		kb.nextLine(); //�л� ���� �Է¹ް� ���͸� �����ش�.
		
		StudentScore[] sc = new StudentScore[numberOfStudents];//StudentScore ��ü�迭 ����
		
		System.out.println("Input the information.");
		for(int i = 0; i < numberOfStudents; i++){
			kb.nextLine();
			sc[i] = new StudentScore();
			System.out.printf("ID:");
			sc[i].setId(kb.nextLine());
			System.out.printf("Name:");
			sc[i].setName(kb.nextLine());
			System.out.printf("Korean:");
			sc[i].setKorean(kb.nextInt());
			System.out.printf("Math:");
			sc[i].setMath(kb.nextInt());
			System.out.printf("English:");
			sc[i].setEnglish(kb.nextInt());
			System.out.println("");
		}//student ���� setter �޼��带 �̿��� �ݺ������� �Է¹���
		
		System.out.printf("NAME\t\tID\tKOREAN\tMATH\tENGLISH\tSUM\tAVG\n");
		for(int i = 0; i < numberOfStudents; i++){
			sum = sc[i].getKorean() + sc[i].getMath() + sc[i].getEnglish();
			avg = (double)sum / 3;
			ksum += sc[i].getKorean();
			msum += sc[i].getMath();
			esum += sc[i].getEnglish();
			System.out.printf("%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n",sc[i].getName(),sc[i].getId(),sc[i].getKorean(),sc[i].getMath(),sc[i].getEnglish(),sum,avg);
		}//��հ� ����ϰ�, student ������ ��հ����� �迭 ���·� ���
		
		kavg = (double)ksum / numberOfStudents;
		mavg = (double)msum / numberOfStudents;
		eavg = (double)esum / numberOfStudents;
		System.out.printf("Subject Avg\t\t%.2f\t%.2f\t%.2f\n",kavg,mavg,eavg);
		//�� ������ ��հ� ���
		
		//��� ������ ���� �л� �̸� ���
		System.out.println("\n<Students over the avg>\n");
		System.out.println("Korean:");
		for(int i = 0; i < numberOfStudents; i++){
			if(sc[i].getKorean() >= kavg){
				System.out.printf("%s\t",sc[i].getName());}
		}
		System.out.println("\nMath:");
		for(int i = 0; i < numberOfStudents; i++){
			if(sc[i].getMath() >= mavg){
				System.out.printf("%s\t",sc[i].getName());}
		}
		System.out.println("\nEnglish:");
		for(int i = 0; i < numberOfStudents; i++){
			if(sc[i].getEnglish() >= eavg){
				System.out.printf("%s\t",sc[i].getName());}
		}
	}
}

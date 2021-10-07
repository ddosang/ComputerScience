import java.util.Scanner;

class StudentInformation{
	private String name, id;
	Scanner kb = new Scanner(System.in);
	
	public void display(){
		System.out.printf("ID: %s",id);
		System.out.printf("Name: %s",name);
	}//id와 name을 출력하는 메서드 display
	
	public void setId(String id){
		this.id = id;
	}
	public void setName(String name){
		this.name = name;
	}
	//input 값으로 id와 name을 설정하는 setter메서드
	public String getId(){
		return id;
	}
	public String getName(){
		return name;
	}
	//id와 name 값을 반환하는 getter 메서드
	
}//private String형 변수 id와 name을 갖는 StudentInformation class 생성

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
	//input 값으로 korean, math, english를 설정하는 setter메서드
	public int getKorean(){
		return korean;
	}
	public int getMath(){
		return math;
	}
	public int getEnglish(){
		return english;
	}
	//korean, math, english를 반환하는 getter메서드
}//StudentInformation을 상속받은 StudentScore class 생성.

public class HW1_4 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		
		int numberOfStudents, sum = 0, ksum = 0, msum = 0, esum = 0;
		double avg = 0, kavg=0, mavg=0, eavg=0;
		System.out.println("How many students are there?");
		numberOfStudents = kb.nextInt();
		kb.nextLine(); //학생 수를 입력받고 엔터를 삼켜준다.
		
		StudentScore[] sc = new StudentScore[numberOfStudents];//StudentScore 객체배열 생성
		
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
		}//student 정보 setter 메서드를 이용해 반복적으로 입력받음
		
		System.out.printf("NAME\t\tID\tKOREAN\tMATH\tENGLISH\tSUM\tAVG\n");
		for(int i = 0; i < numberOfStudents; i++){
			sum = sc[i].getKorean() + sc[i].getMath() + sc[i].getEnglish();
			avg = (double)sum / 3;
			ksum += sc[i].getKorean();
			msum += sc[i].getMath();
			esum += sc[i].getEnglish();
			System.out.printf("%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n",sc[i].getName(),sc[i].getId(),sc[i].getKorean(),sc[i].getMath(),sc[i].getEnglish(),sum,avg);
		}//평균값 계산하고, student 정보와 평균값들을 배열 형태로 출력
		
		kavg = (double)ksum / numberOfStudents;
		mavg = (double)msum / numberOfStudents;
		eavg = (double)esum / numberOfStudents;
		System.out.printf("Subject Avg\t\t%.2f\t%.2f\t%.2f\n",kavg,mavg,eavg);
		//각 과목의 평균값 출력
		
		//평균 점수를 넘은 학생 이름 출력
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

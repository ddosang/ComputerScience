import java.util.*;

class Student{
	String name, ID;
	int age; //���������
	Student(String name,String ID, int age){
		this.name = name;
		this.ID = ID;
		this.age = age;
	} //�����ڸ� ���� �ʱ�ȭ
	public String toString() {
		return name+"\t"+ID+"\t"+age;
	}//object class�� method �������̵�
}//�л� Ŭ����
public class Week12_1 {	
	public static void main(String[] args) {
		
		ArrayList <Student> s = new ArrayList <Student>(); //ArrayList
		String name, ID;
		int age;
		Scanner kb = new Scanner(System.in);
		
		System.out.println("Input Student Name, ID, and age. 0 for name to quit.");
		while(true) {
			name = kb.next();
			if(name.equals("0")) {
				System.out.println("NUMBER\tNAME\tID\tAGE");
				PrintResult(s); //0 �Է��ϸ� ��� �����ش�
				break;
			}
			ID = kb.next();
			age= kb.nextInt();
			s.add(new Student(name, ID, age));
		}//0�� �Է��ϸ� �׸� �Է¹޵��� ����.
		
		for(int i = 1;;i++) { //�ʱⰪ�� ������ ���ѷ���
			System.out.println("Choose the opreation you want.");
			System.out.println("1.add information 2.delete information 3.show list 4.Finish program");
			int n = kb.nextInt();
			if(n==1) {
				addStudent(s);
				PrintResult(s);
			}
			else if(n==2) {
				deleteStudent(s);
				PrintResult(s);
			}
			else if(n==3) {
				PrintResult(s);
			}
			else if(n==4) {
				break;
			} //4�� ������ ���ѷ��� ��������
			else {
				System.out.println("Wrong input.");
				System.out.println();
			}// ���ڿ� ���� ��� ����
		}

	}
	public static void PrintResult(List<Student> student) {
		for(int i = 1; i<=student.size(); i++) {
			System.out.printf("%d\t",i);
			System.out.println(student.get(i-1));
		}
		System.out.println();
	} // list�� �Է¹޴� �޼��� PrintResult
	public static void deleteStudent(List<Student> Stu) {
		Scanner kb = new Scanner(System.in);
		System.out.println("Input Student Number to delete.");
		int n = kb.nextInt();
		Stu.remove(n-1);
	}// list�� �Է¹޴� �޼��� deleteResult
	public static void addStudent(List<Student> Stu) {
		System.out.println("Input new Student Name, ID, and age, and the location");
		Scanner kb = new Scanner(System.in);
		String name = kb.next();
		String ID = kb.next();
		int age= kb.nextInt();
		int loca = kb.nextInt();
		Stu.add(loca-1 , new Student(name, ID, age));
	}// list�� �Է¹޴� �޼��� addStudent
}

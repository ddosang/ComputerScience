
import java.util.Scanner;

class Phone {//phone class ����
	
	private String maker, color; //private���� maker, color string ����
	void setMaker(String mkr){
		maker = mkr;
	}; //setMaker.  ������ ������ (mkr �κп�)�Է¹޾Ƽ� maker�� �ִ´�.
	void setColor(String clr){
		color = clr;
	};//���� ������ clr�� �Է¹޾Ƽ� color�� �����Ѵ�.
	void phoneCopy(Phone p){
		p.maker = this.maker;
		p.color = this.color;
		}// a.phoneCopy(b)�϶� b�� maker, color�� a�� maker, color ������ �ִ´�.
	
	
	void phoneInfo(){
		System.out.println("��Ż�:" + maker);
		System.out.println("����:" + color);
	};//�ڵ����� ��Ż�� ������ ����Ѵ�.
}


//������ �־��� ���� ����.
//public class Week4_1 {
//	public static void main(String[] main){
//		Scanner kbd = new Scanner(System.in);
//		
//		String maker, color;
//		
//		Phone pOld = new Phone();
//		Phone pNew = new Phone();
//		
//		System.out.println("--��ȭ�����Է�(��Ż�,����)--");
//		pOld.setMaker(kbd.nextLine());
//		pOld.setColor(kbd.nextLine());
//		pOld.phoneCopy(pNew);
//		
//		System.out.println("<���� ��ȭ��>");
//		pOld.phoneInfo();
//		System.out.println("<���ο� ��ȭ��>");
//		pNew.phoneInfo();
//	}
//	
//}

import java.util.Scanner;

class Circle{//circle class ����
	final double PI = 3.14159; // ���  PI
	private double radius;// private �Ǽ��� ����   radius ����

	public void setRadius(double input){
		radius = input;
	}//�Է¹��� ���� radius�� �����ϴ� �޼���
	
	public double getRadius(){
		return radius;
	} //radius����  return�ϴ� �޼���
	
	public double area(double radius){
		return PI*radius*radius;
	}//radius���� ������ area���� return�ϴ� �޼���
	public void showCircle(){
		System.out.println("������: "+radius);
		System.out.println("���� ����: "+area(radius));
	}//�������� ���� ���̸� ���
}

public class Week4_2 {
	public static void main(String[] args){	
	
	double input;
	
	Circle c1 = new Circle();//circle ������Ʈ ����
	
	Scanner kb = new Scanner(System.in);
	System.out.printf("������ �Է�:");
	input = kb.nextInt();//�������� �Է¹޾� input�� ����.
	
	c1.setRadius(input);//input���� �ν��Ͻ� ���� radius�� �ִ´�.
	c1.area(input);
	c1.showCircle();
	}
}

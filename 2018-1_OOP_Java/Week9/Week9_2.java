import java.util.Scanner;

interface Geometry{
	final double PI = 3.14159;
	public double area();
	public double perimeter();
}//Geometry Interface

class Circle implements Geometry{
	double radius;
	
	Circle(){
		this(0);
	}//������
	Circle(double radius){
		this.radius = radius;
	}//���ڰ� double 1���� ������
	
	public double area() {
		return PI*radius*radius;
	}//area method ������ �°� ����
	public double perimeter() {
		return 2*PI*radius;
	}//perimeter method ������ �°� ����
}//Geometry interface�� �����ϴ� Circle class

class Square implements Geometry{
	double side;
	
	Square(){
		this(0);
	}//������
	Square(double side){
		this.side = side;
	}//���ڰ� double 1���� ������
	
	public double area() {
		return side*side;
	}//area method ������ �°� ����
	public double perimeter() {
		return 4*side;
	}//perimeter method ������ �°� ����
}//Geometry interface�� �����ϴ� Square class

class Triangle implements Geometry{
	double a, b, c;
	
	Triangle(){
		this(0,0,0);
	}//������
	Triangle(double a, double b, double c){
		this.a = a;
		this.b = b;
		this.c = c;
	}//���ڰ� double 3���� ������
	
	public double area() {
		double s = (a+b+c)/2; 
		return Math.sqrt(s*(s-a)*(s-b)*(s-c));
	}//area method ������ �°� ����
	public double perimeter() {
		return a+b+c;
	}//perimeter method ������ �°� ����
}//Geometry interface�� �����ϴ� Triangle class

public class Week9_2 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		int radius, length, a, b, c;
		
		System.out.println("Input radius for a circle");
		radius = kb.nextInt();
		Circle cc = new Circle(radius);
		//�������� �Է¹޾� �� ���� ���ڷ� �ϴ� circle �ν��Ͻ� ����
		
		System.out.println("Input length for a square");
		length = kb.nextInt();
		Square s = new Square(length);
		//�� ���� ���̸� �Է¹޾� �� ���� ���ڷ� �ϴ� square �ν��Ͻ� ����
		
		System.out.println("Input a for a triangle");
		a = kb.nextInt();
		System.out.println("Input a for b triangle");
		b = kb.nextInt();
		System.out.println("Input a for c triangle");
		c = kb.nextInt();
		Triangle t = new Triangle(a,b,c);
		//�ﰢ���� �� ���� ���̸� �Է¹޾� �� ���� ���ڷ� �ϴ� triangle �ν��Ͻ� ����
		
		System.out.println("<Circle>");
		System.out.println("Area: "+ cc.area());
		System.out.println("Circumference: "+cc.perimeter());
		System.out.println("<Square>");
		System.out.println("Area: "+ s.area());
		System.out.println("Circumference: "+s.perimeter());
		System.out.println("<Triangle>");
		System.out.println("Area: "+ t.area());
		System.out.println("Circumference: "+t.perimeter());
		//���� �ν��Ͻ��� area, perimeter �޼��� �����Ͽ� ���
		
	}
}

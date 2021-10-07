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
	}//생성자
	Circle(double radius){
		this.radius = radius;
	}//인자가 double 1개인 생성자
	
	public double area() {
		return PI*radius*radius;
	}//area method 도형에 맞게 변경
	public double perimeter() {
		return 2*PI*radius;
	}//perimeter method 도형에 맞게 변경
}//Geometry interface를 구현하는 Circle class

class Square implements Geometry{
	double side;
	
	Square(){
		this(0);
	}//생성자
	Square(double side){
		this.side = side;
	}//인자가 double 1개인 생성자
	
	public double area() {
		return side*side;
	}//area method 도형에 맞게 변경
	public double perimeter() {
		return 4*side;
	}//perimeter method 도형에 맞게 변경
}//Geometry interface를 구현하는 Square class

class Triangle implements Geometry{
	double a, b, c;
	
	Triangle(){
		this(0,0,0);
	}//생성자
	Triangle(double a, double b, double c){
		this.a = a;
		this.b = b;
		this.c = c;
	}//인자가 double 3개인 생성자
	
	public double area() {
		double s = (a+b+c)/2; 
		return Math.sqrt(s*(s-a)*(s-b)*(s-c));
	}//area method 도형에 맞게 변경
	public double perimeter() {
		return a+b+c;
	}//perimeter method 도형에 맞게 변경
}//Geometry interface를 구현하는 Triangle class

public class Week9_2 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		int radius, length, a, b, c;
		
		System.out.println("Input radius for a circle");
		radius = kb.nextInt();
		Circle cc = new Circle(radius);
		//반지름을 입력받아 그 값을 인자로 하는 circle 인스턴스 생성
		
		System.out.println("Input length for a square");
		length = kb.nextInt();
		Square s = new Square(length);
		//힌 변의 길이를 입력받아 그 값을 인자로 하는 square 인스턴스 생성
		
		System.out.println("Input a for a triangle");
		a = kb.nextInt();
		System.out.println("Input a for b triangle");
		b = kb.nextInt();
		System.out.println("Input a for c triangle");
		c = kb.nextInt();
		Triangle t = new Triangle(a,b,c);
		//삼각형의 세 변의 길이를 입력받아 그 값을 인자로 하는 triangle 인스턴스 생성
		
		System.out.println("<Circle>");
		System.out.println("Area: "+ cc.area());
		System.out.println("Circumference: "+cc.perimeter());
		System.out.println("<Square>");
		System.out.println("Area: "+ s.area());
		System.out.println("Circumference: "+s.perimeter());
		System.out.println("<Triangle>");
		System.out.println("Area: "+ t.area());
		System.out.println("Circumference: "+t.perimeter());
		//각각 인스턴스에 area, perimeter 메서드 적용하여 출력
		
	}
}

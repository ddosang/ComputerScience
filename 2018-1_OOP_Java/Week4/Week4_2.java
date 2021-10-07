import java.util.Scanner;

class Circle{//circle class 생성
	final double PI = 3.14159; // 상수  PI
	private double radius;// private 실수형 변수   radius 선언

	public void setRadius(double input){
		radius = input;
	}//입력받은 수를 radius에 대입하는 메서드
	
	public double getRadius(){
		return radius;
	} //radius값을  return하는 메서드
	
	public double area(double radius){
		return PI*radius*radius;
	}//radius값을 넣으면 area값을 return하는 메서드
	public void showCircle(){
		System.out.println("반지름: "+radius);
		System.out.println("원의 넓이: "+area(radius));
	}//반지름과 원의 넓이를 출력
}

public class Week4_2 {
	public static void main(String[] args){	
	
	double input;
	
	Circle c1 = new Circle();//circle 오브젝트 생성
	
	Scanner kb = new Scanner(System.in);
	System.out.printf("반지름 입력:");
	input = kb.nextInt();//반지름을 입력받아 input에 저장.
	
	c1.setRadius(input);//input값을 인스턴스 변수 radius에 넣는다.
	c1.area(input);
	c1.showCircle();
	}
}

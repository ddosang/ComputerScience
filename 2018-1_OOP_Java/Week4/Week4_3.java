
import java.util.Scanner;

class Phone {//phone class 생성
	
	private String maker, color; //private으로 maker, color string 선언
	void setMaker(String mkr){
		maker = mkr;
	}; //setMaker.  제조사 정보를 (mkr 부분에)입력받아서 maker에 넣는다.
	void setColor(String clr){
		color = clr;
	};//색상 정보를 clr로 입력받아서 color에 대입한다.
	void phoneCopy(Phone p){
		p.maker = this.maker;
		p.color = this.color;
		}// a.phoneCopy(b)일때 b의 maker, color에 a의 maker, color 정보를 넣는다.
	
	
	void phoneInfo(){
		System.out.println("통신사:" + maker);
		System.out.println("색상:" + color);
	};//핸드폰의 통신사와 색상을 출력한다.
}


//문제에 주어진 실행 문장.
//public class Week4_1 {
//	public static void main(String[] main){
//		Scanner kbd = new Scanner(System.in);
//		
//		String maker, color;
//		
//		Phone pOld = new Phone();
//		Phone pNew = new Phone();
//		
//		System.out.println("--전화정보입력(통신사,색상)--");
//		pOld.setMaker(kbd.nextLine());
//		pOld.setColor(kbd.nextLine());
//		pOld.phoneCopy(pNew);
//		
//		System.out.println("<원래 전화기>");
//		pOld.phoneInfo();
//		System.out.println("<새로운 전화기>");
//		pNew.phoneInfo();
//	}
//	
//}

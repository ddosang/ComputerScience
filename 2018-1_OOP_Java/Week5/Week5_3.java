
public class Week5_3{
	public static void main(String[] args){

		//->
		int a = 5, b = 10;
		double da = 3.4, db = 5.2;
		char ca = 'a', cb ='b';
		int iarr[] = {1,2,3};
		double darr[] = {1.1,2.2,3.3};
		char carr[] = {'a','p','p','l','e'};
		
		
		System.out.println("a+b="+sum(a,b));
		System.out.println("da+b="+sum(da,b));
		System.out.println("a+db="+sum(a,db));
		System.out.println("da+db="+sum(da,db));
		System.out.println("ca+cb="+sum(ca,cb));
		System.out.println("sum of Int_Arr="+sum(iarr));
		System.out.println("sum of Double_Arr="+sum(darr));
		System.out.println("sum of Char_Arr="+sum(carr));
		//<-제시된 코드
	}
	
	
	static int sum(int a, int b){
		return a+b;
	}//정수형 인자 2개, 정수형 반환값을 가지는 클래스 메서드 선언
	
	static double sum(double a, int b){
		return a+b;
	}//실수형, 정수형 인자 각각 1개, 실수형 반환값을 가지는 클래스 메서드 선언
	
	static double sum(int a, double b){
		return a+b;
	}//정수형, 실수형 인자 각각 1개, 실수형 반환값을 가지는 클래스 메서드 선언
	
	static double sum(double a, double b){
		return a+b;
	}//실수형 인자 2개, 실수형 반환값을 가지는 클래스 메서드 선언
	
	static String sum(char a, char b){
		String c1 = Character.toString(a), c2=Character.toString(b);
		return c1+c2;
	}//문자형 인자 2개를 각각 문자열로 바꾼 뒤 결합하는 클래스 메서드 선언
	
	static int sum(int[] a){
		int sum = 0;
		for(int i = 0; i < a.length ; i++){
			sum += a[i];
		}
		return sum;
	}//정수형 배열의 모든 원소를 더하는 클래스 메서드 선언
	
	static double sum(double[] a){
		double sum = 0;
		for(int i = 0; i < a.length ; i++){
			sum += a[i];
		}
		return sum;
	}//실수형 배열의 모든 원소를 더하는 클래스 메서드 선언
	
	static String sum(char[] a){
		String sum = "";
		for(int i = 0; i < a.length ; i++){
			sum += a[i];
		}//문자형 배열의 모든 원소를 붙임
		return sum;

	}//메서드 오버로딩
}

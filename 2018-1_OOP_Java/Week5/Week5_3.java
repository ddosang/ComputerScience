
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
		//<-���õ� �ڵ�
	}
	
	
	static int sum(int a, int b){
		return a+b;
	}//������ ���� 2��, ������ ��ȯ���� ������ Ŭ���� �޼��� ����
	
	static double sum(double a, int b){
		return a+b;
	}//�Ǽ���, ������ ���� ���� 1��, �Ǽ��� ��ȯ���� ������ Ŭ���� �޼��� ����
	
	static double sum(int a, double b){
		return a+b;
	}//������, �Ǽ��� ���� ���� 1��, �Ǽ��� ��ȯ���� ������ Ŭ���� �޼��� ����
	
	static double sum(double a, double b){
		return a+b;
	}//�Ǽ��� ���� 2��, �Ǽ��� ��ȯ���� ������ Ŭ���� �޼��� ����
	
	static String sum(char a, char b){
		String c1 = Character.toString(a), c2=Character.toString(b);
		return c1+c2;
	}//������ ���� 2���� ���� ���ڿ��� �ٲ� �� �����ϴ� Ŭ���� �޼��� ����
	
	static int sum(int[] a){
		int sum = 0;
		for(int i = 0; i < a.length ; i++){
			sum += a[i];
		}
		return sum;
	}//������ �迭�� ��� ���Ҹ� ���ϴ� Ŭ���� �޼��� ����
	
	static double sum(double[] a){
		double sum = 0;
		for(int i = 0; i < a.length ; i++){
			sum += a[i];
		}
		return sum;
	}//�Ǽ��� �迭�� ��� ���Ҹ� ���ϴ� Ŭ���� �޼��� ����
	
	static String sum(char[] a){
		String sum = "";
		for(int i = 0; i < a.length ; i++){
			sum += a[i];
		}//������ �迭�� ��� ���Ҹ� ����
		return sum;

	}//�޼��� �����ε�
}

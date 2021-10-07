import java.util.Scanner;
import java.io.*;

public class HW2_2 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		System.out.println("Input a filename");
		String fileName = kb.next();
		System.out.println("Input a number");
		int n = kb.nextInt();//�� ���� �̸��� ���� �Է�
		
		try {
			ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(fileName));//��Ʈ�� ����
			for(int i = 1; i<=n; i++){
				if(check(i)==true) {
					outputStream.writeInt(i);
				}
			}//�Է¹��� ���� �� �Ҽ����� ���Ͽ� �Է�
			System.out.println("Writing data into \""+fileName+"\"");
			outputStream.close();
		}catch(IOException e) {
			System.out.println("Problem with input from file "+fileName);
			System.exit(1);
		}
		
		
		
		try {
			ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(fileName));//��Ʈ�� ����
			System.out.println("Reading data from \""+fileName+"\"");
			System.out.println("\n<Prime numbers between 2 and "+n+">");
			try{
				while(true) {
				int i = inputStream.readInt();
				System.out.printf("%d ",i);
				}//���Ͽ��� �о�� ���ڸ� ���
			}catch(EOFException e) {
				System.out.println();
				System.out.println("End Of File reading");
			}
			inputStream.close();
		}catch(FileNotFoundException e){
			System.out.println("Cannot find file "+fileName);
		}catch(IOException e) {
			System.out.println("Problem with input from file "+fileName);
			System.exit(1);
		}//binary file �о����
	}
	
	static boolean check(int x) {
		boolean a = false;
		if(x==2) a = true;
		else {
		for(int i = 2; i<x ; i++) {
			if(x%i != 0) {a = true;}
			else { a = false; break;}
		}}
		return a;
	}//x�� �Ҽ����� �ƴ��� �Ǻ����ִ� �޼���
}


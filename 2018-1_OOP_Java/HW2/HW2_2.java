import java.util.Scanner;
import java.io.*;

public class HW2_2 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		System.out.println("Input a filename");
		String fileName = kb.next();
		System.out.println("Input a number");
		int n = kb.nextInt();//열 파일 이름과 숫자 입력
		
		try {
			ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(fileName));//스트림 생성
			for(int i = 1; i<=n; i++){
				if(check(i)==true) {
					outputStream.writeInt(i);
				}
			}//입력받은 숫자 중 소수만을 파일에 입력
			System.out.println("Writing data into \""+fileName+"\"");
			outputStream.close();
		}catch(IOException e) {
			System.out.println("Problem with input from file "+fileName);
			System.exit(1);
		}
		
		
		
		try {
			ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(fileName));//스트림 생성
			System.out.println("Reading data from \""+fileName+"\"");
			System.out.println("\n<Prime numbers between 2 and "+n+">");
			try{
				while(true) {
				int i = inputStream.readInt();
				System.out.printf("%d ",i);
				}//파일에서 읽어온 숫자를 출력
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
		}//binary file 읽어오기
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
	}//x가 소수인지 아닌지 판별해주는 메서드
}


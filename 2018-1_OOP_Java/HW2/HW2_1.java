
import java.util.*;
import java.io.*;

public class HW2_1 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		
		System.out.println("Input the filename to read.");
		String fileName1 = kb.next();//읽을 파일 이름 입력받음
		
		Scanner inputStream = null;
		try {
			inputStream = new Scanner(new File(fileName1));
		}catch(FileNotFoundException e) {
			System.out.println("Error opening the file "+fileName1);
			System.exit(1);
		}//파일에서 읽어오기 위해 스트림 생성
		
		System.out.println("Input the filename to write.");
		String fileName2 = kb.next();//쓸 파일 이름 입력받음
		
		PrintWriter outStream = null;
		try {
			outStream = new PrintWriter(fileName2);
		}catch(IOException e) {
			System.out.println("Exception occurs.");
			System.exit(1);
		}//파일에 쓰기 위해 스트림 생성
	
		while(inputStream.hasNextLine()) {
			String line = inputStream.nextLine();//한줄씩 읽어서
			StringTokenizer token = new StringTokenizer(line,", \n");//토큰클래스에 넣는다 분리자는, \n
			while(token.hasMoreTokens()) {
				String str = token.nextToken();//토큰 하나씩 읽어서
				if(str.length()>4)
					outStream.println(str);//길이가 4보다 큰것만 파일에 출력
			}
		}
		System.out.println(fileName2 +" is generated.");
		
		inputStream.close();
		outStream.close();
		
	}
}

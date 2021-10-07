
import java.util.*;
import java.io.*;

public class HW2_1 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		
		System.out.println("Input the filename to read.");
		String fileName1 = kb.next();//���� ���� �̸� �Է¹���
		
		Scanner inputStream = null;
		try {
			inputStream = new Scanner(new File(fileName1));
		}catch(FileNotFoundException e) {
			System.out.println("Error opening the file "+fileName1);
			System.exit(1);
		}//���Ͽ��� �о���� ���� ��Ʈ�� ����
		
		System.out.println("Input the filename to write.");
		String fileName2 = kb.next();//�� ���� �̸� �Է¹���
		
		PrintWriter outStream = null;
		try {
			outStream = new PrintWriter(fileName2);
		}catch(IOException e) {
			System.out.println("Exception occurs.");
			System.exit(1);
		}//���Ͽ� ���� ���� ��Ʈ�� ����
	
		while(inputStream.hasNextLine()) {
			String line = inputStream.nextLine();//���پ� �о
			StringTokenizer token = new StringTokenizer(line,", \n");//��ūŬ������ �ִ´� �и��ڴ�, \n
			while(token.hasMoreTokens()) {
				String str = token.nextToken();//��ū �ϳ��� �о
				if(str.length()>4)
					outStream.println(str);//���̰� 4���� ū�͸� ���Ͽ� ���
			}
		}
		System.out.println(fileName2 +" is generated.");
		
		inputStream.close();
		outStream.close();
		
	}
}

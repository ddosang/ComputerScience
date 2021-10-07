import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Week11_1 {
	public static void main(String args[]) {
		
		Scanner kb = new Scanner(System.in);
		String fileName1, fileName2;
		System.out.println("File name for input:");
		fileName1 = kb.next();
		System.out.println("File name for output:");
		fileName2 = kb.next();
		kb.close();
		//file �̸� �Է¹���.
		
		try {
			ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(fileName1));
			ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(fileName2));
			System.out.println("The numbers in File, "+fileName1);
			try {
				while(true) {
					int anInteger = inputStream.readInt();
					System.out.println(anInteger);
					outputStream.writeInt(anInteger*2);
				}//ù ���Ͽ��� �о�� 2���ؼ� �ι�° ���Ͽ� ����
			}
			catch(EOFException e) {
				System.out.println("End of reading from File, "+fileName1);
				System.out.println(fileName2+" is generated.");
				System.out.println("");
			}//���� �д°� ���� ���.
			inputStream.close();
			outputStream.close();
		}catch(FileNotFoundException e) {
			System.out.println("Cannot find the file "+fileName1);
		}
		catch(IOException e) {
			System.out.println("Problem with input form file "+fileName1);
		}//ù��° try, catch ���
			
		try {
			ObjectInputStream inputStream2 = new ObjectInputStream(new FileInputStream(fileName2));
			System.out.println("The numbers in File, "+fileName2);
			try {
				while(true) {
					int anInteger2 = inputStream2.readInt();
					System.out.println(anInteger2);
				}
			}//�ι�° ���Ͽ��� �о��
			catch(EOFException e) {
				System.out.println("End of reading from 2nd File, "+fileName2);
			}
			inputStream2.close();
		}
		catch(FileNotFoundException e) {
			System.out.println("Cannot find the file "+fileName2);
		}
		catch(IOException e) {
			System.out.println("Problem with input form file "+fileName2);
		}//�ι�° try, catch ���
	}
}



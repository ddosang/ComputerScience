package fallinlovewithyou;

import java.util.Scanner;
class Time{
	private int hour;
	private int minute; 
	//private �ν��Ͻ� ���� hour�� minute ����
	
	private boolean isValid(int hour, int minute) {
		if(0<=hour && hour <= 23 && 0 <= minute && minute <= 59){
			return true;
		}//hour�� minute�� ���� �ȿ� ������ true�� ��ȯ
		else {
			System.out.println("Wrong Input");
			return false;}
		//���� �ۿ� ������ �߸��� �Է��̶�� �˷��ֱ�
	}//private method isValid return���� boolean��
	
	public void setTime(int hour,int minute) {
		if(isValid(hour, minute) == true) {
			this.hour = hour;
			this.minute = minute;
			//a.setTime(hour,minute)�϶� a�� hour, minute��
			//���ڷ� ���޹��� hour, minute �ִ´�.
		}
	}//int�� ���� 2���� �޴� setTime method : return�� ����

	public int getTime(char ch) {
		if (ch == 'H' || ch == 'h') {
			return hour;
		}
		else if(ch == 'M' || ch == 'm') {
			return minute;
		}
		else {
			return 0;
		}
	}//ch �� H,h�̸� hour M,m�̸� minute�� ��ȯ. �� �� �ƴϸ� 0 ��ȯ.
}
public class HW1_1 {
public static void main(String[] args) {
	
	Scanner kb = new Scanner(System.in);
	
	int hour, minute;//������ ���� hour, minute ����
	
	System.out.println("Hour:");
	hour = kb.nextInt();
	System.out.println("Minute:");
	minute = kb.nextInt();
	//hour�� minute �Է¹���
	
	Time t = new Time();
	//Time class �� ��ü t ����.
	
	t.setTime(hour, minute);
	//setTime method�� �̿��� �Է¹��� ������ t�� �ð��� �� ����.
	
	System.out.println(t.getTime('h')+":"+t.getTime('m'));
	//getTime method�� �̿��� t�� hour�� minute�� ���
}
}

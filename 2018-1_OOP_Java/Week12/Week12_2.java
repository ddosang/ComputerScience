package fallinlovewithyou;

import java.util.*;

public class Week12_2 {
	public static void main(String[] args) {
		
		Map<String, String> m = new HashMap<String,String>();
		Scanner kb = new Scanner(System.in);
		String ID, name, str, str1, maxID, minID;
		int maxLength, minLength;  //�ʿ��� ���� ����

		System.out.println("�л� ID�� �̸��� ���ʷ� �Է��ϼ���.(����� 0 0 �Է�)");
		while(true) {
			ID = kb.next();
			name = kb.next(); //ID, �̸� �Է¹޴´�.
			if(name.equals("0") && ID.equals("0")) { //�Ѵ� 0�̸� break (�ϱ����� max, min ���� ���� ����)
				System.out.println("<�л����>");
				System.out.println("[ID]\t\t[NAME]");
				
				Set s = m.keySet();
				Iterator<String> it = s.iterator();
				
				Iterator<String> it2 = s.iterator(); //iterator �ϳ� �� �����ؼ�
				str1 = it2.next();
				maxLength = m.get(str1).length();
				minLength = m.get(str1).length();
				maxID = str1;
				minID = str1;// max min �ʱ�ȭ 
	
				while(it.hasNext()) {
					str = it.next();
					System.out.println(str+"\t\t"+m.get(str)); //�л� ��� ���
					
					if(m.get(str).length() > maxLength){
						maxLength = m.get(str).length(); 
						maxID = str;
					} //max �� ���ϱ�
					if(m.get(str).length() < minLength){
						minLength = m.get(str).length(); 
						minID = str;
					} //min �� ���ϱ�
				}
				break;
			}
			m.put(ID, name);
		}		
		
		System.out.println("��ü �л���:"+m.size());
		System.out.println("<���� �� �̸��� ���� �л�>");
		System.out.println("ID:"+maxID+" Name:"+m.get(maxID)+" ����:"+maxLength);
		System.out.println("<���� ª�� �̸��� ���� �л�>");
		System.out.println("ID:"+minID+" Name:"+m.get(minID)+" ����:"+minLength);
		//��� ���
	}
}

 

